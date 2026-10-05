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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineDisplay;
    QPushButton *pushButton7;
    QPushButton *pushButton8;
    QPushButton *pushButton9;
    QPushButton *pushButtonMultiply;
    QPushButton *pushButtonMinus;
    QPushButton *pushButton5;
    QPushButton *pushButton6;
    QPushButton *pushButton4;
    QPushButton *pushButtonPlus;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QPushButton *pushButton1;
    QPushButton *pushButtonEqual;
    QPushButton *pushButton0;
    QPushButton *pushButtonDevide;
    QPushButton *pushButtonComma;
    QPushButton *pushButtonC;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(317, 207);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineDisplay = new QLineEdit(centralwidget);
        lineDisplay->setObjectName("lineDisplay");
        lineDisplay->setGeometry(QRect(0, 0, 311, 31));
        pushButton7 = new QPushButton(centralwidget);
        pushButton7->setObjectName("pushButton7");
        pushButton7->setGeometry(QRect(0, 40, 75, 24));
        pushButton8 = new QPushButton(centralwidget);
        pushButton8->setObjectName("pushButton8");
        pushButton8->setGeometry(QRect(80, 40, 75, 24));
        pushButton9 = new QPushButton(centralwidget);
        pushButton9->setObjectName("pushButton9");
        pushButton9->setGeometry(QRect(160, 40, 75, 24));
        pushButtonMultiply = new QPushButton(centralwidget);
        pushButtonMultiply->setObjectName("pushButtonMultiply");
        pushButtonMultiply->setGeometry(QRect(240, 40, 75, 24));
        pushButtonMinus = new QPushButton(centralwidget);
        pushButtonMinus->setObjectName("pushButtonMinus");
        pushButtonMinus->setGeometry(QRect(240, 70, 75, 24));
        pushButton5 = new QPushButton(centralwidget);
        pushButton5->setObjectName("pushButton5");
        pushButton5->setGeometry(QRect(80, 70, 75, 24));
        pushButton6 = new QPushButton(centralwidget);
        pushButton6->setObjectName("pushButton6");
        pushButton6->setGeometry(QRect(0, 70, 75, 24));
        pushButton4 = new QPushButton(centralwidget);
        pushButton4->setObjectName("pushButton4");
        pushButton4->setGeometry(QRect(160, 70, 75, 24));
        pushButtonPlus = new QPushButton(centralwidget);
        pushButtonPlus->setObjectName("pushButtonPlus");
        pushButtonPlus->setGeometry(QRect(240, 100, 75, 24));
        pushButton2 = new QPushButton(centralwidget);
        pushButton2->setObjectName("pushButton2");
        pushButton2->setGeometry(QRect(80, 100, 75, 24));
        pushButton3 = new QPushButton(centralwidget);
        pushButton3->setObjectName("pushButton3");
        pushButton3->setGeometry(QRect(0, 100, 75, 24));
        pushButton1 = new QPushButton(centralwidget);
        pushButton1->setObjectName("pushButton1");
        pushButton1->setGeometry(QRect(160, 100, 75, 24));
        pushButtonEqual = new QPushButton(centralwidget);
        pushButtonEqual->setObjectName("pushButtonEqual");
        pushButtonEqual->setGeometry(QRect(240, 130, 75, 24));
        pushButton0 = new QPushButton(centralwidget);
        pushButton0->setObjectName("pushButton0");
        pushButton0->setGeometry(QRect(80, 130, 75, 24));
        pushButtonDevide = new QPushButton(centralwidget);
        pushButtonDevide->setObjectName("pushButtonDevide");
        pushButtonDevide->setGeometry(QRect(0, 130, 75, 24));
        pushButtonComma = new QPushButton(centralwidget);
        pushButtonComma->setObjectName("pushButtonComma");
        pushButtonComma->setGeometry(QRect(160, 130, 75, 24));
        pushButtonC = new QPushButton(centralwidget);
        pushButtonC->setObjectName("pushButtonC");
        pushButtonC->setGeometry(QRect(0, 160, 75, 24));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButtonMultiply->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButtonMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButtonPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButtonEqual->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButtonDevide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButtonComma->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButtonC->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
