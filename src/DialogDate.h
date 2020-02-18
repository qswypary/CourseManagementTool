#ifndef DIALOGDATE_H
#define DIALOGDATE_H

#include <QDialog>
#include <QDate>

namespace Ui {
class DialogDate;
}

class DialogDate : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDate(QWidget *parent = nullptr, QDate def_date = QDate());
    ~DialogDate();

signals:
    void to_save_date(QDate date);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogDate *ui;
};

#endif // DIALOGDATE_H
