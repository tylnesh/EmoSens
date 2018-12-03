/********************************************************************************
** Form generated from reading UI file 'visualizedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALIZEDIALOG_H
#define UI_VISUALIZEDIALOG_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_visualizeDialog
{
public:
    QPushButton *loadButton;
    QWidget *widget;
    QtCharts::QChartView *barChartWidget;
    QCustomPlot *lineChartWidget;
    QCustomPlot *pupilChartWidget;
    QScrollBar *horizontalScrollBar;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *angerCheckBox;
    QCheckBox *contemptCheckBox;
    QCheckBox *disgustCheckBox;
    QCheckBox *engagementCheckBox;
    QCheckBox *fearCheckBox;
    QCheckBox *joyCheckBox;
    QCheckBox *sadnessCheckBox;
    QCheckBox *surpriseCheckBox;
    QCheckBox *valenceCheckBox;
    QFrame *line;
    QCheckBox *gsrCheckBox;
    QCheckBox *hrCheckBox;
    QFrame *line_2;
    QCheckBox *diameter0CheckBox;
    QCheckBox *diameter1CheckBox;
    QComboBox *graphComboBox;
    QPushButton *exportButton;

    void setupUi(QDialog *visualizeDialog)
    {
        if (visualizeDialog->objectName().isEmpty())
            visualizeDialog->setObjectName(QStringLiteral("visualizeDialog"));
        visualizeDialog->resize(1280, 720);
        loadButton = new QPushButton(visualizeDialog);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(1180, 10, 89, 25));
        widget = new QWidget(visualizeDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 1111, 691));
        barChartWidget = new QtCharts::QChartView(widget);
        barChartWidget->setObjectName(QStringLiteral("barChartWidget"));
        barChartWidget->setGeometry(QRect(0, 10, 1111, 681));
        lineChartWidget = new QCustomPlot(widget);
        lineChartWidget->setObjectName(QStringLiteral("lineChartWidget"));
        lineChartWidget->setGeometry(QRect(10, 0, 1101, 691));
        pupilChartWidget = new QCustomPlot(widget);
        pupilChartWidget->setObjectName(QStringLiteral("pupilChartWidget"));
        pupilChartWidget->setGeometry(QRect(10, 10, 1101, 691));
        horizontalScrollBar = new QScrollBar(visualizeDialog);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(10, 700, 1111, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(visualizeDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(1130, 90, 141, 391));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        angerCheckBox = new QCheckBox(layoutWidget);
        angerCheckBox->setObjectName(QStringLiteral("angerCheckBox"));
        angerCheckBox->setChecked(true);

        verticalLayout->addWidget(angerCheckBox);

        contemptCheckBox = new QCheckBox(layoutWidget);
        contemptCheckBox->setObjectName(QStringLiteral("contemptCheckBox"));
        contemptCheckBox->setChecked(true);

        verticalLayout->addWidget(contemptCheckBox);

        disgustCheckBox = new QCheckBox(layoutWidget);
        disgustCheckBox->setObjectName(QStringLiteral("disgustCheckBox"));
        disgustCheckBox->setChecked(true);

        verticalLayout->addWidget(disgustCheckBox);

        engagementCheckBox = new QCheckBox(layoutWidget);
        engagementCheckBox->setObjectName(QStringLiteral("engagementCheckBox"));
        engagementCheckBox->setChecked(true);

        verticalLayout->addWidget(engagementCheckBox);

        fearCheckBox = new QCheckBox(layoutWidget);
        fearCheckBox->setObjectName(QStringLiteral("fearCheckBox"));
        fearCheckBox->setChecked(true);

        verticalLayout->addWidget(fearCheckBox);

        joyCheckBox = new QCheckBox(layoutWidget);
        joyCheckBox->setObjectName(QStringLiteral("joyCheckBox"));
        joyCheckBox->setChecked(true);

        verticalLayout->addWidget(joyCheckBox);

        sadnessCheckBox = new QCheckBox(layoutWidget);
        sadnessCheckBox->setObjectName(QStringLiteral("sadnessCheckBox"));
        sadnessCheckBox->setChecked(true);

        verticalLayout->addWidget(sadnessCheckBox);

        surpriseCheckBox = new QCheckBox(layoutWidget);
        surpriseCheckBox->setObjectName(QStringLiteral("surpriseCheckBox"));
        surpriseCheckBox->setChecked(true);

        verticalLayout->addWidget(surpriseCheckBox);

        valenceCheckBox = new QCheckBox(layoutWidget);
        valenceCheckBox->setObjectName(QStringLiteral("valenceCheckBox"));
        valenceCheckBox->setChecked(true);

        verticalLayout->addWidget(valenceCheckBox);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        gsrCheckBox = new QCheckBox(layoutWidget);
        gsrCheckBox->setObjectName(QStringLiteral("gsrCheckBox"));
        gsrCheckBox->setChecked(true);

        verticalLayout->addWidget(gsrCheckBox);

        hrCheckBox = new QCheckBox(layoutWidget);
        hrCheckBox->setObjectName(QStringLiteral("hrCheckBox"));
        hrCheckBox->setChecked(true);

        verticalLayout->addWidget(hrCheckBox);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        diameter0CheckBox = new QCheckBox(layoutWidget);
        diameter0CheckBox->setObjectName(QStringLiteral("diameter0CheckBox"));
        diameter0CheckBox->setChecked(true);

        verticalLayout->addWidget(diameter0CheckBox);

        diameter1CheckBox = new QCheckBox(layoutWidget);
        diameter1CheckBox->setObjectName(QStringLiteral("diameter1CheckBox"));
        diameter1CheckBox->setChecked(true);

        verticalLayout->addWidget(diameter1CheckBox);

        graphComboBox = new QComboBox(visualizeDialog);
        graphComboBox->setObjectName(QStringLiteral("graphComboBox"));
        graphComboBox->setGeometry(QRect(1130, 40, 151, 41));
        exportButton = new QPushButton(visualizeDialog);
        exportButton->setObjectName(QStringLiteral("exportButton"));
        exportButton->setGeometry(QRect(1140, 670, 89, 25));

        retranslateUi(visualizeDialog);

        QMetaObject::connectSlotsByName(visualizeDialog);
    } // setupUi

    void retranslateUi(QDialog *visualizeDialog)
    {
        visualizeDialog->setWindowTitle(QApplication::translate("visualizeDialog", "Dialog", Q_NULLPTR));
        loadButton->setText(QApplication::translate("visualizeDialog", "Load", Q_NULLPTR));
        angerCheckBox->setText(QApplication::translate("visualizeDialog", "Anger", Q_NULLPTR));
        contemptCheckBox->setText(QApplication::translate("visualizeDialog", "Contempt", Q_NULLPTR));
        disgustCheckBox->setText(QApplication::translate("visualizeDialog", "Disgust", Q_NULLPTR));
        engagementCheckBox->setText(QApplication::translate("visualizeDialog", "Engagement", Q_NULLPTR));
        fearCheckBox->setText(QApplication::translate("visualizeDialog", "Fear", Q_NULLPTR));
        joyCheckBox->setText(QApplication::translate("visualizeDialog", "Joy", Q_NULLPTR));
        sadnessCheckBox->setText(QApplication::translate("visualizeDialog", "Sadness", Q_NULLPTR));
        surpriseCheckBox->setText(QApplication::translate("visualizeDialog", "Surprise", Q_NULLPTR));
        valenceCheckBox->setText(QApplication::translate("visualizeDialog", "Valence", Q_NULLPTR));
        gsrCheckBox->setText(QApplication::translate("visualizeDialog", "GSR", Q_NULLPTR));
        hrCheckBox->setText(QApplication::translate("visualizeDialog", "HR", Q_NULLPTR));
        diameter0CheckBox->setText(QApplication::translate("visualizeDialog", "Pupil 0 Diameter", Q_NULLPTR));
        diameter1CheckBox->setText(QApplication::translate("visualizeDialog", "Pupil 1 Diameter", Q_NULLPTR));
        graphComboBox->clear();
        graphComboBox->insertItems(0, QStringList()
         << QApplication::translate("visualizeDialog", "Average emotions", Q_NULLPTR)
         << QApplication::translate("visualizeDialog", "Emotions progression", Q_NULLPTR)
         << QApplication::translate("visualizeDialog", "Pupil Movement", Q_NULLPTR)
        );
        exportButton->setText(QApplication::translate("visualizeDialog", "Export", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class visualizeDialog: public Ui_visualizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZEDIALOG_H
