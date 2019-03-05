#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QFileDialog"
#include "QDir"
#include "QKeyEvent"
#include "QtWidgets"
#include "QTimer"
#include "QThread"
//#include "QtBluetooth"
#include "keypresseventfilter.h"
#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QDateTime>
#include <QList>
#include <QDebug>

#include <QVariant>

#include <opencv2/opencv.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

#include <zmq.hpp>
#include <include/zhelpers.hpp>

#include "affectzmq.h"

#include <QCoreApplication>
#include <qtconcurrentrun.h>
#include <QThread>

//#ifndef QT_NO_CONCURRENT



QList<QSerialPortInfo> list;


QString arduino = "";
QString filename="";
double arduinoGSR = 0.0;
QChar arduinoVal;
bool record = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realTimeDataSlot()));
    QDateTime UTC(QDateTime::currentDateTimeUtc());
    QDateTime local(UTC);

    measurement.setFileName("measurement_" + local.toString() +".csv");
    measurement.open(QIODevice::ReadWrite);

    QTextStream measurementHeader( &measurement );
    measurementHeader << "Right eye Pupil Size;Left eye Pupil Size;GazeX;GazeY;GSR;Time" << endl;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    ui->label->setScaledContents( true );

    ui->label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

           if(ui->isArduino->isChecked())

           {
               serial= new QSerialPort();
               serial->setPortName(ui->arduinoBox->currentText());
                if (serial->open(QIODevice::ReadWrite))
                  {
                   serial->setBaudRate(QSerialPort::Baud9600);
                   serial->setDataBits(QSerialPort::Data8);
                   serial->setParity(QSerialPort::NoParity);
                   serial->setStopBits(QSerialPort::OneStop);
                   serial->setFlowControl(QSerialPort::NoFlowControl);
                  qDebug("Connection established");


                   connect(serial, &QSerialPort::readyRead, this, &MainWindow::handleReadyRead);
                   connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
                                   this, &MainWindow::handleError);

                   } else qDebug("Connection Error");
    }


    connect(&m_timer, &QTimer::timeout, this, &MainWindow::handleTimeout);
    m_timer.start(100);
    timer->start(5000);
    record = true;
    dataTimer.start(0);

    ui->startButton->setVisible(false);
    ui->pauseButton->setEnabled(true);



}



void MainWindow::on_pauseButton_clicked()
{
    if (timer->isActive()) { timer->stop();record = false; }
    else {timer->start(5000); record = true;}
}


void MainWindow::on_connectButton_clicked()
{
    QString address;
     try{
     nzmqt::ZMQContext* context = nzmqt::createDefaultContext(this);
     //context.
     zmq::context_t contextPort (1);

     if(ui->isPupil->isChecked()) {
             zmq::socket_t req (contextPort, ZMQ_REQ);
             QString ipString = "tcp://127.0.0.1:50020";
             req.connect(ipString.toStdString());

    ////          // Ask for the subport
     zmq::message_t subPortRequest (8);
     memcpy (subPortRequest.data(), "SUB_PORT", 8);
     req.send(subPortRequest);
     zmq::message_t reply;
     req.recv(&reply);

    QString sub_port = QString::fromStdString(std::string(static_cast<char*>(reply.data()), reply.size()));
     context->start();
     address = "tcp://127.0.0.1:"+sub_port;

     nzmqtSubscriber* sub0 = new nzmqtSubscriber(*context, address, "pupil.0", this );
     nzmqtSubscriber* sub1 = new nzmqtSubscriber(*context, address, "pupil.1", this );
     nzmqtSubscriber* sub2 = new nzmqtSubscriber(*context, address, "gaze", this );

     context->start();

     connect(sub0, SIGNAL(extractData(QVariant, QString)),this,SLOT(dataReceived(QVariant,QString)));
     connect(sub1, SIGNAL(extractData(QVariant,QString)),this,SLOT(dataReceived(QVariant,QString)));
     connect(sub2, SIGNAL(extractData(QVariant,QString)),this,SLOT(dataReceived(QVariant,QString)));

     sub0->startImpl();
     sub1->startImpl();
     sub2->startImpl();

     }
    }catch (std::exception& ex)
        {
            qWarning() << ex.what();
            exit(-1);}


}



void MainWindow::handleReadyRead()
{
 m_readData.append(serial->readAll());
    if (!m_timer.isActive())
        m_timer.start(100);
}


void MainWindow::handleTimeout()
{
    if (m_readData.isEmpty()) {
        //qDebug() << QObject::tr("No data was currently available for reading from port %1").arg(serial->portName()) << endl;
    } else {
        //qDebug() << QObject::tr("Data successfully received from port %1").arg(serial->portName()) << endl;
        //qDebug(m_readData);

        if (QString(m_readData).length() != 0 &&  QString(m_readData).length() < 15)
        {

        arduino = QString(m_readData);
        if (arduino.split(":").length()==2){
            arduinoGSR = arduino.split(":").at(0).toDouble();
            //qDebug()<< "GSR: " << arduinoGSR;
            if (arduino.split(":").at(1)>0)
            {
                if (arduino.split(":").at(1).at(0) == "+" || arduino.split(":").at(1).at(0) == "-")
                {    arduinoVal = arduino.split(":").at(1).at(0);
                qDebug()<< "Val: " << arduinoVal;
            }
            }
         }
        }
        m_readData = "";

           }
}


void MainWindow::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::ReadError) {
        //qDebug(QObject::tr("An I/O error occurred while reading the data from port %1, error: %2").arg(serial->portName()).arg(serial->errorString()));
        //QCoreApplication::exit(1);
    }
}



void MainWindow::realTimeDataSlot()
{

    static QTime time(QTime::currentTime());
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey = 0;
    static double lastSecond = 0;
    if (key - lastPointKey > 0.01 && record) // at most add point every 10 ms
    {

        QTextStream measurementStream( &measurement );

        measurementStream << diameter_3d_0 << ";"  << diameter_3d_1 << ";"  << gazeX << ";" << gazeY << ";" << arduinoGSR << ";"  << time.currentTime().toString() << endl;
        qDebug() << arduinoGSR << " " << time.currentTime().toString() << endl;

        lastPointKey = key;
    }





}

QStringList MainWindow::availablePorts()
{
    QStringList ports;

    for (QSerialPortInfo port : QSerialPortInfo::availablePorts())
    {
        //Their is some sorting to do for just list the port I want, with vendor Id & product Id
        //qDebug() << port.portName();
        //<< port.vendorIdentifier() << port.productIdentifier()
        //<< port.hasProductIdentifier() << port.hasVendorIdentifier() << port.isBusy();
        ports += port.portName();
    }
    return ports;
}

void MainWindow::on_isArduino_stateChanged(int arg1)
{
    //qDebug() << arg1;

    if (this->availablePorts().length()!=0 && arg1)
    {
        qDebug() << this->availablePorts();
            QStringList ports = this->availablePorts();

            ui->arduinoBox->addItems(ports);




    }
    else ui->arduinoBox->clear();

}


void MainWindow::dataReceived(QVariant v, QString t)
{
//qDebug() << " rubbish received";
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


}
