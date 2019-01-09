#-------------------------------------------------
#
# Project created by QtCreator 2018-11-13T11:16:39
#
#-------------------------------------------------

QT       += core gui bluetooth serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EmoSens_2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    keypresseventfilter.cpp \
    nzmqtsubscriber.cpp

HEADERS += \
    mainwindow.h \
    keypresseventfilter.h \
    global.h \
    nzmqtsubscriber.h

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

#HEADERS += \
   #     ./include/nzmqt/nzmqt.hpp \
 #       mainwindow.h \
  #  nzmqtsubscriber.h \
 #   datacollectiondialog.h \
  #  qcustomplot.h \
    #statsdialog.h \
   # visualizedialog.h


CONFIG += c++11

