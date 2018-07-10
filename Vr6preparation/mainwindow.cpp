#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customPlot->addGraph();
    //ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->customPlot->xAxis->setTicker(timeTicker);
    ui->customPlot->xAxis->setRange(0, 21);
    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->yAxis->setRange(0, 10);

    dataTimer = new QTimer(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makePlot(){

    key = plotTimer.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    double lastPointKey = 0;
    if(key<20){
        ui->customPlot->xAxis->setRange(0, 21);
    }
    else if(key>20){
        ui->customPlot->xAxis->setRange(key, 21, Qt::AlignRight);
    }
    if (key-lastPointKey > 0.5) {
      ui->customPlot->graph(0)->addData(key, qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.3843));
      ui->customPlot->graph(0)->rescaleValueAxis(true);
      lastPointKey = key;
    }    
    ui->customPlot->replot();
}

void MainWindow::on_clearBtn_clicked()
{

    ui->customPlot->graph(0)->data()->clear();
    ui->customPlot->replot();
    plotTimer.restart();

    dataTimer->stop();
    ui->playBtn->setText("Play");
    key=0;

    ui->customPlot->xAxis->setRange(0, 21);
    ui->customPlot->yAxis->setRange(0, 10);
}

void MainWindow::on_playBtn_clicked()
{
    int timeAccumulator, timeElapsed=0;

    if(ui->playBtn->text()=="Play"){
        timeAccumulator=0;
        plotTimer.start();
        ui->playBtn->setText("Pause");
        // setup a timer that repeatedly calls makeplot
        QObject::connect(dataTimer, SIGNAL(timeout()), this, SLOT(makePlot()));
        dataTimer->start(0); // Interval 0 means to refresh as fast as possible
    }
    else if(ui->playBtn->text()=="Resume"){
        ui->playBtn->setText("Pause");
        dataTimer->start(); // Interval 0 means to refresh as fast as possible
        plotTimer.restart();
        qDebug() << plotTimer;
        plotTimer.addMSecs(timeAccumulator); ///// NAO FUNCIONA PORQUE?
    }
    else if(ui->playBtn->text()=="Pause"){
        ui->playBtn->setText("Resume");
        dataTimer->stop();
        timeElapsed=plotTimer.elapsed();
        timeAccumulator=timeAccumulator+timeElapsed;
        qDebug() << timeElapsed;
        qDebug() << timeAccumulator;
    }



}
