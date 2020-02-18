#include <sstream>
#include <stdexcept>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DialogDate.h"

const QVector<QString> MainWindow::WEEKDAYS = {tr("周一"), tr("周二"), tr("周三"), tr("周四"),
                                               tr("周五"), tr("周六"), tr("周日")};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    update_time();
    _timerp = new QTimer();
    _timerp->start(_time_interval);
    connect(_timerp, SIGNAL(timeout()), this, SLOT(update_time()));

    _settings_p = std::unique_ptr<QSettings>(new QSettings(_settings_fn, QSettings::IniFormat));

    _begin_date = _settings_p->value("begin_date", QVariant(_begin_date)).toDate();
    _welcome = _settings_p->value("welcome", QVariant(_welcome)).toString();
    ui->labelHello->setText(_welcome);
}

MainWindow::~MainWindow()
{
    _settings_p->setValue("welcome", _welcome);
    _settings_p->setValue("begin_date", _begin_date);
    _settings_p->setValue("last_info_fn", _info_fn);
    _settings_p->setValue("last_timetable_fn", _timetable_fn);

    _timerp->stop();
    delete _timerp;

    delete ui;
}

void MainWindow::initialize_after_showing() {
    _info_fn = _settings_p->value("last_info_fn", QVariant()).toString();
    if (!_info_fn.isEmpty()) load_info_table();

    _timetable_fn = _settings_p->value("last_timetable_fn", QVariant()).toString();
    if (!_timetable_fn.isEmpty()) load_time_table();
}

void MainWindow::on_action_info_triggered()
{
    _info_fn = QFileDialog::getOpenFileName(this, tr("打开"), QString(),
                                            tr("Excel 文件(*.xls *.xlsx);;所有文件(*.*)"));
    if (_info_fn.isNull()) return;

    load_info_table();

    QMessageBox::information(this, tr("载入成功"), tr("课程信息文件载入成功！\n载入时间表文件以显示课表。"));
}

void MainWindow::on_action_time_triggered()
{
    _timetable_fn = QFileDialog::getOpenFileName(this, tr("打开"), QString(),
                                                 tr("Excel 文件(*.xls *.xlsx);;所有文件(*.*)"));
    if (_timetable_fn.isNull()) return;

    load_time_table();

    QMessageBox::information(this, tr("载入成功"), tr("时间表文件载入成功！"));
}

void MainWindow::update_time() {
    QDateTime curr = QDateTime::currentDateTime();
    _curr_weekday = curr.date().dayOfWeek();
    _curr_time = curr.time();

    _curr_week = int(_begin_date.daysTo(curr.date()) / WEEKDAYS.size()) + 1;

    int num = 0;
    for ( ; num != _course_time.size(); ++num) {
        if (_curr_time >= _course_time[num][0]
                && _curr_time < _course_time[num][1])
            break;
    }
    if (num == _course_time.size()) num = -1;
    _curr_course = {num, _curr_weekday - 1};
    set_current_course();

    if (_curr_week % 2 == 1) _curr_table = &_odd_week_table;
    else _curr_table = &_even_week_table;

    std::ostringstream oss;
    oss << "第" << _curr_week << "周，"
        << WEEKDAYS[_curr_weekday - 1].toStdString() << "，"
        << _curr_time.toString(QString("H:mm")).toStdString();

    ui->labelTime->setText(tr(oss.str().c_str()));
}

void MainWindow::on_tableWidgetTimetable_cellDoubleClicked(int row, int column)
{
    display_course_info((*_curr_table)[row][column]);
    _timerp->start(_time_interval);
}

void MainWindow::on_action_reload_triggered()
{
    if (!_info_fn.isEmpty()) load_info_table();
    if (!_timetable_fn.isEmpty()) load_time_table();
}

void MainWindow::on_action_date_triggered()
{
    DialogDate *dialogp = new DialogDate(this, _begin_date);

    connect(dialogp, SIGNAL(to_save_date(QDate)),
            this, SLOT(when_saving_date(QDate)));

    dialogp->show();
}

