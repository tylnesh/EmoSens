/********************************************************************************
** Form generated from reading UI file 'datacollectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATACOLLECTIONDIALOG_H
#define UI_DATACOLLECTIONDIALOG_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_DataCollectionDialog
{
public:
    QLabel *picture;
    QPushButton *startButton;
    QtCharts::QChartView *chartWidget;
    QCustomPlot *HRWidget;
    QCustomPlot *GSRWidget;
    QCustomPlot *ValenceWidget;
    QPushButton *pauseButton;
    QPushButton *statsButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *DataCollectionDialog)
    {
        if (DataCollectionDialog->objectName().isEmpty())
            DataCollectionDialog->setObjectName(QStringLiteral("DataCollectionDialog"));
        DataCollectionDialog->resize(1920, 1080);
        picture = new QLabel(DataCollectionDialog);
        picture->setObjectName(QStringLiteral("picture"));
        picture->setGeometry(QRect(10, 80, 1280, 720));
        startButton = new QPushButton(DataCollectionDialog);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(10, 10, 174, 42));
        chartWidget = new QtCharts::QChartView(DataCollectionDialog);
        chartWidget->setObjectName(QStringLiteral("chartWidget"));
        chartWidget->setGeometry(QRect(10, 140, 1811, 651));
        HRWidget = new QCustomPlot(DataCollectionDialog);
        HRWidget->setObjectName(QStringLiteral("HRWidget"));
        HRWidget->setGeometry(QRect(10, 840, 591, 211));
        GSRWidget = new QCustomPlot(DataCollectionDialog);
        GSRWidget->setObjectName(QStringLiteral("GSRWidget"));
        GSRWidget->setGeometry(QRect(620, 840, 591, 211));
        ValenceWidget = new QCustomPlot(DataCollectionDialog);
        ValenceWidget->setObjectName(QStringLiteral("ValenceWidget"));
        ValenceWidget->setGeometry(QRect(1230, 840, 591, 211));
        pauseButton = new QPushButton(DataCollectionDialog);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setGeometry(QRect(250, 10, 174, 42));
        statsButton = new QPushButton(DataCollectionDialog);
        statsButton->setObjectName(QStringLiteral("statsButton"));
        statsButton->setGeometry(QRect(510, 10, 174, 42));
        label = new QLabel(DataCollectionDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 800, 151, 31));
        QFont font;
        font.setPointSize(22);
        label->setFont(font);
        label_2 = new QLabel(DataCollectionDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(620, 800, 311, 31));
        label_2->setFont(font);
        label_3 = new QLabel(DataCollectionDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1230, 800, 231, 31));
        label_3->setFont(font);

        retranslateUi(DataCollectionDialog);

        QMetaObject::connectSlotsByName(DataCollectionDialog);
    } // setupUi

    void retranslateUi(QDialog *DataCollectionDialog)
    {
        DataCollectionDialog->setWindowTitle(QApplication::translate("DataCollectionDialog", "Dialog", nullptr));
        picture->setText(QString());
        startButton->setText(QApplication::translate("DataCollectionDialog", "Start", nullptr));
        pauseButton->setText(QApplication::translate("DataCollectionDialog", "Pause", nullptr));
        statsButton->setText(QApplication::translate("DataCollectionDialog", "Show stats", nullptr));
        label->setText(QApplication::translate("DataCollectionDialog", "Heart Rate", nullptr));
        label_2->setText(QApplication::translate("DataCollectionDialog", "Galvanic Skin Response", nullptr));
        label_3->setText(QApplication::translate("DataCollectionDialog", "Emotion valence", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataCollectionDialog: public Ui_DataCollectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATACOLLECTIONDIALOG_H
