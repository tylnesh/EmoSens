#include "visualizedialog.h"
#include "ui_visualizedialog.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QVector>
#include <QtCharts>
#include <qcustomplot.h>

//QVector<QVector<double>> affectVector (9, QVector<double> (0));


visualizeDialog::visualizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::visualizeDialog)
{
    ui->setupUi(this);
    ui->horizontalScrollBar->setVisible(false);

    //QString filename = QFileDialog::getOpenFileName(this, tr("Open data file"), "$HOME/output/", tr("Text Files (*.dat *.txt *.csv)"));
}

visualizeDialog::~visualizeDialog()
{
    delete ui;
}

void visualizeDialog::on_loadButton_clicked()
{
   // QString filename = QFileDialog::getOpenFileName(this, tr("Open data file"), "$HOME/output/", tr("Text Files (*.dat *.txt *.csv)"));
    file.setFileName(QFileDialog::getOpenFileName(this, tr("Open file"), "../output", tr("Text Files (*.dat *.txt *.csv)")));
   // file.open(QIODevice::ReadOnly);


   // QVector<QVector<double>> affectVector (9, QVector<double> (0));

     affectVector.resize(9);

     //affectVector.append(QVector<double>);
     //affectVector.append();

    //affectVector = new QVector<QVector<double>>(9);

    if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          GSRVector.append(line.split(" ").at(0).toDouble());
          GSRSum += line.split(" ").at(0).toDouble();

          HRVector.append(line.split(" ").at(1).toDouble());
          HRSum += line.split(" ").at(1).toDouble();

          affectVector[0].append(line.split(" ").at(2).toDouble());
          angerSum += line.split(" ").at(2).toDouble();

          affectVector[1].append(line.split(" ").at(3).toDouble());
          contemptSum += line.split(" ").at(3).toDouble();

          affectVector[2].append(line.split(" ").at(4).toDouble());
          disgustSum += line.split(" ").at(4).toDouble();

          affectVector[3].append(line.split(" ").at(5).toDouble());
          engagementSum += line.split(" ").at(5).toDouble();

          affectVector[4].append(line.split(" ").at(6).toDouble());
          fearSum += line.split(" ").at(6).toDouble();

          affectVector[5].append(line.split(" ").at(7).toDouble());
          joySum += line.split(" ").at(7).toDouble();

          affectVector[6].append(line.split(" ").at(8).toDouble());
          sadnessSum += line.split(" ").at(8).toDouble();

          affectVector[7].append(line.split(" ").at(9).toDouble());
          surpriseSum += line.split(" ").at(9).toDouble();

          affectVector[8].append(line.split(" ").at(10).toDouble());
          valenceSum += line.split(" ").at(10).toDouble();


          // 11 - 16 are pupil center positions and gaze positions.
          // TODO - add changes of position of gaze and pupil to visualization.

          diameter0Vector.append(line.split(" ").at(17).toDouble()*10);
          diameter0Sum += line.split(" ").at(17).toDouble();

          diameter0Vector.append(line.split(" ").at(18).toDouble()*10);
          diameter1Sum += line.split(" ").at(18).toDouble();

       }
       file.close();

       GSRMean = GSRSum / GSRVector.length();
       HRMean = HRSum / HRVector.length();

       angerMean = angerSum / affectVector[0].length();
       contemptMean = contemptSum / affectVector[1].length();
       disgustMean = disgustSum / affectVector[2].length();
       engagementMean = engagementSum / affectVector[3].length();
       fearMean = fearSum / affectVector[4].length();
       joyMean = joySum / affectVector[5].length();
       sadnessMean = sadnessSum / affectVector[6].length();
       surpriseMean = surpriseSum / affectVector[7].length();
       valenceMean = valenceSum / affectVector[8].length();

       diameter0Mean = diameter0Sum / diameter0Vector.length();
       diameter1Mean = diameter1Sum / diameter1Vector.length();

       //qDebug() << engagementSum;


       QBarSet *set0 = new QBarSet("Anger");
       QBarSet *set1 = new QBarSet("Contempt");
       QBarSet *set2 = new QBarSet("Disgust");
       QBarSet *set3 = new QBarSet("Engagement");
       QBarSet *set4 = new QBarSet("Fear");
       QBarSet *set5 = new QBarSet("Joy");
       QBarSet *set6 = new QBarSet("Sadness");
       QBarSet *set7 = new QBarSet("Surprise");
       QBarSet *set8 = new QBarSet("Valence");


       qDebug() << GSRMean;

       qDebug() << angerMean;
       qDebug() << contemptMean;
       qDebug() << disgustMean;
       qDebug() << engagementMean;
       qDebug() << fearMean;
       qDebug() << joyMean;
       qDebug() << sadnessMean;
       qDebug() << surpriseMean;
       qDebug() << valenceMean;

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
       //ui->barChartWidget->chart()->setTheme(QChart::ChartThemeHighContrast);
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

       ui->lineChartWidget->yAxis->setRange(0, 200,Qt::AlignCenter);



       //qDebug() << gsrSum;
    }
}

    void visualizeDialog::on_graphComboBox_activated(int index)
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

            ui->lineChartWidget->yAxis->setRange(0, 200,Qt::AlignJustify);
            ui->lineChartWidget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignBottom);
            //ui->lineChartWidget->axisRect()->insetLayout()->

            ui->lineChartWidget->replot();
            break;

        }

    }

    void visualizeDialog::on_angerCheckBox_stateChanged(int arg1)
    {

        if (arg1 == 0) { ui->lineChartWidget->graph(0)->setVisible(false); ui->lineChartWidget->legend->elementAt(0)->setVisible(false); }
        if (arg1 == 2) { ui->lineChartWidget->graph(0)->setVisible(true); ui->lineChartWidget->legend->elementAt(0)->setVisible(true); }

        ui->lineChartWidget->replot();
        //ui->lineChartWidget->legend->elementAt(0)->setVisible(false);
        //qDebug() << arg1;
    }

    void visualizeDialog::on_contemptCheckBox_stateChanged(int arg1)
    {
        if (arg1 == 0) ui->lineChartWidget->graph(1)->setVisible(false);
        if (arg1 == 2) ui->lineChartWidget->graph(1)->setVisible(true);
         ui->lineChartWidget->replot();
    }

    void visualizeDialog::on_disgustCheckBox_stateChanged(int arg1)
    {
        if (arg1 == 0) ui->lineChartWidget->graph(2)->setVisible(false);
        if (arg1 == 2) ui->lineChartWidget->graph(2)->setVisible(true);
         ui->lineChartWidget->replot();
    }

    void visualizeDialog::on_engagementCheckBox_stateChanged(int arg1)
    {
        if (arg1 == 0) ui->lineChartWidget->graph(3)->setVisible(false);
        if (arg1 == 2) ui->lineChartWidget->graph(3)->setVisible(true);
         ui->lineChartWidget->replot();
    }

    void visualizeDialog::on_fearCheckBox_stateChanged(int arg1)
    {
        if (arg1 == 0) ui->lineChartWidget->graph(4)->setVisible(false);
        if (arg1 == 2) ui->lineChartWidget->graph(4)->setVisible(true);
         ui->lineChartWidget->replot();
    }

    void visualizeDialog::on_joyCheckBox_stateChanged(int arg1)
    {
        if (arg1 == 0) ui->lineChartWidget->graph(5)->setVisible(false);
        if (arg1 == 2) ui->lineChartWidget->graph(5)->setVisible(true);
         ui->lineChartWidget->replot();
    }

    void visualizeDialog::on_sadnessCheckBox_stateChanged(int arg1)
    {
        if (arg1 == 0) ui->lineChartWidget->graph(6)->setVisible(false);
        if (arg1 == 2) ui->lineChartWidget->graph(6)->setVisible(true);
         ui->lineChartWidget->replot();
    }

    void visualizeDialog::on_surpriseCheckBox_stateChanged(int arg1)
    {
        if (arg1 == 0) ui->lineChartWidget->graph(7)->setVisible(false);
        if (arg1 == 2) ui->lineChartWidget->graph(7)->setVisible(true);
         ui->lineChartWidget->replot();
    }

    void visualizeDialog::on_valenceCheckBox_stateChanged(int arg1)
    {
        if (arg1 == 0) ui->lineChartWidget->graph(8)->setVisible(false);
        if (arg1 == 2) ui->lineChartWidget->graph(8)->setVisible(true);
         ui->lineChartWidget->replot();
    }

    void visualizeDialog::on_gsrCheckBox_stateChanged(int arg1)
    {
        if (arg1 == 0) ui->lineChartWidget->graph(9)->setVisible(false);
        if (arg1 == 2) ui->lineChartWidget->graph(9)->setVisible(true);
         ui->lineChartWidget->replot();
    }

    void visualizeDialog::on_hrCheckBox_stateChanged(int arg1)
    {
        if (arg1 == 0) ui->lineChartWidget->graph(10)->setVisible(false);
        if (arg1 == 2) ui->lineChartWidget->graph(10)->setVisible(true);
         ui->lineChartWidget->replot();
    }

    void visualizeDialog::on_diameter0CheckBox_stateChanged(int arg1)
    {
        if (arg1 == 0) ui->lineChartWidget->graph(11)->setVisible(false);
        if (arg1 == 2) ui->lineChartWidget->graph(11)->setVisible(true);
         ui->lineChartWidget->replot();
    }

    void visualizeDialog::on_diameter1CheckBox_stateChanged(int arg1)
    {
        if (arg1 == 0) ui->lineChartWidget->graph(12)->setVisible(false);
        if (arg1 == 2) ui->lineChartWidget->graph(12)->setVisible(true);
         ui->lineChartWidget->replot();
    }

    void visualizeDialog::horzScrollBarChanged(int value)
    {
      if (qAbs(ui->lineChartWidget->xAxis->range().center()-value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
      {
        ui->lineChartWidget->xAxis->setRange(value/100.0, ui->lineChartWidget->xAxis->range().size(), Qt::AlignCenter);

        ui->lineChartWidget->replot();
      }
    }



    void visualizeDialog::xAxisChanged(QCPRange range)
    {
      ui->horizontalScrollBar->setValue(qRound(range.center()*100.0)); // adjust position of scroll bar slider
      ui->horizontalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
    }


void visualizeDialog::on_exportButton_clicked()
{
    ui->lineChartWidget->savePng("export.png");
}
