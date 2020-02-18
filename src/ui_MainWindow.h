/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_info;
    QAction *action_time;
    QAction *action_reload;
    QAction *action_date;
    QAction *action_welcome;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidgetTimetable;
    QFrame *verticalFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelHello;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelTimeHint;
    QLabel *labelTime;
    QLabel *labelInfoHint;
    QTableWidget *tableWidgetInfo;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_load;
    QMenu *menu_setting;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(960, 720);
        MainWindow->setMinimumSize(QSize(960, 720));
        MainWindow->setMaximumSize(QSize(960, 720));
        action_info = new QAction(MainWindow);
        action_info->setObjectName(QString::fromUtf8("action_info"));
        action_time = new QAction(MainWindow);
        action_time->setObjectName(QString::fromUtf8("action_time"));
        action_time->setEnabled(false);
        action_reload = new QAction(MainWindow);
        action_reload->setObjectName(QString::fromUtf8("action_reload"));
        action_reload->setEnabled(false);
        action_date = new QAction(MainWindow);
        action_date->setObjectName(QString::fromUtf8("action_date"));
        action_welcome = new QAction(MainWindow);
        action_welcome->setObjectName(QString::fromUtf8("action_welcome"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 3);
        tableWidgetTimetable = new QTableWidget(centralWidget);
        tableWidgetTimetable->setObjectName(QString::fromUtf8("tableWidgetTimetable"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidgetTimetable->sizePolicy().hasHeightForWidth());
        tableWidgetTimetable->setSizePolicy(sizePolicy);
        tableWidgetTimetable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetTimetable->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidgetTimetable->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(tableWidgetTimetable);

        verticalFrame = new QFrame(centralWidget);
        verticalFrame->setObjectName(QString::fromUtf8("verticalFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalFrame->sizePolicy().hasHeightForWidth());
        verticalFrame->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(verticalFrame);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        labelHello = new QLabel(verticalFrame);
        labelHello->setObjectName(QString::fromUtf8("labelHello"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelHello->sizePolicy().hasHeightForWidth());
        labelHello->setSizePolicy(sizePolicy2);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        labelHello->setFont(font);
        labelHello->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_4->addWidget(labelHello);

        horizontalFrame = new QFrame(verticalFrame);
        horizontalFrame->setObjectName(QString::fromUtf8("horizontalFrame"));
        sizePolicy2.setHeightForWidth(horizontalFrame->sizePolicy().hasHeightForWidth());
        horizontalFrame->setSizePolicy(sizePolicy2);
        horizontalLayout_3 = new QHBoxLayout(horizontalFrame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelTimeHint = new QLabel(horizontalFrame);
        labelTimeHint->setObjectName(QString::fromUtf8("labelTimeHint"));
        sizePolicy2.setHeightForWidth(labelTimeHint->sizePolicy().hasHeightForWidth());
        labelTimeHint->setSizePolicy(sizePolicy2);
        labelTimeHint->setFont(font);
        labelTimeHint->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_3->addWidget(labelTimeHint);

        labelTime = new QLabel(horizontalFrame);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelTime->sizePolicy().hasHeightForWidth());
        labelTime->setSizePolicy(sizePolicy3);
        labelTime->setFont(font);
        labelTime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_3->addWidget(labelTime);


        verticalLayout_4->addWidget(horizontalFrame);

        labelInfoHint = new QLabel(verticalFrame);
        labelInfoHint->setObjectName(QString::fromUtf8("labelInfoHint"));
        sizePolicy2.setHeightForWidth(labelInfoHint->sizePolicy().hasHeightForWidth());
        labelInfoHint->setSizePolicy(sizePolicy2);
        labelInfoHint->setFont(font);
        labelInfoHint->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_4->addWidget(labelInfoHint);

        tableWidgetInfo = new QTableWidget(verticalFrame);
        tableWidgetInfo->setObjectName(QString::fromUtf8("tableWidgetInfo"));
        tableWidgetInfo->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidgetInfo->horizontalHeader()->setVisible(false);

        verticalLayout_4->addWidget(tableWidgetInfo);


        horizontalLayout->addWidget(verticalFrame);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 960, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_load = new QMenu(menu);
        menu_load->setObjectName(QString::fromUtf8("menu_load"));
        menu_setting = new QMenu(menuBar);
        menu_setting->setObjectName(QString::fromUtf8("menu_setting"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_setting->menuAction());
        menu->addAction(menu_load->menuAction());
        menu->addAction(action_reload);
        menu_load->addAction(action_info);
        menu_load->addAction(action_time);
        menu_setting->addAction(action_date);
        menu_setting->addAction(action_welcome);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\257\276\347\250\213\347\256\241\347\220\206\345\267\245\345\205\267", nullptr));
        action_info->setText(QApplication::translate("MainWindow", "\350\275\275\345\205\245\350\257\276\347\250\213\344\277\241\346\201\257(&I)...", nullptr));
        action_time->setText(QApplication::translate("MainWindow", "\350\275\275\345\205\245\346\227\266\351\227\264\350\241\250(&T)...", nullptr));
        action_reload->setText(QApplication::translate("MainWindow", "\351\207\215\346\226\260\350\275\275\345\205\245\346\211\200\346\234\211\346\226\207\344\273\266(&R)", nullptr));
#ifndef QT_NO_SHORTCUT
        action_reload->setShortcut(QApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        action_date->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\255\246\346\234\237\350\265\267\345\247\213\346\227\245(&D)...", nullptr));
        action_welcome->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\254\242\350\277\216\350\257\255(&W)...", nullptr));
        labelHello->setText(QApplication::translate("MainWindow", "\346\254\242\350\277\216\357\274\214\346\270\205\346\260\264\346\227\240\351\237\263pary", nullptr));
        labelTimeHint->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
        labelTime->setText(QApplication::translate("MainWindow", "\347\254\254X\345\221\250\357\274\214\345\221\250\343\200\207\357\274\214HH:MM", nullptr));
        labelInfoHint->setText(QApplication::translate("MainWindow", "\350\257\276\347\250\213\344\277\241\346\201\257\357\274\232", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_load->setTitle(QApplication::translate("MainWindow", "\350\275\275\345\205\245\346\226\207\344\273\266(&L)", nullptr));
        menu_setting->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256(&S)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
