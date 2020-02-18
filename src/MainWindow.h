#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <map>
#include <vector>
#include <QSettings>
#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include "xlsxdocument.h"
#include "CourseInfo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initialize_after_showing();

private slots:
    void on_action_info_triggered();

    void on_action_time_triggered();

    void update_time();

    void on_tableWidgetTimetable_cellDoubleClicked(int row, int column);

    void on_action_reload_triggered();

    void on_action_date_triggered();

    void when_saving_date(QDate date);

    void on_action_welcome_triggered();

private:
    Ui::MainWindow *ui;

    const static QVector<QString> WEEKDAYS;

    QDate _begin_date = {2020, 2, 17};
    QTimer *_timerp;
    const int _time_interval = 1000 * 20;
    int _curr_week;
    int _curr_weekday;
    QTime _curr_time;
    QPoint _curr_course;

    QColor _highlight = {191, 191, 191};
    QString _welcome = tr("欢迎，用户");

    QString _info_fn;
    QString _timetable_fn;
    QString _settings_fn = "settings.ini";
    std::unique_ptr<QXlsx::Document> _info_fp = nullptr;
    std::unique_ptr<QXlsx::Document> _timetable_fp = nullptr;
    std::unique_ptr<QSettings> _settings_p;

    QMap<int, CourseInfo> _info_map;
    QVector<QString> _info_header;

    QVector<QVector<QTime>> _course_time;
    QVector<QVector<int>> _odd_week_table, _even_week_table;
    QVector<QVector<int>> *_curr_table;

    QVector<QLabel *> _url_labelp;

    void load_table(const QString &filename, std::unique_ptr<QXlsx::Document> &ptr);
    void load_info_table();
    void load_time_table();

    void set_current_course();
    void display_course_info(int num);
};

#endif // MAINWINDOW_H
