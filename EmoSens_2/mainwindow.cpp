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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer->start(5000);

    QBluetoothAddress remoteAddress("98:D3:32:70:8B:76");



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
        QStringList fileList;
        bool s;
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
    timer->start(1000);
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
ui->label->setPixmap( filelistinfo[ currentimage++].absoluteFilePath() );

}

void MainWindow::on_pauseButton_clicked()
{
    if (timer->isActive()) timer->stop();
    else timer->start(1000);
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
    MainWindow::startDeviceDiscovery();
}

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';
}
