#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonPrevod, &QPushButton::clicked, this, &MainWindow::retezec);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::retezec(){
    ui->doubleSpinBoxCislo->value();
    ui->labelNazev->text();
    ui->labelVysledek->setText( ui->labelNazev->text()+ QString(" ") + QString::number(ui->doubleSpinBoxCislo->value()));
}