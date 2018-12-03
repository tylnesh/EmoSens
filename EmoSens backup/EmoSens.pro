#-------------------------------------------------
#
# Project created by QtCreator 2018-03-22T22:53:06
#
#-------------------------------------------------

QT       += core gui serialport charts network #multimediawidgets multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = EmoSens
TEMPLATE = app



# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_NO_VERSION_TAGGING

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    nzmqtsubscriber.cpp \
    datacollectiondialog.cpp \
    qcustomplot.cpp \
    statsdialog.cpp \
    visualizedialog.cpp

HEADERS += \
        ./include/nzmqt/nzmqt.hpp \
        mainwindow.h \
    nzmqtsubscriber.h \
    datacollectiondialog.h \
    qcustomplot.h \
    statsdialog.h \
    visualizedialog.h

LIBS  += -lzmq -lqmsgpack

CONFIG += c++11

INCLUDEPATH += \
    ./include \
    ./3rdparty/cppzmq \
    $(QTDIR)/include \
    /opt/local/include


FORMS += \
        mainwindow.ui \
    datacollectiondialog.ui \
    statsdialog.ui \
    visualizedialog.ui




