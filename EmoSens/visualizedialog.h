#ifndef VISUALIZEDIALOG_H
#define VISUALIZEDIALOG_H

#include <QDialog>
#include <QFile>
#include <QtCharts>
#include "qcustomplot.h"


namespace Ui {
class visualizeDialog;
}

class visualizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit visualizeDialog(QWidget *parent = 0);
    ~visualizeDialog();

private slots:
    void on_loadButton_clicked();

    void on_graphComboBox_activated(int index);

    void on_angerCheckBox_stateChanged(int arg1);

    void on_contemptCheckBox_stateChanged(int arg1);

    void on_disgustCheckBox_stateChanged(int arg1);

    void on_engagementCheckBox_stateChanged(int arg1);

    void on_fearCheckBox_stateChanged(int arg1);

    void on_joyCheckBox_stateChanged(int arg1);

    void on_sadnessCheckBox_stateChanged(int arg1);

    void on_surpriseCheckBox_stateChanged(int arg1);

    void on_valenceCheckBox_stateChanged(int arg1);

    void on_gsrCheckBox_stateChanged(int arg1);

    void on_hrCheckBox_stateChanged(int arg1);

    void on_diameter0CheckBox_stateChanged(int arg1);

    void on_diameter1CheckBox_stateChanged(int arg1);

    void horzScrollBarChanged(int value);

    void xAxisChanged(QCPRange range);

private:
    Ui::visualizeDialog *ui;
    QFile file;
    QVector<QVector<double>> affectVector ;
    QVector<double> HRVector;
    QVector<double> GSRVector;
    QVector<double> diameter0Vector;
    QVector<double> diameter1Vector;


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

    QBarSeries *barseries;
    QLineSeries *lineseries;


};

#endif // VISUALIZEDIALOG_H
