#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QFileInfoList>
//#include <QtBluetooth>
#include <global.h>
#include <QSerialPort>

#include <zmq.hpp>
#include <nzmqtsubscriber.h>

#include <QVariant>

//extern int key;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QTimer *timer;
    QTimer m_timer;
    QTimer dataTimer;
    QByteArray  m_readData;
    int currentimage = 0;
    QFileInfoList filelistinfo;
    QFileInfoList randomfilelistinfo;
    int files[20];
    int r = 0;
    QFile measurement   ;



    double diameter_3d_1 =0;
    double diameter_3d_0 =0;

    double gazeX = 0;
    double gazeY = 0;

    double pupilCenterX0 = 0;
    double pupilCenterY0 = 0;
    double pupilCenterZ0 = 0;

    double pupilCenterX1 = 0;
    double pupilCenterY1 = 0;
    double pupilCenterZ1 = 0;


    ~MainWindow();

public slots:
    void handleReadyRead();
       void handleTimeout();
       void handleError(QSerialPort::SerialPortError error);
       void dataReceived(QVariant v, QString t);

private slots:
    void on_startButton_clicked();
    void update();

    void on_pauseButton_clicked();

    void on_connectButton_clicked();
    //void deviceDiscovered(const QBluetoothDeviceInfo &device);
    void realTimeDataSlot();
    void on_pushButton_clicked();

    void on_isArduino_stateChanged(int arg1);

    void on_selectButton_clicked();

protected slots:


private:
    Ui::MainWindow *ui;
    void startDeviceDiscovery();
    QSerialPort *serial;
    QStringList availablePorts();

    double emotions[9] = {0,0,0,0,0,0,0,0,0};
    zmq::message_t msg;
    zmq::context_t context = zmq::context_t(1) ;
    zmq::socket_t socket = zmq::socket_t(context, ZMQ_SUB);
    //QString affectiva_data;


    // Create the transfer request and file to be sent

};

#endif // MAINWINDOW_H
