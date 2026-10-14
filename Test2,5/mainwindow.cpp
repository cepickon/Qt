#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->radioButton, &QRadioButton::toggled, this, &MainWindow::spojeni);
    connect(ui->radioButton_2, &QRadioButton::toggled, this, &MainWindow::spojeni);
    connect(ui->checkBox, &QCheckBox::clicked, this, &MainWindow::spojeni);
    connect(ui->checkBox_2, &QCheckBox::clicked, this, &MainWindow::spojeni);
    connect(ui->spinBox, &QSpinBox::valueChanged, this, &MainWindow::spojeni);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::spojeni);
}

MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::spojeni(){
    QString char1 = "";
    if(ui->radioButton->isChecked()){
        char1 += ui->radioButton->text();
        char1 += " ";
    }
    if(ui->radioButton_2->isChecked()){
        char1 += ui->radioButton_2->text();
        char1 += " ";
    }
    if(ui->checkBox->isChecked()){
        char1 += ui->checkBox->text();
        char1 += " ";
    }
    if(ui->checkBox_2->isChecked()){
        char1 += ui->checkBox_2->text();
        char1 += " ";
    }
    if(ui->spinBox->hasAcceptableInput()){
        char1 += ui->spinBox->text();
        char1 += " ";
    }
    ui->label->setText(char1 + ui->lineEdit->displayText());
}