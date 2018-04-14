#include "statsdialog.h"
#include "ui_statsdialog.h"
#include <QtCharts>
#include <QDebug>


statsDialog::statsDialog(QWidget *parent,
                         double angerMean,
                         double contemptMean,
                         double disgustMean,
                         double engagementMean,
                         double fearMean,
                         double joyMean,
                         double sadnessMean,
                         double surpriseMean,
                         double valenceMean,
                         double HRMean, double GSRMean, double diameter0Mean , double diameter1Mean, QVector<QVector<double>> affectVector, QVector<double> HRVector,
                         QVector<double> GSRVector,
                         QVector<double> diameter0Vector,
                         QVector<double> diameter1Vector) :
    QDialog(parent),
    ui(new Ui::statsDialog)
{
    ui->setupUi(this);

    QBarSet *set0 = new QBarSet("Anger");
    QBarSet *set1 = new QBarSet("Contempt");
    QBarSet *set2 = new QBarSet("Disgust");
    QBarSet *set3 = new QBarSet("Engagement");
    QBarSet *set4 = new QBarSet("Fear");
    QBarSet *set5 = new QBarSet("Joy");
    QBarSet *set6 = new QBarSet("Sadness");
    QBarSet *set7 = new QBarSet("Surprise");
    QBarSet *set8 = new QBarSet("Valence");


    *set0 << angerMean;
    *set1 << contemptMean;
    *set2 << disgustMean;
    *set3 << engagementMean;
    *set4 << fearMean;
    *set5 << joyMean;
    *set6 << sadnessMean;
    *set7 << surpriseMean;
    *set8 << valenceMean;

    barseries = new QBarSeries();
    barseries->append(set0);
    barseries->append(set1);
    barseries->append(set2);
    barseries->append(set3);
    barseries->append(set4);
    barseries->append(set5);
    barseries->append(set6);
    barseries->append(set7);
    barseries->append(set8);


    QStringList categories;
    categories << "Emotions";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    ui->barChartWidget->chart()->createDefaultAxes();
    ui->barChartWidget->chart()->setAxisX(axis, barseries);
    ui->barChartWidget->chart()->setVisible(true);
    ui->barChartWidget->chart()->legend()->setAlignment(Qt::AlignBottom);
    ui->barChartWidget->setRenderHint(QPainter::Antialiasing);
    ui->barChartWidget->chart()->setTitle("Emotions");
    ui->barChartWidget->chart()->addSeries(barseries);
    ui->barChartWidget->chart()->legend()->setAlignment(Qt::AlignBottom);
    //ui->chartWidget->chart()->legend()->setAlignment(Qt::AlignLeft);
    //ui->chartWidget->chart()->setTheme(QChart::ChartThemeBlueCerulean);
    ui->barChartWidget->chart()->setTheme(QChart::ChartThemeHighContrast);
    ui->barChartWidget->chart()->legend()->setFont(QFont("Arial", 18));



    QLineSeries *angerSeries = new QLineSeries();
    QLineSeries *contemptSeries = new QLineSeries();
    QLineSeries *disgustSeries = new QLineSeries();
    QLineSeries *engagementSeries = new QLineSeries();
    QLineSeries *fearSeries = new QLineSeries();
    QLineSeries *joySeries = new QLineSeries();
    QLineSeries *sadnessSeries = new QLineSeries();
    QLineSeries *surpriseSeries = new QLineSeries();
    QLineSeries *valenceSeries = new QLineSeries();

    QLineSeries *gsrSeries = new QLineSeries();
    QLineSeries *hrSeries = new QLineSeries();
    QLineSeries *d0Series = new QLineSeries();
    QLineSeries *d1Series = new QLineSeries();





    for (int i = 0; i< affectVector[0].length(); i++) angerSeries->append(i,affectVector[0].at(i));
    for (int i = 0; i< affectVector[1].length(); i++) contemptSeries->append(i,affectVector[1].at(i));
    for (int i = 0; i< affectVector[2].length(); i++) disgustSeries->append(i,affectVector[2].at(i));
    for (int i = 0; i< affectVector[3].length(); i++) engagementSeries->append(i,affectVector[3].at(i));
    for (int i = 0; i< affectVector[4].length(); i++) fearSeries->append(i,affectVector[4].at(i));
    for (int i = 0; i< affectVector[5].length(); i++) joySeries->append(i,affectVector[5].at(i));
    for (int i = 0; i< affectVector[6].length(); i++) sadnessSeries->append(i,affectVector[6].at(i));
    for (int i = 0; i< affectVector[7].length(); i++) surpriseSeries->append(i,affectVector[7].at(i));
    for (int i = 0; i< affectVector[8].length(); i++) valenceSeries->append(i,affectVector[8].at(i));

    for (int i = 0; i< GSRVector.length(); i++) gsrSeries->append(i,GSRVector.at(i));
    for (int i = 0; i< HRVector.length(); i++) hrSeries->append(i,HRVector.at(i));
    for (int i = 0; i< diameter0Vector.length(); i++) d0Series->append(i,diameter0Vector.at(i));
    for (int i = 0; i< diameter1Vector.length(); i++) d1Series->append(i,diameter1Vector.at(i));


    ui->lineChartWidget->legend->setVisible(true);
    QPen pen;

    ui->lineChartWidget->addGraph();
    pen.setColor(Qt::red);
    ui->lineChartWidget->graph(0)->setPen(pen);
    ui->lineChartWidget->graph(0)->setName("Anger");

    QVector<double> x;
    for (int i = 0; i<affectVector[0].length(); i++) x.append(i);
    ui->lineChartWidget->graph(0)->setData(x,affectVector[0]);

    ui->lineChartWidget->addGraph();
    pen.setColor(Qt::darkGreen);
    ui->lineChartWidget->graph(1)->setPen(pen);
    ui->lineChartWidget->graph(1)->setName("Contempt");
    ui->lineChartWidget->graph(1)->setData(x,affectVector[1]);
    ui->lineChartWidget->graph(1)->rescaleAxes(true);


    ui->lineChartWidget->addGraph();
    pen.setColor(Qt::green);
    ui->lineChartWidget->graph(2)->setPen(pen);
    ui->lineChartWidget->graph(2)->setName("Disgust");
    ui->lineChartWidget->graph(2)->setData(x,affectVector[2]);
    ui->lineChartWidget->graph(2)->rescaleAxes(true);


    ui->lineChartWidget->addGraph();
    pen.setColor(Qt::magenta);
    ui->lineChartWidget->graph(3)->setPen(pen);
    ui->lineChartWidget->graph(3)->setName("Engagement");
    ui->lineChartWidget->graph(3)->setData(x,affectVector[3]);
    ui->lineChartWidget->graph(3)->rescaleAxes(true);

    ui->lineChartWidget->addGraph();
    pen.setColor(Qt::yellow);
    ui->lineChartWidget->graph(4)->setPen(pen);
    ui->lineChartWidget->graph(4)->setName("Fear");
    ui->lineChartWidget->graph(4)->setData(x,affectVector[4]);
    ui->lineChartWidget->graph(4)->rescaleAxes(true);

    ui->lineChartWidget->addGraph();
    pen.setColor(Qt::darkMagenta);
    ui->lineChartWidget->graph(5)->setPen(pen);
    ui->lineChartWidget->graph(5)->setName("Joy");
    ui->lineChartWidget->graph(5)->setData(x,affectVector[5]);
    ui->lineChartWidget->graph(5)->rescaleAxes(true);

    ui->lineChartWidget->addGraph();
    pen.setColor(Qt::blue);
    ui->lineChartWidget->graph(6)->setPen(pen);
    ui->lineChartWidget->graph(6)->setName("Sadness");
    ui->lineChartWidget->graph(6)->setData(x,affectVector[6]);
    ui->lineChartWidget->graph(6)->rescaleAxes(true);

    ui->lineChartWidget->addGraph();
    pen.setColor(Qt::cyan);
    ui->lineChartWidget->graph(7)->setPen(pen);
    ui->lineChartWidget->graph(7)->setName("Surprise");
    ui->lineChartWidget->graph(7)->setData(x,affectVector[7]);
    ui->lineChartWidget->graph(7)->rescaleAxes(true);

    ui->lineChartWidget->addGraph();
    pen.setColor(Qt::black);
    ui->lineChartWidget->graph(8)->setPen(pen);
    ui->lineChartWidget->graph(8)->setName("Valence");
    ui->lineChartWidget->graph(8)->setData(x,affectVector[8]);
    ui->lineChartWidget->graph(8)->rescaleAxes(true);

    ui->lineChartWidget->addGraph();
    pen.setColor(QRgb(0xfaa43a));
    ui->lineChartWidget->graph(9)->setPen(pen);
    ui->lineChartWidget->graph(9)->setName("GSR");
    ui->lineChartWidget->graph(9)->setData(x,GSRVector);
    ui->lineChartWidget->graph(9)->rescaleAxes(true);

    ui->lineChartWidget->addGraph();
    pen.setColor(QRgb(0xf17cb0));
    ui->lineChartWidget->graph(10)->setPen(pen);
    ui->lineChartWidget->graph(10)->setName("HR");
    ui->lineChartWidget->graph(10)->setData(x,HRVector);
    ui->lineChartWidget->graph(10)->rescaleAxes(true);


    ui->lineChartWidget->addGraph();
    pen.setColor(QRgb(0xB276B2));
    ui->lineChartWidget->graph(11)->setPen(pen);
    ui->lineChartWidget->graph(11)->setName("Pupil 0");
    ui->lineChartWidget->graph(11)->setData(x,diameter0Vector);
    ui->lineChartWidget->graph(11)->rescaleAxes(true);

    ui->lineChartWidget->addGraph();
    pen.setColor(QRgb(0xB276B2));
    ui->lineChartWidget->graph(12)->setPen(pen);
    ui->lineChartWidget->graph(12)->setName("Pupil 1");
    ui->lineChartWidget->graph(12)->setData(x,diameter1Vector);
    ui->lineChartWidget->graph(12)->rescaleAxes(true);







//    customPlot->graph()->rescaleAxes(true);




//    ui->lineChartWidget->chart()->createDefaultAxes();



    ui->lineChartWidget->setVisible(false);


    ui->angerCheckBox->setVisible(false);
    ui->contemptCheckBox->setVisible(false);
    ui->disgustCheckBox->setVisible(false);
    ui->engagementCheckBox->setVisible(false);
    ui->fearCheckBox->setVisible(false);
    ui->joyCheckBox->setVisible(false);
    ui->sadnessCheckBox->setVisible(false);
    ui->surpriseCheckBox->setVisible(false);
    ui->valenceCheckBox->setVisible(false);

    ui->gsrCheckBox->setVisible(false);
    ui->hrCheckBox->setVisible(false);

    ui->diameter0CheckBox->setVisible(false);
    ui->diameter1CheckBox->setVisible(false);

    ui->line->setVisible(false);
    ui->line_2->setVisible(false);

    ui->horizontalScrollBar->setRange(0, affectVector.length()*1000);

    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(horzScrollBarChanged(int)));
    connect(ui->lineChartWidget->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
    ui->lineChartWidget->xAxis->setRange(0, 6, Qt::AlignLeft);


    //ui->horizontalScrollBar->setRange();
}