void MainWindow::when_saving_date(QDate date) {
    _begin_date = date;
    update_time();

    QMessageBox::information(this, tr("设置成功"), tr("学期开始日设置成功！"));
}

void MainWindow::on_action_welcome_triggered()
{
    QString temp = QInputDialog::getText(this, tr("设置欢迎语"), tr("欢迎语："), QLineEdit::Normal, _welcome);
    if (!temp.isNull()) {
        _welcome = temp;
        ui->labelHello->setText(_welcome);
        QMessageBox::information(this, tr("设置成功"), tr("欢迎语设置成功！"));
    }
}

void MainWindow::load_table(const QString &filename, std::unique_ptr<QXlsx::Document> &ptr) {
    if (!QFile::exists(filename)) {
        std::ostringstream oss;
        oss << "找不到文件 " << filename.toStdString()
            << "。该文件是否已被移动、重命名或删除？";
        QMessageBox::warning(this, tr("载入失败"), tr(oss.str().c_str()));
        throw std::invalid_argument("bad filename");
    }
    ptr = std::unique_ptr<QXlsx::Document>(new QXlsx::Document(filename));
}

void MainWindow::load_info_table() {
    try {
        load_table(_info_fn, _info_fp);
    }
    catch (std::invalid_argument) {
        _info_fn = QString();
        _timetable_fn = QString();
        _timetable_fp = std::unique_ptr<QXlsx::Document>();
        ui->action_time->setEnabled(false);
        ui->action_reload->setEnabled(false);
        return;
    }

    QXlsx::CellRange range = _info_fp->dimension();
    int firstR = range.firstRow(), lastR = range.lastRow() + 1;
    int firstC = range.firstColumn(), lastC = range.lastColumn() + 1;
    int index_col = 0, name_col = 1;
    QVector<bool> url_check;
    _info_map = QMap<int, CourseInfo>();
    _info_header = QVector<QString>();

    for (int row = firstR; row != lastR; ++row) {
        if (row == firstR) {
            for (int col = firstC; col != lastC; ++col) {
                _info_header.append(_info_fp->read(row, col).toString());
            }
        }
        else if (row == firstR + 1) {
            for (int col = firstC; col != lastC; ++col) {
                QString temp = _info_fp->read(row, col).toString();

                if (temp == QString("name")) { name_col = col; }
                else if (temp == QString("index")) { index_col = col; }

                url_check.append(temp == QString("url"));
            }
        }
        else {
            int index = _info_fp->read(row, index_col).toInt();
            QString name = _info_fp->read(row, name_col).toString();
            QVector<QString> content;
            for (int col = firstC; col != lastC; ++col) {
                content.append(_info_fp->read(row, col).toString());
            }
            _info_map.insert(index, CourseInfo(name, content));
            for (int i = 0; i != url_check.size(); ++i) {
                _info_map.find(index).value().set_url(i, url_check[i]);
            }
        }
    }

    ui->action_time->setEnabled(true);
    ui->action_reload->setEnabled(true);
}

