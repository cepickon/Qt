#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    MainWindow(const MainWindow &) = delete;
    MainWindow(MainWindow &&) = delete;
    MainWindow &operator=(const MainWindow &) = delete;
    MainWindow &operator=(MainWindow &&) = delete;
    ~MainWindow() override;
public slots:
    void on0();
    void on1();
    void on2();
    void on3();
    void on4();
    void on5();
    void on6();
    void on7();
    void on8();
    void on9();
    void onPlus();
    void onMinus();
    void onMultiply();
    void onDevide();
    void onEqual();
    void onComma();

private:
    Ui::MainWindow *ui;
    void insertToDisplay(QString);
    double calculate(double number1, char op, double number2);
};
#endif // MAINWINDOW_H
