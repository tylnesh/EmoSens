/****************************************************************************
** Meta object code from reading C++ file 'datacollectiondialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "datacollectiondialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datacollectiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataCollectionDialog_t {
    QByteArrayData data[15];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataCollectionDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataCollectionDialog_t qt_meta_stringdata_DataCollectionDialog = {
    {
QT_MOC_LITERAL(0, 0, 20), // "DataCollectionDialog"
QT_MOC_LITERAL(1, 21, 12), // "dataReceived"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 1), // "v"
QT_MOC_LITERAL(4, 37, 1), // "t"
QT_MOC_LITERAL(5, 39, 15), // "handleReadyRead"
QT_MOC_LITERAL(6, 55, 13), // "handleTimeout"
QT_MOC_LITERAL(7, 69, 11), // "handleError"
QT_MOC_LITERAL(8, 81, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(9, 110, 5), // "error"
QT_MOC_LITERAL(10, 116, 16), // "realTimeDataSlot"
QT_MOC_LITERAL(11, 133, 10), // "incrementT"
QT_MOC_LITERAL(12, 144, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(13, 167, 22), // "on_pauseButton_clicked"
QT_MOC_LITERAL(14, 190, 22) // "on_statsButton_clicked"

    },
    "DataCollectionDialog\0dataReceived\0\0v\0"
    "t\0handleReadyRead\0handleTimeout\0"
    "handleError\0QSerialPort::SerialPortError\0"
    "error\0realTimeDataSlot\0incrementT\0"
    "on_startButton_clicked\0on_pauseButton_clicked\0"
    "on_statsButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataCollectionDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x09 /* Protected */,
       5,    0,   64,    2, 0x0a /* Public */,
       6,    0,   65,    2, 0x0a /* Public */,
       7,    1,   66,    2, 0x0a /* Public */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    0,   71,    2, 0x08 /* Private */,
      13,    0,   72,    2, 0x08 /* Private */,
      14,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DataCollectionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataCollectionDialog *_t = static_cast<DataCollectionDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataReceived((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->handleReadyRead(); break;
        case 2: _t->handleTimeout(); break;
        case 3: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 4: _t->realTimeDataSlot(); break;
        case 5: _t->incrementT(); break;
        case 6: _t->on_startButton_clicked(); break;
        case 7: _t->on_pauseButton_clicked(); break;
        case 8: _t->on_statsButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataCollectionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DataCollectionDialog.data,
      qt_meta_data_DataCollectionDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataCollectionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataCollectionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataCollectionDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DataCollectionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
