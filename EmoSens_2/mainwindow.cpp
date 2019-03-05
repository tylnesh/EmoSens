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



//void affectiva(QString address)
//{
//   // for(int i = 0; i <= 5; i++)
//  //  {
//       // qDebug() << address << " " << i <<
//         //           "from" << QThread::currentThread();
//   // }

//    zmq::context_t contextAffectiva(1);
//                zmq::socket_t subscriber (contextAffectiva, ZMQ_SUB);
//                subscriber.connect("tcp://localhost:5555");
//                subscriber.setsockopt( ZMQ_SUBSCRIBE, "aff", 3);

//                //for(int i =0; i++; i<100)

//                while(true){

//                    //  Read envelope with address
//                    QString add =  QString::fromStdString(s_recv (subscriber));
//                    //  Read message contents
//                    QString contents =  QString::fromStdString(s_recv (subscriber));

//                    qDebug() << "[" << add << "] " << contents << endl;
//              }


//}

QList<QSerialPortInfo> list;

//cv::VideoCapture cap(0); // the fist webcam connected to your PC
//cv::Mat frame;


 //update;
 //context(1);
 //socket (context, ZMQ_SUB);




QString arduino = "";
QString filename="";
double arduinoGSR = 0.0;
QChar arduinoVal;
bool record = false;
QString affectiva_data = "0;0;0;0;0;0;0;0;0;";
zmq::context_t contextAffectiva(1);
zmq::socket_t subscriber (contextAffectiva, ZMQ_SUB);


QVector<int> v;
QFile f("rating_images.txt");




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    //qDebug() << "Rating file lines: " << f. << endl;

    v.reserve(1000);
    if(f.open(QIODevice::ReadOnly))
    {
        int d;
        QTextStream ts(&f);
        while(!ts.atEnd())
        {
            ts >> d;
            //qDebug() << ts.status();
            if(ts.status() == QTextStream::Ok)
                v.append(d);
            else
                break;
        }
    qDebug() << "Rating file length: " << v.length() << endl;

    qDebug() << "Rating file content: " << v << endl;
    }
    else //could not open file
    {
        qDebug() << "Could not open Rating file";
    }

    //std::cout << "Connecting to  server…" << std::endl;
    //socket.connect ("tcp://localhost:5555");
    //if (socket.connected()) qDebug() << "Connected";

  //  KeyPressEventFilter *filter = new KeyPressEventFilter(this);
      // this->-installEventFilter(filter);

    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realTimeDataSlot()));

    QDateTime UTC(QDateTime::currentDateTimeUtc());
        QDateTime local(UTC);



         measurement.setFileName("emotion_" + local.toString() +".csv");
         measurement.open(QIODevice::ReadWrite);


         QTextStream measurementHeader( &measurement );
        measurementHeader << "joy;fear;disgust;sadness;anger;surprise;contempt;valence;engagement;Right eye;Left eye;GSR;Valence;Picture;Picture Valence;Time Elapsed" << endl;




    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer->start(5000);

   // QBluetoothAddress remoteAddress("98:D3:32:70:8B:76");


//    try{

//        nzmqt::ZMQContext* context = nzmqt::createDefaultContext(this);

//        QString address = "tcp://127.0.0.1:5555";
//        nzmqtSubscriber* affect = new nzmqtSubscriber(*context, address, "aff", this);
//        connect(affect, SIGNAL(extractData(QVariant,QString)),this,SLOT(dataReceived(QVariant,QString)));
//        affect->startImpl();
//    }catch (std::exception& ex)
//    {
//        qWarning() << ex.what();
//        exit(-1);}


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
            //serial->setPortNastd::memcpy (message.data(), data, size);me("/dev/ttyUSB0");
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
                   connect(&m_timer, &QTimer::timeout, this, &MainWindow::handleTimeout);
                   m_timer.start(100);
                   } else qDebug("Connection Error");
    }



    timer->start(5000);
    record = true;
    dataTimer.start(0);

    ui->startButton->setVisible(false);
     ui->pauseButton->setEnabled(true);



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
    //QBluetoothDeviceDiscoveryAgent *discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
   // connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
    //        this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

    // Start a discovery
   // discoveryAgent->start();

    //...
}

