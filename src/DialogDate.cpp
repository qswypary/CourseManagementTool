#include "DialogDate.h"
#include "ui_DialogDate.h"

DialogDate::DialogDate(QWidget *parent, QDate def_date) :
    QDialog(parent),
    ui(new Ui::DialogDate)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(def_date);
}

DialogDate::~DialogDate()
{
    delete ui;
}

void DialogDate::on_buttonBox_accepted()
{
    emit to_save_date(ui->dateEdit->date());
}
