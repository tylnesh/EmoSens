/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QComboBox *arduinoBox;
    QCheckBox *isArduino;
    QLineEdit *affectivaAddress;
    QCheckBox *isAffectiva;
    QPushButton *selectButton;
    QPushButton *connectButton;
    QCheckBox *isPupil;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1548, 1032);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 1471, 811));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setEnabled(false);
        startButton->setGeometry(QRect(670, 770, 148, 50));
        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setEnabled(false);
        pauseButton->setGeometry(QRect(840, 770, 148, 50));
        arduinoBox = new QComboBox(centralWidget);
        arduinoBox->setObjectName(QStringLiteral("arduinoBox"));
        arduinoBox->setGeometry(QRect(10, 770, 201, 51));
        isArduino = new QCheckBox(centralWidget);
        isArduino->setObjectName(QStringLiteral("isArduino"));
        isArduino->setGeometry(QRect(20, 830, 201, 23));
        isArduino->setChecked(true);
        affectivaAddress = new QLineEdit(centralWidget);
        affectivaAddress->setObjectName(QStringLiteral("affectivaAddress"));
        affectivaAddress->setGeometry(QRect(1260, 790, 171, 41));
        isAffectiva = new QCheckBox(centralWidget);
        isAffectiva->setObjectName(QStringLiteral("isAffectiva"));
        isAffectiva->setGeometry(QRect(1250, 760, 181, 23));
        isAffectiva->setChecked(true);
        selectButton = new QPushButton(centralWidget);
        selectButton->setObjectName(QStringLiteral("selectButton"));
        selectButton->setGeometry(QRect(430, 770, 148, 50));
        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(1090, 770, 141, 51));
        isPupil = new QCheckBox(centralWidget);
        isPupil->setObjectName(QStringLiteral("isPupil"));
        isPupil->setGeometry(QRect(1250, 730, 171, 23));
        isPupil->setChecked(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1548, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        startButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        isArduino->setText(QApplication::translate("MainWindow", "Is base station connected?", nullptr));
        isAffectiva->setText(QApplication::translate("MainWindow", "Is Affectiva installed?", nullptr));
        selectButton->setText(QApplication::translate("MainWindow", "Select image folder", nullptr));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        isPupil->setText(QApplication::translate("MainWindow", "Is Pupil Running?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
