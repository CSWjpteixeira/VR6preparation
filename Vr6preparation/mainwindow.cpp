#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


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
    ui->comboBox->addItem("Both on");
    ui->comboBox->addItem("Speedometer only");
    ui->comboBox->addItem("Graph only");
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
      ui->customPlot->graph(0)->addData(key, abs((double)10*qSin(key/0.3843)));
      ui->customPlot->graph(0)->rescaleValueAxis(true);
      lastPointKey = key;
    }    
    ui->customPlot->replot();
}

void MainWindow::on_clearBtn_clicked()
{
    qWarning("Data Cleared");
    ui->customPlot->xAxis->setRange(0, 21);
    ui->customPlot->yAxis->setRange(0, 10);
    ui->customPlot->graph(0)->data()->clear();
    ui->customPlot->replot();
    plotTimer.restart();

    dataTimer->stop();
    ui->playBtn->setText("Play");
    key=0;

}

void MainWindow::on_playBtn_clicked()
{
    if(ui->playBtn->text()=="Play"){
        qWarning("Started");
        plotTimer.start();
        ui->playBtn->setText("Pause");
        // setup a timer that repeatedly calls makeplot
        QObject::connect(dataTimer, SIGNAL(timeout()), this, SLOT(makePlot()));
        dataTimer->start(0);
    }
    else if(ui->playBtn->text()=="Resume"){
        qWarning("Resumed");
        ui->playBtn->setText("Pause");
        dataTimer->start(0);
    }
    else if(ui->playBtn->text()=="Pause"){
        qWarning("Paused");
        dataTimer->stop();
        ui->playBtn->setText("Resume");
    }

}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1=="Both on"){
        ui->customPlot->QWidget::show();
    }
    else if(arg1=="Speedometer only"){
        ui->customPlot->QWidget::hide();
    }
    else if("Graph only"){
        ui->customPlot->QWidget::show();
    }

}

void MainWindow::on_exitBtn_clicked()
{
    if(QMessageBox::Yes == QMessageBox::question(this,tr("Warning"),tr("Are you sure you want to exit?"))){
        QApplication::quit();
    }
}
