#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItem>
#include <QHeaderView>
//A

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mModelStandardItem = new QStandardItemModel(this);
    for (int i = 0; i < 5; ++i) {
        QList<QStandardItem*> row;
        for (int j = i*6; j < (i+1)*6; ++j) {
            QStandardItem * item = new QStandardItem();
            item->setData(Qt::UserRole);
            row.append(item);
        }
        mModelStandardItem->appendRow(row);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->verticalHeader()->setVisible(true);
    ui->tableView->setModel(mModelStandardItem);
    connect(ui->tableView, &QTableView::clicked, this, &MainWindow::onTableViewItemAdded);
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::onTableViewItemAdded(const QModelIndex &index){
    QStandardItem *item = mModelStandardItem->itemFromIndex(index);
    QString value1 = item->data(Qt::UserRole).toString();
    int count1 = 0;
    for(int i = 0; i < mModelStandardItem->rowCount(); ++i){
        for(int j = 0; j < mModelStandardItem->columnCount(); ++j) {
            QStandardItem *item = mModelStandardItem->item(i, j);
            QString value = item->data(Qt::UserRole).toString();
            if(value1 == value){
                count1++;
            }
        }
    }
    ui->label->setText(value1 + " " + QString::number(count1));
}