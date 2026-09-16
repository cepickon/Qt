#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mjeButtonVelky(false)
{
    ui->setupUi(this);
    //1. argument je objekt,na kterém chceme zachytit událost
    //2. argument je událost, kterou chceme zachytit na objektu z prvního argumentu
    //3. argument je objekt, ve kterém je definovaná metoda na zpracování dané události z argumentu 2.
    //4. argument je metoda, ktera se zavola po dane události
    connect(ui->pushButtonPrevod, &QPushButton::clicked, this, &MainWindow::tlacitko);
    connect(ui->doubleSpinBoxEUR, &QDoubleSpinBox::valueChanged, this, &MainWindow::prevod);
    connect(ui->doubleSpinBoxKurz, &QDoubleSpinBox::valueChanged, this, &MainWindow::prevod);
    connect(ui->doubleSpinBoxCZK, &QDoubleSpinBox::valueChanged, this, &MainWindow::prevodzpet);
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::prevod(){
    double vysledek = ui->doubleSpinBoxEUR->value() * ui->doubleSpinBoxKurz->value();
    ui->vysledek->setText(QString::number(vysledek));
    ui ->doubleSpinBoxCZK->setValue(vysledek);
}
void MainWindow::prevodzpet(){
    double vysledek3 = ui->doubleSpinBoxCZK->value() / ui->doubleSpinBoxKurz->value();
    ui ->doubleSpinBoxEUR->setValue(vysledek3);
}
void MainWindow::tlacitko(){
    if (mjeButtonVelky == false){
        ui->pushButtonPrevod->setMinimumHeight(200);
        ui->pushButtonPrevod->setMinimumWidth(200);
        mjeButtonVelky = true;
    }
    else{
        ui->pushButtonPrevod->setMinimumHeight(25);
        ui->pushButtonPrevod->setMinimumWidth(25);
        mjeButtonVelky = false;
    }
}