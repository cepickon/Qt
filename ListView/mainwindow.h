#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QStringListModel>
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
    void onListViewItemClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *mModelStandardItem;
    QStringListModel * mModelStringList;
};
#endif // MAINWINDOW_H