/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *labelCMV;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *labelCM;
    QLabel *labelZap;
    QDoubleSpinBox *doubleSpinBoxHM;
    QLabel *labelSO;
    QDoubleSpinBox *doubleSpinBoxCM;
    QLabel *labelHM;
    QDoubleSpinBox *doubleSpinBoxZap;
    QLabel *labelZO;
    QDoubleSpinBox *doubleSpinBoxSO;
    QDoubleSpinBox *doubleSpinBoxZO;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(560, 629);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 10, 291, 221));
        labelCMV = new QLabel(groupBox);
        labelCMV->setObjectName("labelCMV");
        labelCMV->setGeometry(QRect(230, 200, 49, 16));
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 30, 271, 171));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelCM = new QLabel(widget);
        labelCM->setObjectName("labelCM");

        gridLayout->addWidget(labelCM, 4, 0, 1, 1);

        labelZap = new QLabel(widget);
        labelZap->setObjectName("labelZap");

        gridLayout->addWidget(labelZap, 1, 0, 1, 1);

        doubleSpinBoxHM = new QDoubleSpinBox(widget);
        doubleSpinBoxHM->setObjectName("doubleSpinBoxHM");
        doubleSpinBoxHM->setMaximum(999999.000000000000000);

        gridLayout->addWidget(doubleSpinBoxHM, 0, 1, 1, 1);

        labelSO = new QLabel(widget);
        labelSO->setObjectName("labelSO");

        gridLayout->addWidget(labelSO, 2, 0, 1, 1);

        doubleSpinBoxCM = new QDoubleSpinBox(widget);
        doubleSpinBoxCM->setObjectName("doubleSpinBoxCM");
        doubleSpinBoxCM->setMaximum(999999.000000000000000);

        gridLayout->addWidget(doubleSpinBoxCM, 4, 1, 1, 1);

        labelHM = new QLabel(widget);
        labelHM->setObjectName("labelHM");

        gridLayout->addWidget(labelHM, 0, 0, 1, 1);

        doubleSpinBoxZap = new QDoubleSpinBox(widget);
        doubleSpinBoxZap->setObjectName("doubleSpinBoxZap");
        doubleSpinBoxZap->setMaximum(999999.000000000000000);

        gridLayout->addWidget(doubleSpinBoxZap, 1, 1, 1, 1);

        labelZO = new QLabel(widget);
        labelZO->setObjectName("labelZO");

        gridLayout->addWidget(labelZO, 3, 0, 1, 1);

        doubleSpinBoxSO = new QDoubleSpinBox(widget);
        doubleSpinBoxSO->setObjectName("doubleSpinBoxSO");

        gridLayout->addWidget(doubleSpinBoxSO, 2, 1, 1, 1);

        doubleSpinBoxZO = new QDoubleSpinBox(widget);
        doubleSpinBoxZO->setObjectName("doubleSpinBoxZO");

        gridLayout->addWidget(doubleSpinBoxZO, 3, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 560, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBoxPrevod", nullptr));
        labelCMV->setText(QString());
        labelCM->setText(QCoreApplication::translate("MainWindow", "\304\214ist\303\241 mzda", nullptr));
        labelZap->setText(QCoreApplication::translate("MainWindow", "Zaplat\303\255 na dani", nullptr));
        labelSO->setText(QCoreApplication::translate("MainWindow", "Soci\303\241ln\303\255 odvody", nullptr));
        labelHM->setText(QCoreApplication::translate("MainWindow", "Hrub\303\241 mzda", nullptr));
        labelZO->setText(QCoreApplication::translate("MainWindow", "Zdravotn\303\255 odvody", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
