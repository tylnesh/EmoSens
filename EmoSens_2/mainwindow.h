#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QFileInfoList>
#include <QtBluetooth>
#include <global.h>
#include <QSerialPort>

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
    int r;
    QFile measurement   ;

    ~MainWindow();

public slots:
    void handleReadyRead();
       void handleTimeout();
       void handleError(QSerialPort::SerialPortError error);

private slots:
    void on_startButton_clicked();
    void update();

    void on_pauseButton_clicked();

    void on_connectButton_clicked();
    void deviceDiscovered(const QBluetoothDeviceInfo &device);
    void realTimeDataSlot();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void startDeviceDiscovery();
    QSerialPort *serial;
    QStringList availablePorts();



    // Create the transfer request and file to be sent

};

#endif // MAINWINDOW_H
