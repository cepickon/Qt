#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QApplication>
#include <QClipboard>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->radioButton_Sp, &QRadioButton::clicked, this, &MainWindow::strongPassword);
    connect(ui->radioButton_Wp, &QRadioButton::clicked, this, &MainWindow::weakPassword);
    connect(ui->pushButton_G, &QPushButton::clicked, this, &MainWindow::lineGenerate);
    connect(ui->pushButton_C, &QPushButton::clicked, this, &MainWindow::copy);
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::strongPassword(){
    ui->checkBox_Ll->setChecked(true);
    ui->checkBox_Sl->setChecked(true);
    ui->checkBox_N->setChecked(true);
    ui->checkBox_Sm->setChecked(true);
    ui->doubleSpinBox_Pl->setMinimum(9);
    ui->doubleSpinBox_Pl->setValue(9);
}
void MainWindow::weakPassword(){
    ui->doubleSpinBox_Pl->setMinimum(5);
    ui->doubleSpinBox_Pl->setValue(5);
}
void MainWindow::lineGenerate(){
    QString password = generate();
    ui->lineEdit_P->setText(password);
}
QString MainWindow::generate(){
    QString chars;
    if (ui->checkBox_Ll->isChecked()){
        chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    if (ui->checkBox_Sl->isChecked()){
        chars += "abcdefghijklmnopqrstuvwxyz";
    }
    if (ui->checkBox_N->isChecked()){
        chars += "0123456789";
    }
    if (ui->checkBox_Sm->isChecked()){
        chars += "!@#$%^&*()_+-=[]{}|;:,.<>?";
    }
    int length = static_cast<int>(ui->doubleSpinBox_Pl->value());
    if (chars.isEmpty() || length <= 0){
        return QString();
    }
    QString password;
    for (int i = 0; i < length; ++i){
        int index = QRandomGenerator::global()->bounded(chars.size());
        password += chars.at(index);
    }
    return password;
}
void MainWindow::copy(){
    QApplication::clipboard()->setText(ui->lineEdit_P->text());
}