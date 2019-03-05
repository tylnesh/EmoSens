#-------------------------------------------------
#
# Project created by QtCreator 2018-11-13T11:16:39
#
#-------------------------------------------------

QT       += core gui serialport concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EmoSens_3
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        keypresseventfilter.cpp \
        nzmqtsubscriber.cpp \
        affectzmq.cpp


HEADERS += \
    ./include/nzmqt/nzmqt.hpp \
    mainwindow.h \
    keypresseventfilter.h \
    global.h \
    nzmqtsubscriber.h\
    include/zhelpers.hpp \
    affectzmq.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += /usr/local/include/opencv4 \
               /usr/local/include/opencv4/opencv2 \
               3rdparty/cppzmq \
              ./include \
              ./3rdparty/cppzmq \
              $(QTDIR)/include \
              /opt/local/include

LIBS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_objdetect -lopencv_imgcodecs -lopencv_videoio -lzmq -lqmsgpack


CONFIG += c++11

