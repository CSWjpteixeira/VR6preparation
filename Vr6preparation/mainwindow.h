#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QSettings>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTimer *dataTimer;
    QTime plotTimer;
    double key;
    QString backgroundcolor = "background-color: rgb(255,255,255);";
    QString needlecolor = "255,255,255";
    int maxspeed = 300;
    int plotrange = 20;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int count;
    QTimer *timer = new QTimer(this);

    void LoadFile(QString xmlFilePath);

public slots:
    void setPos(int new_pos);

private slots:
    void makePlot();

    void on_playBtn_clicked();

    //void on_but1_clicked();

    void on_actionLoad_triggered();

    void on_actionExit_triggered();

    void on_actionHideSpeedometer_triggered();

    void on_actionHidePlot_triggered();

    void on_actionErase_triggered();

    void clearData();

private:
    Ui::MainWindow *ui;

    QVector<double> qv_x,qv_y;
    int p_init;
    int p_end;

    QGraphicsScene *scene;


protected:
    void paintEvent(QPaintEvent *);

signals:
    void valueChanged(int);
};

#endif // MAINWINDOW_H