statsDialog::~statsDialog()
{
    delete ui;
}

void statsDialog::on_graphComboBox_activated(int index)
{
    switch (index){
    case 0:
        ui->lineChartWidget->setVisible(false);
        ui->barChartWidget->setVisible(true);

        ui->angerCheckBox->setVisible(false);
        ui->contemptCheckBox->setVisible(false);
        ui->disgustCheckBox->setVisible(false);
        ui->engagementCheckBox->setVisible(false);
        ui->fearCheckBox->setVisible(false);
        ui->joyCheckBox->setVisible(false);
        ui->sadnessCheckBox->setVisible(false);
        ui->surpriseCheckBox->setVisible(false);
        ui->valenceCheckBox->setVisible(false);

        ui->gsrCheckBox->setVisible(false);
        ui->hrCheckBox->setVisible(false);

        ui->diameter0CheckBox->setVisible(false);
        ui->diameter1CheckBox->setVisible(false);

        ui->line->setVisible(false);
        ui->line_2->setVisible(false);
        break;

    case 1:

        ui->lineChartWidget->setVisible(true);
        ui->barChartWidget->setVisible(false);

        ui->angerCheckBox->setVisible(true);
        ui->contemptCheckBox->setVisible(true);
        ui->disgustCheckBox->setVisible(true);
        ui->engagementCheckBox->setVisible(true);
        ui->fearCheckBox->setVisible(true);
        ui->joyCheckBox->setVisible(true);
        ui->sadnessCheckBox->setVisible(true);
        ui->surpriseCheckBox->setVisible(true);
        ui->valenceCheckBox->setVisible(true);

        ui->gsrCheckBox->setVisible(true);
        ui->hrCheckBox->setVisible(true);

        ui->diameter0CheckBox->setVisible(true);
        ui->diameter1CheckBox->setVisible(true);
        ui->line->setVisible(true);
        ui->line_2->setVisible(true);
        break;

    }

}

