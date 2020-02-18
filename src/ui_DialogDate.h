/********************************************************************************
** Form generated from reading UI file 'DialogDate.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDATE_H
#define UI_DIALOGDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogDate
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDateEdit *dateEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogDate)
    {
        if (DialogDate->objectName().isEmpty())
            DialogDate->setObjectName(QString::fromUtf8("DialogDate"));
        DialogDate->resize(240, 100);
        DialogDate->setMinimumSize(QSize(240, 100));
        DialogDate->setMaximumSize(QSize(240, 100));
        verticalLayout = new QVBoxLayout(DialogDate);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(DialogDate);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        dateEdit = new QDateEdit(DialogDate);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(dateEdit);

        buttonBox = new QDialogButtonBox(DialogDate);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogDate);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogDate, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogDate, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogDate);
    } // setupUi

    void retranslateUi(QDialog *DialogDate)
    {
        DialogDate->setWindowTitle(QApplication::translate("DialogDate", "\350\256\276\347\275\256\345\255\246\346\234\237\350\265\267\345\247\213\346\227\245", nullptr));
        label->setText(QApplication::translate("DialogDate", "\345\255\246\346\234\237\350\265\267\345\247\213\346\227\245\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogDate: public Ui_DialogDate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDATE_H
