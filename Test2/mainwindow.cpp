#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
//B

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->radioButton, &QRadioButton::toggled, this, &MainWindow::spojeni1);
    connect(ui->radioButton_2, &QRadioButton::toggled, this, &MainWindow::spojeni1);
    connect(ui->spinBox, &QSpinBox::valueChanged, this, &MainWindow::spojeni1);
    connect(ui->checkBox, &QCheckBox::clicked, this, &MainWindow::spojeni2);
    connect(ui->checkBox_2, &QCheckBox::clicked, this, &MainWindow::spojeni2);
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::spojeni1(){
    QString char1;
    if(ui->radioButton->isChecked()){
        char1 = ui->radioButton->text();
        char1 += " ";
    }
    if(ui->radioButton_2->isChecked()){
        char1 = ui->radioButton_2->text();
        char1 += " ";
    }
    if(ui->spinBox->hasAcceptableInput()){
        char1 += QString::number(ui->spinBox->value());
    }
    ui->label->setText(char1);
}
void MainWindow::spojeni2(){
    QString char2;
    if(ui->checkBox->isChecked()){
        char2 = ui->checkBox->text();
        char2 += " ";
    }
    if(ui->checkBox_2->isChecked()){
        char2 += ui->checkBox_2->text();
        char2 += " ";
    }
    ui->lineEdit->setText(char2);
}