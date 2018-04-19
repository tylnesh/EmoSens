#include "datacollectiondialog.h"
#include "ui_datacollectiondialog.h"
#include <QDateTime>
#include "nzmqtsubscriber.h"
#include "3rdparty/cppzmq/zmq.hpp"
#include <qmsgpack/msgpack.h>
#include <iostream>
#include <QDebug>
#include <QLabel>
#include <QVariant>
#include <QLabel>
#include <QtSerialPort/QtSerialPort>
#include <QtCharts>
#include <QDialog>
#include <QtWidgets/QMainWindow>

//#include <QtMultimediaWidgets>
//#include <P

//#include "PlottingImageListener.hpp"
//#include "StatusListener.hpp"

//#include "afacelistener.h"
//#include <ProcessStatusListener.h>
//#include <poitn

QString affectiva = "";
QString arduino = "";
double arduinoGSR = 0.0;
double arduinoHR = 0.0;

DataCollectionDialog::DataCollectionDialog(QWidget *parent, const QString &ip) :
    QDialog(parent), m_ip(ip),
    ui(new Ui::DataCollectionDialog)
{
    this->setWindowState(Qt::WindowFullScreen);
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window);
    this->showMaximized();

    QDateTime UTC(QDateTime::currentDateTimeUtc());
        QDateTime local(UTC);



         emotion.setFileName("emotion_" + local.toString() +".dat");
         emotion.open(QIODevice::ReadWrite);
         timer = new QTimer(this);
         connect(timer, SIGNAL(timeout()), this, SLOT(incrementT()));

         try{

          nzmqt::ZMQContext* context = nzmqt::createDefaultContext(this);
          zmq::context_t contextPort (1);
          zmq::socket_t req (contextPort, ZMQ_REQ);
          QString ipString = "tcp://" + m_ip + ":50020";
          req.connect(ipString.toStdString());

//          // Ask for the subport
          zmq::message_t subPortRequest (8);
          memcpy (subPortRequest.data(), "SUB_PORT", 8);
          req.send(subPortRequest);
          zmq::message_t reply;
          req.recv(&reply);

          QString sub_port = QString::fromStdString(std::string(static_cast<char*>(reply.data()), reply.size()));
qDebug() << sub_port;
          context->start();
          QString address = "tcp://"+m_ip+":"+sub_port;

          nzmqtSubscriber* sub0 = new nzmqtSubscriber(*context, address, "pupil.0", this );
          nzmqtSubscriber* sub1 = new nzmqtSubscriber(*context, address, "pupil.1", this );
          nzmqtSubscriber* sub2 = new nzmqtSubscriber(*context, address, "gaze", this );

//          context->start();
          address = "tcp://"+m_ip+":5555";
          nzmqtSubscriber* affect = new nzmqtSubscriber(*context, address, "", this);

          connect(sub0, SIGNAL(extractData(QVariant, QString)),this,SLOT(dataReceived(QVariant,QString)));
          connect(sub1, SIGNAL(extractData(QVariant,QString)),this,SLOT(dataReceived(QVariant,QString)));
          connect(sub2, SIGNAL(extractData(QVariant,QString)),this,SLOT(dataReceived(QVariant,QString)));
          connect(affect, SIGNAL(extractData(QVariant,QString)),this,SLOT(dataReceived(QVariant,QString)));

          serial= new QSerialPort();
          serial->setPortName("/dev/ttyACM0");
                 if (serial->open(QIODevice::ReadWrite))
                {
                 serial->setBaudRate(QSerialPort::Baud9600);
                 serial->setDataBits(QSerialPort::Data8);
                 serial->setParity(QSerialPort::NoParity);
                 serial->setStopBits(QSerialPort::OneStop);
                 serial->setFlowControl(QSerialPort::NoFlowControl);
                qDebug("Connection established");


                 connect(serial, &QSerialPort::readyRead, this, &DataCollectionDialog::handleReadyRead);
                 connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
                                 this, &DataCollectionDialog::handleError);
                 connect(&m_timer, &QTimer::timeout, this, &DataCollectionDialog::handleTimeout);
                 m_timer.start(100);
                 } else qDebug("Connection Error");





                  //connect(sub, SIGNAL(finished()), SLOT(quit()));

                  sub0->startImpl();
                  sub1->startImpl();
                  sub2->startImpl();
                  affect->startImpl();
              }catch (std::exception& ex)
              {
                  qWarning() << ex.what();
                  exit(-1);}

         connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realTimeDataSlot()));


             series = new QPieSeries();
             series->setHoleSize(0.35);


             series->append("Anger", affect[0]);
             series->append("Contempt", affect[1]);
             series->append("Disgust", affect[2]);
          // series->append("Engagement", affect[3]);
             series->append("Fear", affect[4]);
             series->append("Joy", affect[5]);
             series->append("Sadness", affect[6]);
             series->append("Surprise", affect[7]);

             ui->chartWidget->setRenderHint(QPainter::Antialiasing);
             ui->chartWidget->chart()->setTitle("Emotions");
             ui->chartWidget->chart()->addSeries(series);
             ui->chartWidget->chart()->legend()->setAlignment(Qt::AlignLeft);
             ui->chartWidget->chart()->legend()->setFont(QFont("Arial", 18));



                     ui->HRWidget->addGraph();
                     ui->HRWidget->graph(0)->setPen(QPen(QColor(40,100,255)));
                     ui->HRWidget->addGraph();
                     ui->HRWidget->graph(1)->setPen(QPen(QColor(255,10,10)));

                     ui->HRWidget->graph(0)->setLineStyle(QCPGraph::lsLine);

                     QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
                     timeTicker->setTimeFormat("%h:%m:%s");
                     ui->HRWidget->xAxis->setTicker(timeTicker);
                     ui->HRWidget->axisRect()->setupFullAxesBox();
                     ui->HRWidget->yAxis->setRange(40, 200);
                     connect(ui->HRWidget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->HRWidget->xAxis2, SLOT(setRange(QCPRange)));
                     connect(ui->HRWidget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->HRWidget->yAxis2, SLOT(setRange(QCPRange)));



                     ui->GSRWidget->addGraph();
                     ui->GSRWidget->graph(0)->setPen(QPen(QColor(40,100,255)));
                     ui->GSRWidget->addGraph();
                     ui->GSRWidget->graph(1)->setPen(QPen(QColor(255,10,10)));
                     ui->GSRWidget->graph(0)->setLineStyle(QCPGraph::lsImpulse);
                     ui->GSRWidget->xAxis->setTicker(timeTicker);
                     ui->GSRWidget->axisRect()->setupFullAxesBox();
                     ui->GSRWidget->yAxis->setRange(0, 300);
                     connect(ui->GSRWidget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->GSRWidget->xAxis2, SLOT(setRange(QCPRange)));
                     connect(ui->GSRWidget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->GSRWidget->yAxis2, SLOT(setRange(QCPRange)));


                     ui->ValenceWidget->addGraph();
                     ui->ValenceWidget->graph(0)->setPen(QPen(QColor(40,100,255)));
                     ui->ValenceWidget->addGraph();
                     ui->ValenceWidget->graph(1)->setPen(QPen(QColor(255,10,10)));
                     ui->ValenceWidget->graph(0)->setLineStyle(QCPGraph::lsImpulse);
                     ui->ValenceWidget->xAxis->setTicker(timeTicker);
                     ui->ValenceWidget->axisRect()->setupFullAxesBox();
                     ui->ValenceWidget->yAxis->setRange(-100, 100);
                     connect(ui->ValenceWidget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->ValenceWidget->xAxis2, SLOT(setRange(QCPRange)));
                     connect(ui->ValenceWidget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->ValenceWidget->yAxis2, SLOT(setRange(QCPRange)));


                     dataTimer.start(0);
                     affectVector.resize(9);








}


