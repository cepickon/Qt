#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QStandardItemModel>

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
public slots:
    void onTableViewItemAdded(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *mModelStandardItem;
};
#endif // MAINWINDOW_H