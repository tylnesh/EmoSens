/********************************************************************************
** Form generated from reading UI file 'statsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATSDIALOG_H
#define UI_STATSDIALOG_H

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
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_statsDialog
{
public:
    QtCharts::QChartView *barChartWidget;
    QComboBox *graphComboBox;
    QCustomPlot *lineChartWidget;
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
    QScrollBar *horizontalScrollBar;

    void setupUi(QDialog *statsDialog)
    {
        if (statsDialog->objectName().isEmpty())
            statsDialog->setObjectName(QStringLiteral("statsDialog"));
        statsDialog->resize(1280, 720);
        barChartWidget = new QtCharts::QChartView(statsDialog);
        barChartWidget->setObjectName(QStringLiteral("barChartWidget"));
        barChartWidget->setGeometry(QRect(20, 10, 1091, 691));
        graphComboBox = new QComboBox(statsDialog);
        graphComboBox->setObjectName(QStringLiteral("graphComboBox"));
        graphComboBox->setGeometry(QRect(1120, 10, 151, 41));
        lineChartWidget = new QCustomPlot(statsDialog);
        lineChartWidget->setObjectName(QStringLiteral("lineChartWidget"));
        lineChartWidget->setGeometry(QRect(20, 10, 1091, 691));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineChartWidget->sizePolicy().hasHeightForWidth());
        lineChartWidget->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(statsDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(1130, 70, 141, 391));
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

        horizontalScrollBar = new QScrollBar(statsDialog);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(20, 700, 1091, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        retranslateUi(statsDialog);

        QMetaObject::connectSlotsByName(statsDialog);
    } // setupUi

    void retranslateUi(QDialog *statsDialog)
    {
        statsDialog->setWindowTitle(QApplication::translate("statsDialog", "Dialog", Q_NULLPTR));
        graphComboBox->clear();
        graphComboBox->insertItems(0, QStringList()
         << QApplication::translate("statsDialog", "Average emotions", Q_NULLPTR)
         << QApplication::translate("statsDialog", "Emotions progression", Q_NULLPTR)
        );
        angerCheckBox->setText(QApplication::translate("statsDialog", "Anger", Q_NULLPTR));
        contemptCheckBox->setText(QApplication::translate("statsDialog", "Contempt", Q_NULLPTR));
        disgustCheckBox->setText(QApplication::translate("statsDialog", "Disgust", Q_NULLPTR));
        engagementCheckBox->setText(QApplication::translate("statsDialog", "Engagement", Q_NULLPTR));
        fearCheckBox->setText(QApplication::translate("statsDialog", "Fear", Q_NULLPTR));
        joyCheckBox->setText(QApplication::translate("statsDialog", "Joy", Q_NULLPTR));
        sadnessCheckBox->setText(QApplication::translate("statsDialog", "Sadness", Q_NULLPTR));
        surpriseCheckBox->setText(QApplication::translate("statsDialog", "Surprise", Q_NULLPTR));
        valenceCheckBox->setText(QApplication::translate("statsDialog", "Valence", Q_NULLPTR));
        gsrCheckBox->setText(QApplication::translate("statsDialog", "GSR", Q_NULLPTR));
        hrCheckBox->setText(QApplication::translate("statsDialog", "HR", Q_NULLPTR));
        diameter0CheckBox->setText(QApplication::translate("statsDialog", "Pupil 0 Diameter", Q_NULLPTR));
        diameter1CheckBox->setText(QApplication::translate("statsDialog", "Pupil 1 Diameter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class statsDialog: public Ui_statsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATSDIALOG_H
