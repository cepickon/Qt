#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
public slots:
    void prevod();
    void prevodzpet();
    void tlacitko();
private:
    Ui::MainWindow *ui;
    bool mjeButtonVelky;
};
#endif // MAINWINDOW_H