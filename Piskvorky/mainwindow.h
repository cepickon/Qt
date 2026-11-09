#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QHeaderView>
#include <QModelIndex>
#include <QMessageBox>
#include <QApplication>
#include <QPushButton>
#include <QColor>

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
    ~MainWindow() override;
    ;bool checkWin(QString player);
    int moves = 0;
    QString player = "X";
    void resetGame();
    int vyhryX = 0;
    int vyhryO = 0;
public slots:
    void onTableViewItemAdded(const QModelIndex &index);
    void endGame();
private:
    Ui::MainWindow *ui;
    QStandardItemModel *mModelStandardItem;
};
#endif // MAINWINDOW_H