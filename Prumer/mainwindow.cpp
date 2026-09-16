#include "mainwindow.h"
#include "ui_mainwindow.h"#
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonVysledek, &QPushButton::clicked, this, &MainWindow::prumer);
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::prumer(){
    QString input = ui->lineEditCisla->text();
    QStringList list = input.split(',');
    double sum = 0;
    for (int i = 0; i < list.size(); ++i){
        sum += list [i].toInt();
    }
    double vysledek = sum / list.size();
    ui->labelVysledek->setText(QString::number(vysledek));
}