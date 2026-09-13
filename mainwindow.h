#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QTableWidgetItem>

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

private slots:
    void on_insertButton_clicked();
    void on_extractButton_clicked();
    void on_searchButton_clicked();
    void on_clearFilterButton_clicked();
    void onDateFilterChanged();
    void on_csvButton_clicked();
    void on_excelButton_clicked();

private:
    Ui::MainWindow *ui;
    QString selectedFilePath;
    bool dateFilterTouched = false;
    void extractFromDb();
    void extractFromDelimitedFile(const QString &delimiter);
    void colorValveValueItem(QTableWidgetItem *item);
};
#endif // MAINWINDOW_H
