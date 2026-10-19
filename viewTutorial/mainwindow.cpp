#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItem>
#include <QHeaderView>
#include <QModelIndex>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //naplnime data
    QStringList data;
    data.append("chleb");
    data.append("rohlik");
    data.append("maslo");
    data.append("salam");
    data.append("syr");
    mModelStandardItem = new QStandardItemModel(this);
    for (int i = 0; i < data.size(); ++i) {
        QStandardItem * item = new QStandardItem(data[i]);
        item->setCheckable(true);  //povolime zaskrtavani
        item->setToolTip("toto je tool tip text");
        item->setCheckState(Qt::Unchecked);//na zacatku jsou polozky nezaskrtle
        //mModelStandardItem->appendRow(item);//pridame item do modelu
        // 2. Vytvoříme položku pro druhý sloupec
        QStandardItem *item2 = new QStandardItem("Text pro druhý sloupec");
        // Můžete mu nastavit vlastní tooltip nebo vlastnosti:
        item2->setCheckable(true);
        // 3. Spojíme položky do seznamu (řádku)
        QList<QStandardItem*> row;
        row.append(item);
        row.append(item2);
        // 4. Přidáme celý řádek najednou do modelu
        mModelStandardItem->appendRow(row);
    }
    mModelStandardItem->sort(0);
    //nastavime jmena sloupecku
    QStringList headersNames;
    headersNames.append("prvy");
    headersNames.append("druhy");
    mModelStandardItem->setHorizontalHeaderLabels(headersNames);
    //tabulka sa roztahne
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //skrijeme cislovani radku v tabulke
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setModel(mModelStandardItem);
    ui->listView->setModel(mModelStandardItem);
    connect(ui->listView, &QListView::clicked, this, &MainWindow::onListViewItemClicked);
    connect(ui->tableView, &QTableView::clicked, this, &MainWindow::onListViewItemClicked);

    mModelStandardItem = new QStandardItemModel(this);
    int cislo = 1;
    for (int k = 0; k < 3; ++k) {
        QList<QStandardItem*> row;
        for (int j = 0; j < 4; ++j){
            QStandardItem *item = new QStandardItem(QString::number(cislo++));
            row.append(item);
        }
        mModelStandardItem->appendRow(row);
    }
    ui->tableView_2->setModel(mModelStandardItem);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mModelStandardItem->sort(0);
    QStringList headersNames1;
    headersNames1.append("prvy");
    headersNames1.append("druhy");
    headersNames1.append("treti");
    headersNames1.append("ctvrty");
    mModelStandardItem->setHorizontalHeaderLabels(headersNames1);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_2->verticalHeader()->setVisible(false);
    ui->tableView_2->setModel(mModelStandardItem);
    connect(ui->tableView_2, &QTableView::clicked, this, &MainWindow::biggerNumber);
    connect(ui->tableView_2, &QTableView::doubleClicked, this, &MainWindow::onListViewItemClicked2);
    connect(ui->tableView_2->horizontalHeader(), &QHeaderView::sectionDoubleClicked, this, &MainWindow::doubleColumn);
    connect(ui->tableView_2, &QTableView::doubleClicked,this, &MainWindow::doubleRow);

    ui->comboBox->addItem("CZK");
    ui->comboBox->addItem("EUR");
    ui->comboBox->addItem("USD");
    ui->comboBox->addItem("YEN");
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::zmena);
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::onListViewItemClicked(const QModelIndex &index){
    QString result;
    for(int i = 0; i < mModelStandardItem->rowCount(); ++i){
        QStandardItem *item = mModelStandardItem->item(i);
        if (item->checkState() == Qt::Checked){
            result += item->data(Qt::DisplayRole).toString() + " ";
        }
    }
    ui->labelInfo->setText(result);
}
void MainWindow::onListViewItemClicked2(const QModelIndex &index){
    QStandardItem *item = mModelStandardItem->itemFromIndex(index);
    int value = item->text().toInt();
    value =(value - 1) * 2;
    item->setText(QString::number(value));
}
void MainWindow::biggerNumber(const QModelIndex &index){
    if (!index.isValid()){
        return;
    }
    QStandardItem *item = mModelStandardItem->itemFromIndex(index);
    if (item) {
        int cislo = item->text().toInt();
        cislo += 1;
        item->setText(QString::number(cislo));
    }
}
void MainWindow::zmena(){
    QString text = ui->comboBox->currentText();
    for (int radek = 0; radek < mModelStandardItem->rowCount(); ++radek) {
        for (int sloupec = 0; sloupec < mModelStandardItem->columnCount(); ++sloupec) {
            QStandardItem *item = mModelStandardItem->item(radek, sloupec);
            if (item) {
                QString puvodniText = item->text();
                int mezera = puvodniText.indexOf(' ');
                if (mezera != -1) {
                    item->setText(puvodniText.left(mezera) + " " + text);
                } else {
                    item->setText(puvodniText + " " + text);
                }
            }
        }
    }
}
void MainWindow::doubleColumn(int sloupec){
    QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->tableView_2->model());
    for (int radek = 0; radek < model->rowCount(); ++radek) {
        QStandardItem *item = model->item(radek, sloupec);
        int hodnota = item->text().toInt();
        item->setText(QString::number(hodnota * 2));
    }
}
void MainWindow::doubleRow(const QModelIndex &index){
    int radek = index.row();
    QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->tableView_2->model());
    for (int sloupec = 0; sloupec < model->columnCount(); ++sloupec) {
        QStandardItem *item = model->item(radek, sloupec);
        int hodnota = item->text().toInt();
        item->setText(QString::number(hodnota * 2));
    }
}