//A
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItem>

const int SIZE = 10;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mModelStandardItem = new QStandardItemModel(this);
    for (int i = 0; i < SIZE; ++i) {
        QList<QStandardItem*> row;
        for (int j = i*SIZE; j < (i+1)*SIZE; ++j) {
            QStandardItem * item = new QStandardItem();
            item->setData(Qt::UserRole);
            row.append(item);
        }
        mModelStandardItem->appendRow(row);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setVisible(false);
    ui->tableView->setModel(mModelStandardItem);
    connect(mModelStandardItem, &QStandardItemModel::itemChanged, this, &MainWindow::lichSloupec);
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::lichSloupec(QStandardItem *itemChanged){
    int number = itemChanged->data(Qt::DisplayRole).toInt();
    int sum = 0;
    if (number > 0) {
        int column = itemChanged->column();
        for (int j = 0; j < mModelStandardItem->rowCount(); ++j) {
            QStandardItem *item = mModelStandardItem->item(j, column);
            if (item->data(Qt::DisplayRole).toInt() % 2 != 0) {
                sum++;
            }
        }
        ui->label->setText("Ve sloupci je  " + QString::number(sum) + " lichých čísel");
    }
}