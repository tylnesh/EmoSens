#ifndef STATSDIALOG_H
#define STATSDIALOG_H

#include <QDialog>
#include <QtCharts>
#include <QVector>
#include "qcustomplot.h"

namespace Ui {
class statsDialog;
}

class statsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit statsDialog(QWidget *parent = 0,
                         double angerMean = 0,
                         double contemptMean =0,
                         double disgustMean =0,
                         double engagementMean = 0,
                         double fearMean =0,
                         double joyMean = 0,
                         double sadnessMean =0,
                         double surpriseMean =0,
                         double valenceMean = 0,
                         double HRMean = 0,
                         double GSRMean =0,
                         double diameter0Mean = 0,
                         double diameter1Mean =0,
                         QVector<QVector<double>> affectVector = QVector<QVector<double>>(),
                         QVector<double> HRVector = QVector<double>(),
                         QVector<double> GSRVector = QVector<double>(),
                         QVector<double> diameter0Vector = QVector<double>(),
                         QVector<double> diameter1Vector = QVector<double>()

            );


    ~statsDialog();

private slots:
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
    Ui::statsDialog *ui;
    QBarSeries *barseries;
    QLineSeries *lineseries;
};

#endif // STATSDIALOG_H
