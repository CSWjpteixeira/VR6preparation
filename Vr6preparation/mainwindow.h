#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addPoint(double x, double y);
    void clearData();

private slots:
    void makePlot();
    void on_clearBtn_clicked();
    void on_addValueBtn_clicked();

private:
    Ui::MainWindow *ui;

    QVector<double> qv_x,qv_y;
};

#endif // MAINWINDOW_H
