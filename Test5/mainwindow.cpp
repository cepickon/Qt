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
    connect(mModelStandardItem, &QStandardItemModel::itemChanged, this, &MainWindow::onTableViewItemClicked);
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::onTableViewItemClicked(QStandardItem *item){
    int sum = 0;
    for(int i = 0; i < mModelStandardItem->rowCount(); ++i) {
        QStandardItem *item1 = mModelStandardItem->item(item->row(), i);
        int number = item1->data(Qt::DisplayRole).toInt();
        if(item){
            if(item1->data().toInt() >= 0 && i != item->row()){
                sum += number;
            }
        }
    }
    for(int j = 0; j < mModelStandardItem->columnCount(); ++j) {
        QStandardItem *item2 = mModelStandardItem->item(item->column(), j);
        int number1 = item2->data(Qt::DisplayRole).toInt();
        if(item){
            if(item2->data().toInt() >= 0){
                sum += number1;
            }
        }
    }
    ui->label->setText("Soucet cisel ve sloupci a radku " + QString::number(sum));
}