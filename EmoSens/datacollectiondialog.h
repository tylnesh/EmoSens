#ifndef DATACOLLECTIONDIALOG_H
#define DATACOLLECTIONDIALOG_H

#include <QDialog>
#include <QString>
#include <QPixmap>
#include <QVariant>
#include <QFile>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include <QTextStream>
#include <QtCharts>
#include "qcustomplot.h"
#include "statsdialog.h"

//#include <boost/filesystem.hpp>
//#include <boost/timer.hpp>
//#include <boost/algorithm/string.hpp>
//#include <boost/program_options.hpp>

namespace Ui {
class DataCollectionDialog;
}

class DataCollectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DataCollectionDialog(QWidget *parent = 0, const QString &ip = "127.0.0.1");
    ~DataCollectionDialog();

protected slots:
    void dataReceived(QVariant v, QString t);

private:


    Ui::DataCollectionDialog *ui;
    QString m_ip;
    QTimer *timer;
    QTimer dataTimer;

    QCustomPlot *HRWidget;
    QCustomPlot *GSRWidget;
    QCustomPlot *ValenceWidget;

    QSerialPort *serial;

    QLineSeries *gsrseries;
    QLineSeries *hrseries;
    QPieSeries *series;
    QPieSlice *slice;

    QByteArray  m_readData;
    QTextStream m_standardOutput;
    QTimer      m_timer;
    //QTimer      dataTimer;
    QString serialBuffer;

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

    double affect[9] = {0,0,0,0,0,0,0,0,0};


    double HRSum = 0;
    double GSRSum = 0;
    double diameter0Sum = 0;
    double diameter1Sum = 0;
    double angerSum = 0;
    double contemptSum =0;
    double disgustSum =0;
    double engagementSum = 0;
    double fearSum =0;
    double joySum = 0;
    double sadnessSum =0;
    double surpriseSum =0;
    double valenceSum = 0;



    //double affectMean[9] = {0,0,0,0,0,0,0,0,0};
    double HRMean = 0;
    double GSRMean = 0;
    double diameter0Mean = 0;
    double diameter1Mean = 0;
    double angerMean = 0;
    double contemptMean =0;
    double disgustMean =0;
    double engagementMean = 0;
    double fearMean =0;
    double joyMean = 0;
    double sadnessMean =0;
    double surpriseMean =0;
    double valenceMean = 0;

    double affectCount = 0;
    double arduinoCount = 0;
    double diameterCount = 0;





    //double diameterMean[2] = {0,0};

    QVector<double> hrVector;
    QVector<double> gsrVector;

    QVector<QString> timeVector;

    QVector<QVector<double>> affectVector;
    QVector<double> diameter0Vector;
    QVector<double> diameter1Vector;

    QPixmap mypix[32];

    int t=0;
    bool record = false;


    QFile emotion;



public slots:
    void handleReadyRead();
    void handleTimeout();
    void handleError(QSerialPort::SerialPortError error);

private slots:
    void realTimeDataSlot();
    void incrementT();
    void on_startButton_clicked();
    void on_pauseButton_clicked();
    void on_statsButton_clicked();
};

#endif // DATACOLLECTIONDIALOG_H