DataCollectionDialog::~DataCollectionDialog()
{
    delete ui;
}



void DataCollectionDialog::incrementT(){
    t++;
    ui->picture->setPixmap(mypix[t]);
    //ui->label
}


void DataCollectionDialog::dataReceived(QVariant v, QString t)
{

    if (t=="pupil.1")
    {
     diameter_3d_1 = v.toMap().take("diameter_3d").toDouble();
     pupilCenterX1 = v.toMap().take("circle_3d").toMap().take("center").toList().at(0).toDouble();
     pupilCenterY1 = v.toMap().take("circle_3d").toMap().take("center").toList().at(1).toDouble();
     pupilCenterZ1 = v.toMap().take("circle_3d").toMap().take("center").toList().at(2).toDouble();
    }

    if (t=="pupil.0")
    {
    diameter_3d_0 = v.toMap().take("diameter_3d").toDouble();
    pupilCenterX0 = v.toMap().take("circle_3d").toMap().take("center").toList().at(0).toDouble();
    pupilCenterY0 = v.toMap().take("circle_3d").toMap().take("center").toList().at(1).toDouble();
    pupilCenterZ0 = v.toMap().take("circle_3d").toMap().take("center").toList().at(2).toDouble();

    }

    if (t=="gaze")
    {

        gazeX = v.toMap().take("norm_pos").toList().at(0).toDouble();
        gazeY = v.toMap().take("norm_pos").toList().at(1).toDouble();

    }

    if (t=="")
    {

        if(v.toString().length() != 0)
        affectiva = v.toString();
        affect[0] = affectiva.split(" ").at(0).toDouble(); // anger
        affect[1] = affectiva.split(" ").at(1).toDouble(); // contempt
        affect[2] = affectiva.split(" ").at(2).toDouble(); // disgust
        affect[3] = affectiva.split(" ").at(3).toDouble(); // engagement
        affect[4] = affectiva.split(" ").at(4).toDouble(); // fear
        affect[5] = affectiva.split(" ").at(5).toDouble(); // joy
        affect[6] = affectiva.split(" ").at(6).toDouble(); // sadness
        affect[7] = affectiva.split(" ").at(7).toDouble(); // surprise
        affect[8] = affectiva.split(" ").at(8).toDouble(); // valence

    }



}


