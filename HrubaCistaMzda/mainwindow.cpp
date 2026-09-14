#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //1. argument je objekt,na kterém chceme zachytit událost
    //2. argument je událost, kterou chceme zachytit na objektu z prvního argumentu
    //3. argument je objekt, ve kterém je definovaná metoda na zpracování dané události z argumentu 2.
    //4. argument je metoda, ktera se zavola po dane události
    connect(ui->doubleSpinBoxHM, &QDoubleSpinBox::editingFinished, this, &MainWindow::prevod);
    connect(ui->doubleSpinBoxCM, &QDoubleSpinBox::editingFinished, this, &MainWindow::prevodzpet);
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::prevod(){
    ui->labelCMV->setText(QString::number(ui ->doubleSpinBoxHM->value() * 0.8));
    double srazky = 4;
    double zaplati = ui->doubleSpinBoxHM->value() / srazky;
    ui ->doubleSpinBoxZap->setValue(zaplati);
    double soc = 0.045;
    double zaplatisoc = ui->doubleSpinBoxHM->value() * soc;
    ui ->doubleSpinBoxSO->setValue(zaplatisoc);
    double zdra = 0.065;
    double zaplatizdra = ui->doubleSpinBoxHM->value() * zdra;
    ui ->doubleSpinBoxZO->setValue(zaplatizdra);
    double vysledek = ui->doubleSpinBoxHM->value() - (zaplati + zaplatizdra + zaplatisoc);
    ui ->doubleSpinBoxCM->setValue(vysledek);
}
void MainWindow::prevodzpet(){
    double hrubaMzda = ui->doubleSpinBoxCM->value() / 0.64;
    ui->doubleSpinBoxHM->setValue(hrubaMzda);
    double srazky = 4;
    double zaplati = hrubaMzda / srazky;
    ui->doubleSpinBoxZap->setValue(zaplati);
    double soc = 0.045;
    double zaplatisoc = hrubaMzda * soc;
    ui->doubleSpinBoxSO->setValue(zaplatisoc);
    double zdra = 0.065;
    double zaplatizdra = hrubaMzda * zdra;
    ui->doubleSpinBoxZO->setValue(zaplatizdra);
}