#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringListModel>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList data;
    data.append("First");
    data.append("Second");
    data.append("Third");
    data.append("Fourth");
    data.append("Fifth");
    //mModelStringList = new QStringListModel(this);
    //mModelStringList->setStringList(data);
    //ui->listView->setModel(mModelStringList);
    mModelStandardItem = new QStandardItemModel(this);
    for(int i = 0; i < data.size(); i++){
        QStandardItem * item = new QStandardItem(data[i]);
        item->setCheckable(true);
        item->setCheckState(Qt::Unchecked);
        mModelStandardItem->appendRow(item);
    }
    ui->listView->setModel(mModelStandardItem);
    connect(ui->listView, &QListView::clicked, this, &MainWindow::onListViewItemClicked);
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::onListViewItemClicked(const QModelIndex &index){
    //QString itemText = mModelStringList->data(index).toString();
    QString itemText = mModelStandardItem->data(index).toString();
    int indexNumber = index.row();
    ui->label->setText(QString::number(indexNumber) + " " + itemText);
}