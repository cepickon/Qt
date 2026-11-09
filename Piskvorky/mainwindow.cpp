#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItem>
#include <QHeaderView>
#include <QModelIndex>
#include <QMessageBox>
#include <QApplication>
#include <QPushButton>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mModelStandardItem = new QStandardItemModel(this);
    for (int i = 0; i < 10; ++i) {
        QList<QStandardItem*> row;
        for (int j = i*10; j < (i+1)*10; ++j) {
            QStandardItem * item = new QStandardItem();
            item->setData(Qt::UserRole);
            row.append(item);
        }
        mModelStandardItem->appendRow(row);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setVisible(false);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setModel(mModelStandardItem);
    connect(ui->tableView, &QTableView::clicked, this, &MainWindow::onTableViewItemAdded);
    connect(ui->pushButton_r, &QPushButton::clicked, this, &MainWindow::resetGame);
    connect(ui->pushButton_eg, &QPushButton::clicked, this, &MainWindow::endGame);
    ui->pushButton_r->setStyleSheet("QPushButton {""background-color: blue;""color: white;""font-weight: bold;""border-radius: 5px;""padding: 5px;""}""QPushButton:hover {""background-color: darkblue;""}");
    ui->pushButton_eg->setStyleSheet("QPushButton {""background-color: red;""color: white;""font-weight: bold;""border-radius: 5px;""padding: 5px;""}""QPushButton:hover {""background-color: darkred;""}");
    ui->label_vx->setText("Výhry X: 0");
    ui->label_vo->setText("Výhry O: 0");
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::onTableViewItemAdded(const QModelIndex &index){
    if (!index.isValid()){
        return;
    }
    if (!mModelStandardItem->item(index.row(), index.column())->text().isEmpty()){
        return;
    }
    QStandardItem *item = mModelStandardItem->item(index.row(), index.column());
    item->setText(player);
    if (player == "X") {
        item->setForeground(QColor("red"));
    }
    else {
        item->setForeground(QColor("blue"));
    }
    moves++;
    if (checkWin(player)) {
        if (player == "X") {
            vyhryX++;
            ui->label_vx->setText("Výhry X: " + QString::number(vyhryX));
        }
        else {
            vyhryO++;
            ui->label_vo->setText("Výhry O: " + QString::number(vyhryO));
        }
        if (vyhryX == 3) {
            QMessageBox::information(this, "Konec hry", "Definitivním vítězem je hráč X!");
            vyhryX = 0;
            vyhryO = 0;
            ui->label_vx->setText("Výhry X: 0");
            ui->label_vo->setText("Výhry O: 0");
        }
        else if (vyhryO == 3) {
            QMessageBox::information(this, "Konec hry", "Definitivním vítězem je hráč O!");
            vyhryX = 0;
            vyhryO = 0;
            ui->label_vx->setText("Výhry X: 0");
            ui->label_vo->setText("Výhry O: 0");
        }
        else {
            QMessageBox::information(this, "Výhra", "Vyhrál hráč " + player + "\nPočet tahů: " + QString::number(moves));
        }
        resetGame();
        return;
    }
    if (moves == 100) {
        QMessageBox::information(this, "Remíza", "Hra skončila remízou!");
        resetGame();
        return;
    }
    player = (player == "X") ? "O" : "X";
}
bool MainWindow::checkWin(QString player){
    int directions[4][2] = {{0, 1},{1, 0},{1, 1},{1, -1}};
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            if (mModelStandardItem->item(row, col)->text() != player){
                continue;
            }
            for (int d = 0; d < 4; d++) {
                int count = 1;
                for (int i = 1; i < 4; i++) {
                    int newRow = row + directions[d][0] * i;
                    int newCol = col + directions[d][1] * i;
                    if (newRow < 0 || newRow >= 10 || newCol < 0 || newCol >= 10){
                        break;
                    }
                    if (mModelStandardItem->item(newRow, newCol)->text() == player){
                        count++;
                    }
                    else{
                        break;
                    }
                }
                if (count >= 4){
                    return true;
                }
            }
        }
    }
    return false;
}
void MainWindow::resetGame(){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mModelStandardItem->item(i, j)->setText("");
            mModelStandardItem->item(i, j)->setForeground(QColor("black"));
        }
    }
    moves = 0;
    player = "X";
}
void MainWindow::endGame(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Ukončení hry", "Opravdu chcete ukončit hru?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}