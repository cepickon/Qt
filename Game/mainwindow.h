#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
public slots:
    void onTargetClicked();
    void onGametimerTimeout();
    void onButtonTimerTimeout();
    void resize();

private:
    QWidget *gameAreaWidget;
    QPushButton *targetButton;
    QTimer *gameTimer;
    QTimer *buttonClickedTimer;
    QLabel *scoreLabel;
    QLabel *timeLabel;
    int mScore;
    int mTimeLeft;
    int mCurrentInterval;
    void moveTargettoRandomPosition();
};
#endif // MAINWINDOW_H