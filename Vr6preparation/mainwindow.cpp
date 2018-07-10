#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customPlot->addGraph();
    //ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);

    QTimer *dataTimer = new QTimer(this);

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->customPlot->xAxis->setTicker(timeTicker);
    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->yAxis->setRange(0, 10);

    // setup a timer that repeatedly calls makeplot
    QObject::connect(dataTimer, SIGNAL(timeout()), this, SLOT(makePlot()));
    dataTimer->start(0); // Interval 0 means to refresh as fast as possible
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
}

void MainWindow::clearData()
{
    qv_x.clear();
    qv_y.clear();

}


void MainWindow::makePlot(){

    static QTime time(QTime::currentTime());

    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey = 0;
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

}

void MainWindow::on_addValueBtn_clicked()
{
    addPoint(ui->Xspinbox->value(),ui->Yspinbox->value());
    makePlot();

}