void statsDialog::on_angerCheckBox_stateChanged(int arg1)
{

    if (arg1 == 0) { ui->lineChartWidget->graph(0)->setVisible(false); ui->lineChartWidget->legend->elementAt(0)->setVisible(false); }
    if (arg1 == 2) { ui->lineChartWidget->graph(0)->setVisible(true); ui->lineChartWidget->legend->elementAt(0)->setVisible(true); }

    ui->lineChartWidget->replot();
    //ui->lineChartWidget->legend->elementAt(0)->setVisible(false);
    //qDebug() << arg1;
}

void statsDialog::on_contemptCheckBox_stateChanged(int arg1)
{
    if (arg1 == 0) ui->lineChartWidget->graph(1)->setVisible(false);
    if (arg1 == 2) ui->lineChartWidget->graph(1)->setVisible(true);
     ui->lineChartWidget->replot();
}

void statsDialog::on_disgustCheckBox_stateChanged(int arg1)
{
    if (arg1 == 0) ui->lineChartWidget->graph(2)->setVisible(false);
    if (arg1 == 2) ui->lineChartWidget->graph(2)->setVisible(true);
     ui->lineChartWidget->replot();
}

void statsDialog::on_engagementCheckBox_stateChanged(int arg1)
{
    if (arg1 == 0) ui->lineChartWidget->graph(3)->setVisible(false);
    if (arg1 == 2) ui->lineChartWidget->graph(3)->setVisible(true);
     ui->lineChartWidget->replot();
}