void MainWindow::on_connectButton_clicked()
{
    QString address;
     try{
     address= "tcp://192.168.1.21:5555";
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
    //qDebug() << sub_port;
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

     if (ui->isAffectiva->isChecked()) {

           //QFuture<void> t1 = QtConcurrent::run(affectiva, QString("127.0.0.1:5555"));
           //t1.waitForFinished();


                     subscriber.connect("tcp://localhost:5555");
                     subscriber.setsockopt( ZMQ_SUBSCRIBE, "aff", 3);


         //t1.begin();

  //       address = "tcp://127.0.0.1:5555";
//         nzmqtSubscriber* affect = new nzmqtSubscriber(*context, address, "aff", this);
//         connect(affect, SIGNAL(extractData(QVariant,QString)),this,SLOT(dataReceived(QVariant,QString)));
//         affect->startImpl();
//     }

//AffectZMQ affect(address);

//affect.run();

          //  qDebug() << "Connecting affectiva";
//             zmq::context_t contextAffectiva(1);
//             zmq::socket_t subscriber (contextAffectiva, ZMQ_SUB);
//             subscriber.connect("tcp://localhost:5555");
//             subscriber.setsockopt( ZMQ_SUBSCRIBE, "aff", 3);

//             //for(int i =0; i++; i<100)

//             while(true){

//                 //  Read envelope with address
//                 QString add =  QString::fromStdString(s_recv (subscriber));
//                 //  Read message contents
//                 QString contents =  QString::fromStdString(s_recv (subscriber));

//                 qDebug() << "[" << add << "] " << contents << endl;
//           }
}


}
//void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
//{
//    qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';
//}

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
                qDebug()<< "Val: " << arduinoVal;
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
//      // add data to lines:
//        if (!cap.isOpened())
//        {
//            qDebug()<< "Webcam not detected!!!";

//        }
//        else{

//        cap >> frame; // outputs the webcam image to a Mat
//        cv::imshow("Webcam", frame); // displays the Mat
//        //if (cv::waitKey(30) >= 0) break;
 //     }


        QTextStream measurementStream( &measurement );
        if(ui->isAffectiva) affectiva_data = QString::fromStdString(s_recv (subscriber));
        else affectiva_data = "0;0;0;0;0;0;0;0;0";

//        qDebug() << affectiva_data;

        //socket.recv(&update);
        //socket.recv(&emotions, sizeof(emotions),0);


        int v_val = v.at(r);
        measurementStream << affectiva_data << ";" << diameter_3d_0 << ";"  << diameter_3d_1   << ";"  << arduinoGSR << ";" << arduinoVal << ";" << filename << ";" << v_val << ";" << time.elapsed() << endl;
        qDebug() << arduinoGSR << " " << arduinoVal << " " << filename << " "<< v.at(r) <<" " << time.elapsed() << endl;

        //qDebug() << msg.data();
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

void MainWindow::on_selectButton_clicked()
{
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







        }

    if (filelistinfo.length()) {
        ui->startButton->setEnabled(true);

}

    qDebug() << filelistinfo.length();
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

    if (t=="affectiva")
    {


       // qDebug() << "decoding msg";
//        if(v.toString().length() != 0)
//        affectiva = v.toString();
//        affect[0] = affectiva.split(" ").at(0).toDouble(); // anger
//        affect[1] = affectiva.split(" ").at(1).toDouble(); // contempt
//        affect[2] = affectiva.split(" ").at(2).toDouble(); // disgust
//        affect[3] = affectiva.split(" ").at(3).toDouble(); // engagement
//        affect[4] = affectiva.split(" ").at(4).toDouble(); // fear
//        affect[5] = affectiva.split(" ").at(5).toDouble(); // joy
//        affect[6] = affectiva.split(" ").at(6).toDouble(); // sadness
//        affect[7] = affectiva.split(" ").at(7).toDouble(); // surprise
//        affect[8] = affectiva.split(" ").at(8).toDouble(); // valence

    }



}
