#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mModelStandardItem = new QStandardItemModel(this);
    for (int i = 0; i < 9; ++i) {
        QList<QStandardItem*> row;
        for (int j = 0; j < 9; ++j) {
            QStandardItem *item = new QStandardItem("");
            row.append(item);
        }
        mModelStandardItem->appendRow(row);
    }
    ui->tableView->setModel(mModelStandardItem);
    connect(mModelStandardItem, &QStandardItemModel::dataChanged, this, &MainWindow::kontrola);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setVisible(false);
    ui->tableView->verticalHeader()->setVisible(false);
    connect(mModelStandardItem, &QStandardItemModel::dataChanged, this, &MainWindow::kontrola);
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::kontrola(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
    int radek = topLeft.row();
    int sloupec = topLeft.column();
    QString hodnota = mModelStandardItem->item(radek, sloupec)->text();

    if (hodnota.isEmpty()) {
        mModelStandardItem->item(radek, sloupec)->setBackground(Qt::white);
        return;
    }
    mModelStandardItem->blockSignals(true);
    for (int i = 0; i < 9; ++i) {
        if (i != sloupec) {
            if (mModelStandardItem->item(radek, i)->text() == hodnota) {
                mModelStandardItem->item(radek, sloupec)->setBackground(Qt::red);
                mModelStandardItem->blockSignals(false);
                return;
            }
        }
    }
    for (int i = 0; i < 9; ++i) {
        if (i != radek) {
            if (mModelStandardItem->item(i, sloupec)->text() == hodnota) {
                mModelStandardItem->item(radek, sloupec)->setBackground(Qt::red);
                mModelStandardItem->blockSignals(false);
                return;
            }
        }
    }
    mModelStandardItem->item(radek, sloupec)->setBackground(Qt::white);
    mModelStandardItem->blockSignals(false);
}