void MainWindow::load_time_table() {
    if (!ui->action_time->isEnabled()) return;

    try {
        load_table(_timetable_fn, _timetable_fp);
    }
    catch (std::invalid_argument) {
        return;
    }

    QXlsx::CellRange range = _timetable_fp->dimension();
    int firstR = range.firstRow(), lastR = range.lastRow() + 1;
    int firstC = range.firstColumn();
    int week_cnt = WEEKDAYS.size();
    int row_num = lastR - firstR;
    _course_time = QVector<QVector<QTime>>();
    _odd_week_table = _even_week_table = QVector<QVector<int>>();

    for (int row = firstR; row != lastR; ++row) {
        _course_time.append(QVector<QTime>{_timetable_fp->read(row, firstC).toTime(),
                                           _timetable_fp->read(row, firstC+1).toTime()});
        int begC = firstC + 2;
        QVector<int> odd_vec, even_vec;
        for (int index = 0; index != week_cnt; ++index) {
            int col = begC + index*2;
            odd_vec.append(_timetable_fp->read(row, col).toInt());
            even_vec.append(_timetable_fp->read(row, col+1).toInt());
        }
        _odd_week_table.append(odd_vec);
        _even_week_table.append(even_vec);
    }

    ui->tableWidgetTimetable->setColumnCount(week_cnt);
    ui->tableWidgetTimetable->setRowCount(row_num);
    QStringList labels;
    for (auto item : WEEKDAYS) {
        labels.append(item);
    }
    ui->tableWidgetTimetable->setHorizontalHeaderLabels(labels);
    ui->tableWidgetTimetable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    for (int i = 0; i != row_num; ++i) {
        for (int j = 0; j != week_cnt; ++j) {
            int num = (*_curr_table)[i][j];
            QString name;
            if (num != 0) name = _info_map.find(num)->get_name();
            ui->tableWidgetTimetable->setItem(i, j, new QTableWidgetItem(name));
        }
    }

    int width = ui->tableWidgetTimetable->width() / week_cnt;
    int height = (ui->tableWidgetTimetable->height() - ui->tableWidgetTimetable->horizontalHeader()->height() - 10) / row_num;

    for (int index = 0; index != week_cnt; ++index) {
        ui->tableWidgetTimetable->setColumnWidth(index, width);
    }
    for (int index = 0; index != row_num; ++index) {
        ui->tableWidgetTimetable->setRowHeight(index, height);
    }

    update_time();
}

void MainWindow::set_current_course() {
    highlight_course(_curr_course.x(), _curr_course.y());
    if (_curr_course.x() >= 0) {
        display_course_info((*_curr_table)[_curr_course.x()][_curr_course.y()]);
    }
}

void MainWindow::highlight_course(int x, int y) {
    QColor default_color = {255, 255, 255};
    for (int row = 0; row != ui->tableWidgetTimetable->rowCount(); ++row) {
        for (int col = 0; col != ui->tableWidgetTimetable->columnCount(); ++col) {
            ui->tableWidgetTimetable->item(row, col)->setBackground(QBrush(default_color));
        }
    }
    if (x < 0) return;
    ui->tableWidgetTimetable->item(x, y)->setBackground(QBrush(_highlight));
}

void MainWindow::display_course_info(int num) {
    while (!_url_labelp.isEmpty()) {
        ui->verticalLayout_4->removeWidget(_url_labelp.back());
        _url_labelp.back()->deleteLater();
        _url_labelp.pop_back();
    }

    if (num == 0) {
        ui->tableWidgetInfo->setVerticalHeaderLabels(QStringList());
        ui->tableWidgetInfo->setRowCount(0);
        ui->tableWidgetInfo->setColumnCount(0);
        return;
    }

    int row_count = 0;
    QStringList labels;
    QVector<QString> content;
    for (int i = 0; i != _info_header.size(); ++i) {
        CourseInfo &course = _info_map.find(num).value();
        if (!_info_header[i].isEmpty()
                && !course[i].isEmpty())
        {
            ++row_count;
            labels.append(_info_header[i]);
            content.append(course[i]);
            if (course.is_url(i)) {
                QLabel *labelp = new QLabel(ui->verticalFrame);
                _url_labelp.append(labelp);
                std::ostringstream oss;
                oss << "<a href=\"" << course[i].toStdString()
                    << "\">相关网址" << _url_labelp.size() << "</a>";
                labelp->setText(tr(oss.str().c_str()));
                labelp->setFont(QFont("微软雅黑", 12));
                labelp->setOpenExternalLinks(true);
                ui->verticalLayout_4->addWidget(labelp);
            }
        }
    }

    ui->tableWidgetInfo->setRowCount(row_count);
    ui->tableWidgetInfo->setColumnCount(1);

    int width = ui->tableWidgetInfo->width() - ui->tableWidgetInfo->verticalHeader()->width();
    ui->tableWidgetInfo->setColumnWidth(0, width);

    ui->tableWidgetInfo->setVerticalHeaderLabels(labels);
    for (int row = 0; row != content.size(); ++row) {
        ui->tableWidgetInfo->setItem(row, 0, new QTableWidgetItem(content[row]));
    }
    ui->tableWidgetInfo->resizeRowsToContents();
}