void DataCollectionDialog::handleReadyRead()
{
 m_readData.append(serial->readAll());
    if (!m_timer.isActive())
        m_timer.start(100);
}


void DataCollectionDialog::handleTimeout()
{
    if (m_readData.isEmpty()) {
        //qDebug() << QObject::tr("No data was currently available for reading from port %1").arg(serial->portName()) << endl;
    } else {
        //qDebug() << QObject::tr("Data successfully received from port %1").arg(serial->portName()) << endl;
       // qDebug(m_readData);

        if (QString(m_readData).length() != 0 &&  QString(m_readData).length() < 15)
        {

        arduino = QString(m_readData);
        if (arduino.split(":").length()==2){
            arduinoGSR = arduino.split(":").at(0).toDouble();
            arduinoHR = arduino.split(":").at(1).toDouble();
        }
      //  qDebug() << arduinoGSR << " - " << arduinoHR << endl;


        }
        m_readData = "";

           }
}


void DataCollectionDialog::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::ReadError) {
        //qDebug(QObject::tr("An I/O error occurred while reading the data from port %1, error: %2").arg(serial->portName()).arg(serial->errorString()));
        //QCoreApplication::exit(1);
    }
}



void DataCollectionDialog::realTimeDataSlot()
{

    static QTime time(QTime::currentTime());
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey = 0;
    static double lastSecond = 0;
    if (key-lastPointKey > 0.05 && record) // at most add point every 50 ms
    {
      // add data to lines:


        QTextStream emotionStream( &emotion );


        emotionStream               << arduinoGSR << " " << arduinoHR << " " << affectiva << " " << pupilCenterX0 << " " << pupilCenterY0 << " " << pupilCenterZ0 << " " << pupilCenterX1 << " " << pupilCenterY1 << " " << pupilCenterZ1 << " " << diameter_3d_0 << " " <<  diameter_3d_1 << " " << gazeX << " " <<  gazeY  << " " << time.elapsed() << endl;

        angerSum += affect[0];
        contemptSum += affect[1];
        disgustSum += affect[2];
        engagementSum += affect[3];
        fearSum += affect[4];
        joySum += affect[5];
        sadnessSum += affect[6];
        surpriseSum += affect[7];
        valenceSum += affect[8];
        HRSum += arduinoHR;
        GSRSum += arduinoGSR;
        diameter0Sum += diameter_3d_0;
        diameter1Sum += diameter_3d_1;


        for (int i = 0; i<9; i++) affectVector[i].append(affect[i]);
        diameter0Vector.append(diameter_3d_0);
        diameter1Vector.append(diameter_3d_1);
        gsrVector.append(arduinoGSR);
        hrVector.append(arduinoHR);



        affectCount++;
        arduinoCount++;
        diameterCount++;



        series->clear();
        series->append("Anger", affect[0]);
        series->append("Contempt", affect[1]);
        series->append("Disgust", affect[2]);
        //series->append("Engagement", affect[3]);
        series->append("Fear", affect[4]);
        series->append("Joy", affect[5]);
        series->append("Sadness", affect[6]);
        series->append("Surprise", affect[7]);





      ui->HRWidget->graph(0)->addData(key, arduinoHR);
      ui->GSRWidget->graph(0)->addData(key, arduinoGSR);
      ui->ValenceWidget->graph(0)->addData(key, affect[8]);

      lastPointKey = key;
    }



    ui->HRWidget->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->HRWidget->replot();

    ui->GSRWidget->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->GSRWidget->replot();

    ui->ValenceWidget->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->ValenceWidget->replot();


}

void DataCollectionDialog::on_startButton_clicked()
{

    record = true;
    //timer->start(5000);

}

void DataCollectionDialog::on_pauseButton_clicked()
{
    if (record) {
        record = false;
        ui->pauseButton->setText("Unpause");
    }

    else {
        record = true;
        ui->pauseButton->setText("Pause");
    }
}

void DataCollectionDialog::on_statsButton_clicked()
{

    angerMean = angerSum / affectCount;
    contemptMean = contemptSum / affectCount;
    disgustMean = disgustSum / affectCount;
    engagementMean = engagementSum / affectCount;
    fearMean = fearSum / affectCount;
    joyMean = joySum / affectCount;
    sadnessMean = sadnessSum / affectCount;
    surpriseMean = surpriseSum / affectCount;
    valenceMean = valenceSum / affectCount;
    HRMean = HRSum / arduinoCount;
    GSRMean = GSRSum / arduinoCount;
    diameter0Mean = diameter0Sum / diameterCount;
    diameter1Mean = diameter1Sum / diameterCount;

    statsDialog *sd = new statsDialog(this,
                                      angerMean,
                                      contemptMean,
                                      disgustMean,
                                      engagementMean,
                                      fearMean,
                                      joyMean,
                                      sadnessMean,
                                      surpriseMean,
                                      valenceMean,
                                      HRMean,  GSRMean,  diameter0Mean, diameter1Mean, affectVector, hrVector,gsrVector,diameter0Vector,diameter1Vector

                                      );

    sd->exec();






}
