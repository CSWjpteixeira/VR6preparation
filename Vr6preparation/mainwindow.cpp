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

    //******|VelStart|************************************************

    p_init = -56;
    p_end = 139;
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    //connect(dataTimer,SIGNAL(timeout()),this,SLOT(update()));

    QString xmlFileString("/home/hmi/Desktop/Vr6preparation/Vr6preparation/ini.xml");

    loadXmlFile(xmlFileString);

    this->setStyleSheet(backgroundcolor);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadXmlFile(QString xmlFileString){

    QFile xmlFile(xmlFileString);
    QXmlStreamReader xmlReader;
    xmlReader.setDevice(&xmlFile);
    xmlReader.readNext();
    xmlReader.readNext();
    while(!xmlReader.isEndDocument()){
        if(xmlReader.isStartElement()){
            QString name = xmlReader.name().toString();
            if(name == "background"){
                QMessageBox::information(this,name,xmlReader.readElementText());
                backgroundcolor="background-color: rgb" + xmlReader.readElementText() + ";";
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
    xmlReader.clear();
    xmlFile.close();
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
        timer->start(40);
    }
    else if(ui->playBtn->text()=="Resume"){
        qWarning("Resumed");
        ui->playBtn->setText("Pause");
        dataTimer->start(0);
        timer->start(40);
    }
    else if(ui->playBtn->text()=="Pause"){
        qWarning("Paused");
        dataTimer->stop();
        ui->playBtn->setText("Resume");
        timer->stop();
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

void MainWindow::on_loadBtn_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this,tr("Open File"),"/home/hmi/Desktop","All Files(*.*);;XML File (*.xml)");
    QFile testFile(filename);
    if(!testFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this,"Load Xml File Problem","Couldn't open xml file to load settings",QMessageBox::Ok);
        loadXmlFile("~/Vr6preparation/ini.xml");
        return;
    }
    else{
        loadXmlFile(filename);
    }
}

//*****************************************************| Velocímetro |******************************************************************************
void MainWindow::paintEvent(QPaintEvent *e)
{

    static const QPoint needle[3] = {
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(-40,-40)

    };
    int dim = qMin(width()/2,height()/2);
    QPainter painter(this);
    QColor needCol(0,0,0);

    painter.translate(width() / 4, height()/2);
    painter.scale(dim / 200.0, dim / 200.0);
    painter.setRenderHint(QPainter::Antialiasing);

//****************************************************
//posição agulha
//****************************************************

    if(p_init < p_end)
    {
    painter.setPen(Qt::NoPen);
    painter.setBrush(needCol);
    painter.save();
    painter.rotate(p_init);
    painter.drawPolygon(needle,3);
    painter.restore();
    painter.setPen(needCol);


      for(int i = 0; i <10; i++)
    {
        painter.drawLine(-88,0,-96,0);
        painter.rotate(20.0);
    }
    p_init++;
//****CONDI-1*****************
  }else if(p_init > p_end)
    {
        painter.setPen(Qt::NoPen);
        painter.setBrush(needCol);
        painter.save();
        painter.rotate(p_init);                  //alterhere
        painter.drawPolygon(needle,3);
        painter.restore();
        painter.setPen(needCol);

        for(int i = 0; i <10; i++)
        {
            painter.drawLine(-88,0,-96,0);
            painter.rotate(20.0);
        }
        p_init--;

//***CONDI-2******************
    }else
    {
        painter.setPen(Qt::NoPen);
        painter.setBrush(needCol);
        painter.save();
        painter.rotate(p_end);
        painter.drawPolygon(needle,3);
        painter.restore();
        painter.setPen(needCol);

        for(int i = 0; i <10; i++)
        {
            painter.drawLine(-88,0,-96,0);
            painter.rotate(20.0);
        }
        if(p_end>=-56)
        {
            p_end--;
        }
    }
//********CONDI-3*******************

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

