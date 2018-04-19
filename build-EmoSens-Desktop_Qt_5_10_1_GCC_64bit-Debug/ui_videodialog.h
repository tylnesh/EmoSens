/********************************************************************************
** Form generated from reading UI file 'videodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEODIALOG_H
#define UI_VIDEODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSlider>
#include <qvideowidget.h>

QT_BEGIN_NAMESPACE

class Ui_VideoDialog
{
public:
    QVideoWidget *videoWidget;
    QSlider *m_positionSlider;

    void setupUi(QDialog *VideoDialog)
    {
        if (VideoDialog->objectName().isEmpty())
            VideoDialog->setObjectName(QStringLiteral("VideoDialog"));
        VideoDialog->resize(1280, 720);
        videoWidget = new QVideoWidget(VideoDialog);
        videoWidget->setObjectName(QStringLiteral("videoWidget"));
        videoWidget->setGeometry(QRect(0, 0, 1280, 720));
        m_positionSlider = new QSlider(videoWidget);
        m_positionSlider->setObjectName(QStringLiteral("m_positionSlider"));
        m_positionSlider->setGeometry(QRect(0, 700, 1271, 16));
        m_positionSlider->setOrientation(Qt::Horizontal);

        retranslateUi(VideoDialog);

        QMetaObject::connectSlotsByName(VideoDialog);
    } // setupUi

    void retranslateUi(QDialog *VideoDialog)
    {
        VideoDialog->setWindowTitle(QApplication::translate("VideoDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoDialog: public Ui_VideoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEODIALOG_H
