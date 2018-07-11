#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTimer *dataTimer;
    QTime plotTimer;
    double key;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void makePlot();
    void on_clearBtn_clicked();
    void on_playBtn_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_exitBtn_clicked();

    void on_loadBtn_clicked();

private:
    Ui::MainWindow *ui;

    QVector<double> qv_x,qv_y;
};

#endif // MAINWINDOW_H
