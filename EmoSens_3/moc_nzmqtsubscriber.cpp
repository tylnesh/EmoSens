/****************************************************************************
** Meta object code from reading C++ file 'nzmqtsubscriber.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "nzmqtsubscriber.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nzmqtsubscriber.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_nzmqtSubscriber_t {
    QByteArrayData data[7];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nzmqtSubscriber_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nzmqtSubscriber_t qt_meta_stringdata_nzmqtSubscriber = {
    {
QT_MOC_LITERAL(0, 0, 15), // "nzmqtSubscriber"
QT_MOC_LITERAL(1, 16, 11), // "extractData"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 1), // "v"
QT_MOC_LITERAL(4, 31, 1), // "t"
QT_MOC_LITERAL(5, 33, 15), // "messageReceived"
QT_MOC_LITERAL(6, 49, 7) // "message"

    },
    "nzmqtSubscriber\0extractData\0\0v\0t\0"
    "messageReceived\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nzmqtSubscriber[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   29,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArrayList,    6,

       0        // eod
};

void nzmqtSubscriber::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        nzmqtSubscriber *_t = static_cast<nzmqtSubscriber *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->extractData((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->messageReceived((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (nzmqtSubscriber::*_t)(QVariant , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nzmqtSubscriber::extractData)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject nzmqtSubscriber::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_nzmqtSubscriber.data,
      qt_meta_data_nzmqtSubscriber,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *nzmqtSubscriber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nzmqtSubscriber::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_nzmqtSubscriber.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int nzmqtSubscriber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void nzmqtSubscriber::extractData(QVariant _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
