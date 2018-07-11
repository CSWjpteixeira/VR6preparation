#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTimer *dataTimer;
    QTime plotTimer;
    double key;

    QString backgroundcolor;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int count;
    QTimer *timer = new QTimer(this);

public slots:
    void setPos(int new_pos);
    void loadXmlFile(QString xmlFileString);

private slots:
    void makePlot();
    void on_clearBtn_clicked();
    void on_playBtn_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_exitBtn_clicked();

    void on_loadBtn_clicked();

    //void on_but1_clicked();

private:
    Ui::MainWindow *ui;

    QVector<double> qv_x,qv_y;
    int p_init;
    int p_end;

protected:
    void paintEvent(QPaintEvent *e);

signals:
    void valueChanged(int);
};

#endif // MAINWINDOW_H
