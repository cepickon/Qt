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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelNazev;
    QLabel *labelPlus;
    QDoubleSpinBox *doubleSpinBoxCislo;
    QPushButton *pushButtonPrevod;
    QLabel *labelVysledek;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(80, 60, 581, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelNazev = new QLabel(widget);
        labelNazev->setObjectName("labelNazev");

        horizontalLayout->addWidget(labelNazev);

        labelPlus = new QLabel(widget);
        labelPlus->setObjectName("labelPlus");

        horizontalLayout->addWidget(labelPlus);

        doubleSpinBoxCislo = new QDoubleSpinBox(widget);
        doubleSpinBoxCislo->setObjectName("doubleSpinBoxCislo");

        horizontalLayout->addWidget(doubleSpinBoxCislo);

        pushButtonPrevod = new QPushButton(widget);
        pushButtonPrevod->setObjectName("pushButtonPrevod");

        horizontalLayout->addWidget(pushButtonPrevod);

        labelVysledek = new QLabel(widget);
        labelVysledek->setObjectName("labelVysledek");

        horizontalLayout->addWidget(labelVysledek);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        labelNazev->setText(QCoreApplication::translate("MainWindow", "\304\214\303\255slo", nullptr));
        labelPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButtonPrevod->setText(QCoreApplication::translate("MainWindow", "P\305\231evod", nullptr));
        labelVysledek->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
