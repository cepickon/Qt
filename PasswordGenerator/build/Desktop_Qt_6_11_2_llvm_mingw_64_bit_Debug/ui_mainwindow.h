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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_Sp;
    QRadioButton *radioButton_Wp;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_Ll;
    QCheckBox *checkBox_Sl;
    QCheckBox *checkBox_N;
    QCheckBox *checkBox_Sm;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Pl;
    QDoubleSpinBox *doubleSpinBox_Pl;
    QPushButton *pushButton_G;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_P;
    QPushButton *pushButton_C;
    QMenuBar *menubar;
    QMenu *menuPassword_generator;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(269, 319);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 226, 250));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        radioButton_Sp = new QRadioButton(widget);
        radioButton_Sp->setObjectName("radioButton_Sp");

        horizontalLayout->addWidget(radioButton_Sp);

        radioButton_Wp = new QRadioButton(widget);
        radioButton_Wp->setObjectName("radioButton_Wp");

        horizontalLayout->addWidget(radioButton_Wp);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        checkBox_Ll = new QCheckBox(widget);
        checkBox_Ll->setObjectName("checkBox_Ll");

        verticalLayout->addWidget(checkBox_Ll);

        checkBox_Sl = new QCheckBox(widget);
        checkBox_Sl->setObjectName("checkBox_Sl");

        verticalLayout->addWidget(checkBox_Sl);

        checkBox_N = new QCheckBox(widget);
        checkBox_N->setObjectName("checkBox_N");

        verticalLayout->addWidget(checkBox_N);

        checkBox_Sm = new QCheckBox(widget);
        checkBox_Sm->setObjectName("checkBox_Sm");

        verticalLayout->addWidget(checkBox_Sm);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_Pl = new QLabel(widget);
        label_Pl->setObjectName("label_Pl");

        horizontalLayout_2->addWidget(label_Pl);

        doubleSpinBox_Pl = new QDoubleSpinBox(widget);
        doubleSpinBox_Pl->setObjectName("doubleSpinBox_Pl");

        horizontalLayout_2->addWidget(doubleSpinBox_Pl);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton_G = new QPushButton(widget);
        pushButton_G->setObjectName("pushButton_G");

        verticalLayout_2->addWidget(pushButton_G);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        lineEdit_P = new QLineEdit(widget);
        lineEdit_P->setObjectName("lineEdit_P");

        horizontalLayout_3->addWidget(lineEdit_P);


        verticalLayout_2->addLayout(horizontalLayout_3);

        pushButton_C = new QPushButton(widget);
        pushButton_C->setObjectName("pushButton_C");

        verticalLayout_2->addWidget(pushButton_C);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 269, 22));
        menuPassword_generator = new QMenu(menubar);
        menuPassword_generator->setObjectName("menuPassword_generator");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPassword_generator->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        radioButton_Sp->setText(QCoreApplication::translate("MainWindow", "Strong password", nullptr));
        radioButton_Wp->setText(QCoreApplication::translate("MainWindow", "Weak password", nullptr));
        checkBox_Ll->setText(QCoreApplication::translate("MainWindow", "Large letters", nullptr));
        checkBox_Sl->setText(QCoreApplication::translate("MainWindow", "Small letters", nullptr));
        checkBox_N->setText(QCoreApplication::translate("MainWindow", "Numbers", nullptr));
        checkBox_Sm->setText(QCoreApplication::translate("MainWindow", "Special marks", nullptr));
        label_Pl->setText(QCoreApplication::translate("MainWindow", "Password lenght", nullptr));
        pushButton_G->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        pushButton_C->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        menuPassword_generator->setTitle(QCoreApplication::translate("MainWindow", "Password generator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
