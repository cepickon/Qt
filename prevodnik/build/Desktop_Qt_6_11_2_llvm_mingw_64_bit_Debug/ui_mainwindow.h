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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *labelKurz;
    QDoubleSpinBox *doubleSpinBoxKurz;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBoxEUR;
    QDoubleSpinBox *doubleSpinBoxCZK;
    QLabel *labelCZK;
    QLabel *labelEUR;
    QPushButton *pushButtonPrevod;
    QLabel *vysledek;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setWindowOpacity(999999999.000000000000000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        labelKurz = new QLabel(centralwidget);
        labelKurz->setObjectName("labelKurz");
        labelKurz->setToolTipDuration(1);
        labelKurz->setLineWidth(15);

        gridLayout_2->addWidget(labelKurz, 0, 0, 1, 1);

        doubleSpinBoxKurz = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxKurz->setObjectName("doubleSpinBoxKurz");
        doubleSpinBoxKurz->setMaximum(999999.000000000000000);

        gridLayout_2->addWidget(doubleSpinBoxKurz, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        doubleSpinBoxEUR = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxEUR->setObjectName("doubleSpinBoxEUR");
        doubleSpinBoxEUR->setMinimumSize(QSize(124, 0));
        doubleSpinBoxEUR->setMaximum(999999999.000000000000000);

        gridLayout->addWidget(doubleSpinBoxEUR, 1, 0, 1, 1);

        doubleSpinBoxCZK = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxCZK->setObjectName("doubleSpinBoxCZK");
        doubleSpinBoxCZK->setMaximum(999999999.000000000000000);

        gridLayout->addWidget(doubleSpinBoxCZK, 1, 2, 1, 1);

        labelCZK = new QLabel(centralwidget);
        labelCZK->setObjectName("labelCZK");

        gridLayout->addWidget(labelCZK, 0, 2, 1, 1);

        labelEUR = new QLabel(centralwidget);
        labelEUR->setObjectName("labelEUR");

        gridLayout->addWidget(labelEUR, 0, 0, 1, 1);

        pushButtonPrevod = new QPushButton(centralwidget);
        pushButtonPrevod->setObjectName("pushButtonPrevod");

        gridLayout->addWidget(pushButtonPrevod, 1, 1, 1, 1);

        vysledek = new QLabel(centralwidget);
        vysledek->setObjectName("vysledek");

        gridLayout->addWidget(vysledek, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 2, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);

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
        labelKurz->setText(QCoreApplication::translate("MainWindow", "Kurz", nullptr));
        labelCZK->setText(QCoreApplication::translate("MainWindow", "CZK", nullptr));
        labelEUR->setText(QCoreApplication::translate("MainWindow", "EUR", nullptr));
        pushButtonPrevod->setText(QCoreApplication::translate("MainWindow", "Tla\304\215\303\255tko", nullptr));
        vysledek->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
