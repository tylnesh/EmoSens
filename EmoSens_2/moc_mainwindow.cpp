/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "handleReadyRead"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "handleTimeout"
QT_MOC_LITERAL(4, 42, 11), // "handleError"
QT_MOC_LITERAL(5, 54, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(6, 83, 5), // "error"
QT_MOC_LITERAL(7, 89, 12), // "dataReceived"
QT_MOC_LITERAL(8, 102, 1), // "v"
QT_MOC_LITERAL(9, 104, 1), // "t"
QT_MOC_LITERAL(10, 106, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(11, 129, 6), // "update"
QT_MOC_LITERAL(12, 136, 22), // "on_pauseButton_clicked"
QT_MOC_LITERAL(13, 159, 24), // "on_connectButton_clicked"
QT_MOC_LITERAL(14, 184, 16), // "realTimeDataSlot"
QT_MOC_LITERAL(15, 201, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(16, 223, 25), // "on_isArduino_stateChanged"
QT_MOC_LITERAL(17, 249, 4), // "arg1"
QT_MOC_LITERAL(18, 254, 23) // "on_selectButton_clicked"

    },
    "MainWindow\0handleReadyRead\0\0handleTimeout\0"
    "handleError\0QSerialPort::SerialPortError\0"
    "error\0dataReceived\0v\0t\0on_startButton_clicked\0"
    "update\0on_pauseButton_clicked\0"
    "on_connectButton_clicked\0realTimeDataSlot\0"
    "on_pushButton_clicked\0on_isArduino_stateChanged\0"
    "arg1\0on_selectButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    1,   76,    2, 0x0a /* Public */,
       7,    2,   79,    2, 0x0a /* Public */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    0,   88,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,
      16,    1,   90,    2, 0x08 /* Private */,
      18,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QString,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleReadyRead(); break;
        case 1: _t->handleTimeout(); break;
        case 2: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 3: _t->dataReceived((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->on_startButton_clicked(); break;
        case 5: _t->update(); break;
        case 6: _t->on_pauseButton_clicked(); break;
        case 7: _t->on_connectButton_clicked(); break;
        case 8: _t->realTimeDataSlot(); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_isArduino_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_selectButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
