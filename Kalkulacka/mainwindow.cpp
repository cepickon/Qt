#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton0, &QPushButton::clicked, this, &MainWindow::on0);
    connect(ui->pushButton1, &QPushButton::clicked, this, &MainWindow::on1);
    connect(ui->pushButton2, &QPushButton::clicked, this, &MainWindow::on2);
    connect(ui->pushButton3, &QPushButton::clicked, this, &MainWindow::on3);
    connect(ui->pushButton4, &QPushButton::clicked, this, &MainWindow::on4);
    connect(ui->pushButton5, &QPushButton::clicked, this, &MainWindow::on5);
    connect(ui->pushButton6, &QPushButton::clicked, this, &MainWindow::on6);
    connect(ui->pushButton7, &QPushButton::clicked, this, &MainWindow::on7);
    connect(ui->pushButton8, &QPushButton::clicked, this, &MainWindow::on8);
    connect(ui->pushButton9, &QPushButton::clicked, this, &MainWindow::on9);
    connect(ui->pushButtonPlus, &QPushButton::clicked, this, &MainWindow::onPlus);
    connect(ui->pushButtonMinus, &QPushButton::clicked, this, &MainWindow::onMinus);
    connect(ui->pushButtonMultiply, &QPushButton::clicked, this, &MainWindow::onMultiply);
    connect(ui->pushButtonDevide, &QPushButton::clicked, this, &MainWindow::onDevide);
    connect(ui->pushButtonEqual, &QPushButton::clicked, this, &MainWindow::onEqual);
    connect(ui->pushButtonComma, &QPushButton::clicked, this, &MainWindow::onComma);
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::insertToDisplay(QString string){
    ui->lineDisplay->setText(ui->lineDisplay->text() + string);
}
double MainWindow::calculate(double number1, char op, double number2){
    switch (op) {
    case '+':
        return number1 + number2;
    case '-':
        return number1 - number2;
    case '*':
        return number1 * number2;
    case '/':
        return number1 / number2;
    default:
        return -1;
    }
}
void MainWindow::on0(){
    insertToDisplay("0");
}
void MainWindow::on1(){
    insertToDisplay("1");
}
void MainWindow::on2(){
    insertToDisplay("2");
}
void MainWindow::on3(){
    insertToDisplay("3");
}
void MainWindow::on4(){
    insertToDisplay("4");
}
void MainWindow::on5(){
    insertToDisplay("5");
}
void MainWindow::on6(){
    insertToDisplay("6");
}
void MainWindow::on7(){
    insertToDisplay("7");
}
void MainWindow::on8(){
    insertToDisplay("8");
}
void MainWindow::on9(){
    insertToDisplay("9");
}
void MainWindow::onPlus(){
    insertToDisplay(" + ");
}
void MainWindow::onMinus(){
    insertToDisplay(" - ");
}
void MainWindow::onMultiply(){
    insertToDisplay(" * ");
}
void MainWindow::onDevide(){
    insertToDisplay(" / ");
}
void MainWindow::onEqual(){
    QString expr = ui->lineDisplay->text();
    char op;
    while(true) {
        int indexOp = -1;
        for (int i = 2; i < expr.size(); ++i) {
            if(expr[i] == '*' || expr[i] == '/') {
                indexOp = i;
                break;
            } else if(indexOp == -1 && (expr[i] == '+' || expr[i] == '-')) {
                indexOp = i;
            }
        }
        if (indexOp == -1)
            break;
        op = expr[indexOp].toLatin1();
        QString number1;
        int startIndex;
        for (startIndex = indexOp - 2; startIndex >= 0 ; --startIndex) {
            if (expr[startIndex] == ' ') {
                break;
            }
            number1 = expr[startIndex] + number1;
        }
        startIndex++;
        QString number2;
        int endIndex;
        for (endIndex = indexOp + 2; endIndex < expr.size(); ++endIndex) {
            if (expr[endIndex] == ' ') {
                break;
            }
            number2 += expr[endIndex];
        }
        endIndex--;
        double result = calculate(number1.toDouble(),op, number2.toDouble());
        QString counted = expr.mid(startIndex, endIndex - startIndex + 1);
        expr.replace(counted, QString::number(result));
    }
    ui->lineDisplay->setText(expr);
}
void MainWindow::onComma(){
    insertToDisplay(".");
}