void statsDialog::on_fearCheckBox_stateChanged(int arg1)
{
    if (arg1 == 0) ui->lineChartWidget->graph(4)->setVisible(false);
    if (arg1 == 2) ui->lineChartWidget->graph(4)->setVisible(true);
     ui->lineChartWidget->replot();
}

void statsDialog::on_joyCheckBox_stateChanged(int arg1)
{
    if (arg1 == 0) ui->lineChartWidget->graph(5)->setVisible(false);
    if (arg1 == 2) ui->lineChartWidget->graph(5)->setVisible(true);
     ui->lineChartWidget->replot();
}

void statsDialog::on_sadnessCheckBox_stateChanged(int arg1)
{
    if (arg1 == 0) ui->lineChartWidget->graph(6)->setVisible(false);
    if (arg1 == 2) ui->lineChartWidget->graph(6)->setVisible(true);
     ui->lineChartWidget->replot();
}

void statsDialog::on_surpriseCheckBox_stateChanged(int arg1)
{
    if (arg1 == 0) ui->lineChartWidget->graph(7)->setVisible(false);
    if (arg1 == 2) ui->lineChartWidget->graph(7)->setVisible(true);
     ui->lineChartWidget->replot();
}

void statsDialog::on_valenceCheckBox_stateChanged(int arg1)
{
    if (arg1 == 0) ui->lineChartWidget->graph(8)->setVisible(false);
    if (arg1 == 2) ui->lineChartWidget->graph(8)->setVisible(true);
     ui->lineChartWidget->replot();
}

void statsDialog::on_gsrCheckBox_stateChanged(int arg1)
{
    if (arg1 == 0) ui->lineChartWidget->graph(9)->setVisible(false);
    if (arg1 == 2) ui->lineChartWidget->graph(9)->setVisible(true);
     ui->lineChartWidget->replot();
}

void statsDialog::on_hrCheckBox_stateChanged(int arg1)
{
    if (arg1 == 0) ui->lineChartWidget->graph(10)->setVisible(false);
    if (arg1 == 2) ui->lineChartWidget->graph(10)->setVisible(true);
     ui->lineChartWidget->replot();
}

void statsDialog::on_diameter0CheckBox_stateChanged(int arg1)
{
    if (arg1 == 0) ui->lineChartWidget->graph(11)->setVisible(false);
    if (arg1 == 2) ui->lineChartWidget->graph(11)->setVisible(true);
     ui->lineChartWidget->replot();
}

void statsDialog::on_diameter1CheckBox_stateChanged(int arg1)
{
    if (arg1 == 0) ui->lineChartWidget->graph(12)->setVisible(false);
    if (arg1 == 2) ui->lineChartWidget->graph(12)->setVisible(true);
     ui->lineChartWidget->replot();
}

void statsDialog::horzScrollBarChanged(int value)
{
  if (qAbs(ui->lineChartWidget->xAxis->range().center()-value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
  {
    ui->lineChartWidget->xAxis->setRange(value/100.0, ui->lineChartWidget->xAxis->range().size(), Qt::AlignCenter);
    ui->lineChartWidget->replot();
  }
}



void statsDialog::xAxisChanged(QCPRange range)
{
  ui->horizontalScrollBar->setValue(qRound(range.center()*100.0)); // adjust position of scroll bar slider
  ui->horizontalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}



