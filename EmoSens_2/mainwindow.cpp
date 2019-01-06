#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QFileDialog"
#include "QDir"
#include "QKeyEvent"
#include "QtWidgets"
#include "QTimer"
#include "QThread"
#include "QtBluetooth"
#include "keypresseventfilter.h"
#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QDateTime>
#include <QList>
#include <QDebug>
#include <opencv2/opencv.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>


QList<QSerialPortInfo> list;

cv::VideoCapture cap(0); // the fist webcam connected to your PC
cv::Mat frame;

QString arduino = "";
QString filename="";
double arduinoGSR = 0.0;
QChar arduinoVal;
bool record = false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{



  //  KeyPressEventFilter *filter = new KeyPressEventFilter(this);
      // this->-installEventFilter(filter);

    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realTimeDataSlot()));

    QDateTime UTC(QDateTime::currentDateTimeUtc());
        QDateTime local(UTC);



         measurement.setFileName("emotion_" + local.toString() +".dat");
         measurement.open(QIODevice::ReadWrite);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer->start(5000);

   // QBluetoothAddress remoteAddress("98:D3:32:70:8B:76");



    const QString folderPath = QFileDialog::getExistingDirectory(this, tr("/home/tylnesh/devel/EmoSens/EmoSens_2/"));
    if(!folderPath.isEmpty())
    {

        QDir dir(folderPath);
        QStringList filter;
        filter << QLatin1String("*.png");
        filter << QLatin1String("*.jpeg");
        filter << QLatin1String("*.jpg");
        dir.setNameFilters(filter);
        filelistinfo = dir.entryInfoList();

        // Initialize sequence
        qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
        // ... Generate numbers from that sequence
       // qrand();





      //  for (int i=0; i<20; i++)
       // {
        //    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
         //   files[i]  =   (qrand() % ((filelistinfo.length() + 1) - 0) + 0);
          //  qDebug() << files[i];
       // }

        QStringList fileList;
        ui->setupUi(this);

       // bool s;
        /*foreach (const QFileInfo &fileinfo, filelistinfo) {
            QString imageFile = fileinfo.absoluteFilePath();
            //imageFile is the image path, just put your load image code here

            QPixmap pixmap(imageFile);
            ui->label->setPixmap(pixmap);
            ui->label->setMask(pixmap.mask());

            ui->label->show();

            //QTimer::singleShot(5000);
           // QThread::msleep(1);
*/





//qDebug()<< key;



        }
    //list = QSerialPortInfo::availablePorts();
    //QString str;
    //QDebug dStream(&str);
    //qDebug() << str;


    //
if (this->availablePorts().length()!=0)
{
    qDebug() << this->availablePorts().first();
        QStringList ports = this->availablePorts();

    serial= new QSerialPort();
    //serial->setPortName("/dev/ttyUSB0");
    serial->setPortName(ports.first());
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
           connect(&m_timer, &QTimer::timeout, this, &MainWindow::handleTimeout);
           m_timer.start(100);
           } else qDebug("Connection Error");


}









}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    ui->label->setScaledContents( true );

    ui->label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    timer->start(5000);
    record = true;
    dataTimer.start(0);
}



//int MainWindow::keyPressFilter(QKeyEvent *event){

//    switch (event->key()) {
//    case Qt::Key_Plus:  { return 1; break;}
//    case Qt::Key_Minus: { return -1; break;}
//    default: {return 0;}
//    }

//}

void MainWindow::update()
{
if (currentimage < filelistinfo.size())
{
    r = (qrand() % ((filelistinfo.length() + 1) - 0) + 0);
ui->label->setPixmap(
            filelistinfo[r
            //files[currentimage]
                ].absoluteFilePath() );
filename = filelistinfo[r].fileName();
qDebug() << filename;
arduinoVal = 0;
}
}

void MainWindow::on_pauseButton_clicked()
{
    if (timer->isActive()) { timer->stop();record = false; }
    else {timer->start(5000); record = true;}

}

void MainWindow::startDeviceDiscovery()
{

    // Create a discovery agent and connect to its signals
    QBluetoothDeviceDiscoveryAgent *discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

    // Start a discovery
    discoveryAgent->start();

    //...
}

void MainWindow::on_connectButton_clicked()
{
    //MainWindow::startDeviceDiscovery();
}

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setScaledContents( true );

    ui->label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    timer->start(1000);
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
                //qDebug()<< "Val: " << arduinoVal;
            }
            }
             //if (arduinoVal == "+") qDebug()<< "positive";
        }
      //  qDebug() << arduinoGSR << " - " << arduinoHR << endl;


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
    if (key-lastPointKey > 0.5 && record) // at most add point every 50 ms
    {
      // add data to lines:
        if (!cap.isOpened())
        {
            qDebug()<< "Webcam not detected!!!";

        }
        else{

        cap >> frame; // outputs the webcam image to a Mat
        cv::imshow("Webcam", frame); // displays the Mat
        if (cv::waitKey(30) >= 0) break;
      }


        QTextStream measurementStream( &measurement );


        measurementStream  << arduinoGSR << " " << arduinoVal << " " << filename << " " << time.elapsed() << endl;
        qDebug() << arduinoGSR << " " << arduinoVal << " " << filename << " " << time.elapsed() << endl;

      //  GSRSum += arduinoGSR;

       // arduinoCount++;

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
