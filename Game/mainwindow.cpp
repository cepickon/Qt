#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRandomGenerator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), mScore(0), mTimeLeft(30), mCurrentInterval(1000)
{
    setWindowTitle("ButtonClick");
    QMainWindow::resize(600, 500);
    setMinimumSize(400, 400);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    scoreLabel = new QLabel("Score 0:", this);
    timeLabel = new QLabel("Time 30s", this);
    QHBoxLayout *topBarLayout = new QHBoxLayout();
    topBarLayout->addWidget(scoreLabel);
    topBarLayout->addStretch();
    topBarLayout->addWidget(timeLabel);
    mainLayout->addLayout(topBarLayout);
    gameAreaWidget = new QWidget(this);
    mainLayout->addWidget(gameAreaWidget, 1);
    targetButton = new QPushButton("Click on me!", gameAreaWidget);
    targetButton->resize(100, 40);
    gameTimer = new QTimer(this);
    buttonClickedTimer = new QTimer(this);

    int g = QRandomGenerator::global()->bounded(0, 100);
    int b = QRandomGenerator::global()->bounded(0, 256);
    gameAreaWidget->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(0).arg(g).arg(b));

    connect(targetButton, &QPushButton::clicked, this, &MainWindow::onTargetClicked);
    connect(gameTimer, &QTimer::timeout, this, &MainWindow::onGametimerTimeout);
    connect(buttonClickedTimer, &QTimer::timeout, this, &MainWindow::onButtonTimerTimeout);
}
MainWindow::~MainWindow() = default;

void MainWindow::onTargetClicked(){
    if (mScore == 0){
        gameTimer->start(1000);
        mTimeLeft = 30;
        mCurrentInterval = 1000;
    }
    ++mScore;
    scoreLabel->setText("Score " + QString::number(mScore));
    buttonClickedTimer->start(mCurrentInterval);
    mCurrentInterval = mCurrentInterval * 0.9;
    moveTargettoRandomPosition();

    int r = QRandomGenerator::global()->bounded(256);
    int g = QRandomGenerator::global()->bounded(256);
    int b = QRandomGenerator::global()->bounded(256);
    targetButton->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(r).arg(g).arg(b));
}
void MainWindow::onGametimerTimeout(){
    mTimeLeft--;
    timeLabel->setText("Time " + QString::number(mTimeLeft) + "s");
    if (mTimeLeft == 0){
        gameTimer->stop();
        buttonClickedTimer->stop();
        QMessageBox endGameMessage;
        endGameMessage.setText("Your score is " + QString::number(mScore) + ". Press OK to play");
        endGameMessage.exec();
        mScore = 0;
    }
}
void MainWindow::onButtonTimerTimeout(){
    moveTargettoRandomPosition();
}

void MainWindow::resize(){
    targetButton->move((gameAreaWidget->width()-targetButton->width()/2)/2,(gameAreaWidget->height()-targetButton->height()/2)/2);
}
void MainWindow::moveTargettoRandomPosition(){
    int maxX = gameAreaWidget->width() - targetButton->width();
    int maxY = gameAreaWidget->height() - targetButton->height();
    int randomX = QRandomGenerator::global()->bounded(0, maxX);
    int randomY = QRandomGenerator::global()->bounded(0, maxY);
    targetButton->move(randomX, randomY);
}