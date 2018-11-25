#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QFileInfoList>
#include <QtBluetooth>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QTimer *timer;
    int currentimage = 0;
    QFileInfoList filelistinfo;
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void update();

    void on_pauseButton_clicked();

    void on_connectButton_clicked();
    void deviceDiscovered(const QBluetoothDeviceInfo &device);

private:
    Ui::MainWindow *ui;
    void startDeviceDiscovery();

    // Create the transfer request and file to be sent

};

#endif // MAINWINDOW_H
