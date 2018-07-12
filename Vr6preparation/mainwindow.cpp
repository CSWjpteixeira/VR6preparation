#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QtXml>
#include <QXmlReader>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customPlot->addGraph();
    //ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    menuBar()->setNativeMenuBar(false);

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->customPlot->xAxis->setTicker(timeTicker);
    ui->customPlot->xAxis->setRange(0, 21);
    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->yAxis->setRange(0, 10);

    dataTimer = new QTimer(this);

    //******|VelStart|************************************************
    //scene = new QGraphicsScene(this);
   // ui->graphicsView->setScene(scene);

    p_init = -56;
    p_end = 139;
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    //connect(dataTimer,SIGNAL(timeout()),this,SLOT(update()));


    this->setStyleSheet(backgroundcolor);

    //**new
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
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

//*****************************************************| Velocímetro |******************************************************************************
void MainWindow::paintEvent(QPaintEvent *)
{


    static const QPoint needle[3] = {
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(-40,-40)

    };
    int dim = qMin(width()/2,height()/2);

    //****testzone
    QPixmap *pix = new QPixmap(351,241);
    QPainter *painter = new QPainter(pix);
    //************

    QColor needCol(255,255,255);

    painter->translate(width() / 4.5, height()/2.3);
    painter->scale(dim / 200.0, dim / 200.0);
    painter->setRenderHint(QPainter::Antialiasing);

//****************************************************
//posição agulha
//****************************************************

    if(p_init < p_end)
    {
    painter->setPen(Qt::NoPen);
    painter->setBrush(needCol);
    painter->save();
    painter->rotate(p_init);
    painter->drawPolygon(needle,3);
    scene->addPixmap(*pix);
    painter->restore();
    painter->setPen(needCol);


      for(int i = 0; i <10; i++)
    {
        painter->drawLine(-88,0,-96,0);
        painter->rotate(20.0);
    }
    p_init++;
    scene->addPixmap(*pix);
//****CONDI-1*****************
  }else if(p_init > p_end)
    {
        painter->setPen(Qt::NoPen);
        painter->setBrush(needCol);
        painter->save();
        painter->rotate(p_init);                  //alterhere
        painter->drawPolygon(needle,3);
        scene->addPixmap(*pix);
        painter->restore();
        painter->setPen(needCol);

        for(int i = 0; i <10; i++)
        {
            painter->drawLine(-88,0,-96,0);
            painter->rotate(20.0);
        }
        p_init--;
        scene->addPixmap(*pix);
//***CONDI-2******************
    }else
    {
        painter->setPen(Qt::NoPen);
        painter->setBrush(needCol);
        painter->save();
        painter->rotate(p_end);
        painter->drawPolygon(needle,3);
        scene->addPixmap(*pix);
        painter->restore();
        painter->setPen(needCol);

        for(int i = 0; i <10; i++)
        {
            painter->drawLine(-88,0,-96,0);
            painter->rotate(20.0);
        }
        scene->addPixmap(*pix);
        if(p_end>=-56)
        {

           p_end--;

        }
    }


}
//**************************************************************
void MainWindow::setPos(int new_pos)
{

    if(new_pos!=p_end)
    {
        p_end = new_pos;
    }
    emit valueChanged(new_pos);
}
//*************************************************************

void MainWindow::on_actionLoad_triggered()
{
    QFile xmlFile(QFileDialog::getOpenFileName(this,tr("Open File"),"../Vr6preparation/","All Files(*.*);;XML File (*.xml)"));

    if(!xmlFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this,"Load Xml File Problem","Couldn't open xml file to load settings",QMessageBox::Ok);
        return;
    }
    QXmlStreamReader xmlReader;

    xmlReader.setDevice(&xmlFile);
    xmlReader.readNext();
    xmlReader.readNext();
    while(!xmlReader.isEndDocument()){
        if(xmlReader.isStartElement()){
            QString name = xmlReader.name().toString();
            if(name == "background"){
                QMessageBox::information(this,name,xmlReader.readElementText());
                QString test=xmlReader.readElementText();
                backgroundcolor="background-color: rgb"+test+";"; // REVER!!!!!!
                qDebug() << backgroundcolor;
                xmlReader.readNext();
                xmlReader.readNext();
            }
            else if(name == "needlecolor"){
                QMessageBox::information(this,name,xmlReader.readElementText());
                QString test2=xmlReader.readElementText();
                //backgroundcolor="background-color: rgb"+test+";"; // REVER!!!!!!
                //qDebug() << backgroundcolor;
                xmlReader.readNext();
                xmlReader.readNext();
            }
            else if(name == "maxvelocity"){
                QMessageBox::information(this,name,xmlReader.readElementText());
                QString test3=xmlReader.readElementText();
                //backgroundcolor="background-color: rgb"+test+";"; // REVER!!!!!!
                //qDebug() << backgroundcolor;
                xmlReader.readNext();
                xmlReader.readNext();
            }
            else if(name == "plotrange"){
                QMessageBox::information(this,name,xmlReader.readElementText());
                QString test4=xmlReader.readElementText();
                //backgroundcolor="background-color: rgb"+test+";"; // REVER!!!!!!
                //qDebug() << backgroundcolor;
                xmlReader.readNext();
                xmlReader.readNext();
            }
            else {
                xmlReader.readNext();
                xmlReader.readNext();
            }
        }
        else if(xmlReader.isEndElement()){
            xmlReader.readNext();
            xmlReader.readNext();
        }
        if(xmlReader.hasError()){
            qDebug() << "XML Error: " << xmlReader.errorString().data();
            return;
        }
    }
}

void MainWindow::on_actionExit_triggered()
{
    if(QMessageBox::Yes == QMessageBox::question(this,tr("Warning"),tr("Are you sure you want to exit?"))){
        QApplication::quit();
    }
}

void MainWindow::on_actionHideSpeedometer_triggered()
{
    if(ui->actionHideSpeedometer->text()=="Hide Speedometer"){
        ui->actionHideSpeedometer->setText("Show Speedometer");
        ui->graphicsView->hide();
    }
    else if(ui->actionHideSpeedometer->text()=="Show Speedometer"){
        ui->actionHideSpeedometer->setText("Hide Speedometer");
        ui->graphicsView->show();
    }
}

void MainWindow::on_actionHidePlot_triggered()
{
    if(ui->actionHidePlot->text()=="Hide Plot 2D"){
        ui->actionHidePlot->setText("Show Plot 2D");
        ui->customPlot->hide();
    }
    else if(ui->actionHidePlot->text()=="Show Plot 2D"){
        ui->actionHidePlot->setText("Hide Plot 2D");
        ui->customPlot->show();
    }
}

void MainWindow::on_actionErase_triggered()
{
    qWarning("Data Cleared");
    ui->customPlot->xAxis->setRange(0, 21);
    ui->customPlot->yAxis->setRange(0, 10);
    ui->customPlot->graph(0)->data()->clear();
    ui->customPlot->replot();
    plotTimer.restart();
    timer->stop();
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

        timer->start(70);
        //count++;
    }
    else if(ui->playBtn->text()=="Resume"){
        qWarning("Resumed");
        ui->playBtn->setText("Pause");
        dataTimer->start(0);

         timer->start(70);/*Resume the veloci*/
    }
    else if(ui->playBtn->text()=="Pause"){
        qWarning("Paused");
        dataTimer->stop();
        ui->playBtn->setText("Resume");

        timer->stop();
    }


}
