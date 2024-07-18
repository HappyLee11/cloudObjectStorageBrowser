/****************************************************************************
** Meta object code from reading C++ file 'basiclogger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../qosbrowser/src/bend/dao/logs/basiclogger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basiclogger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BasicLogger_t {
    QByteArrayData data[10];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BasicLogger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BasicLogger_t qt_meta_stringdata_BasicLogger = {
    {
QT_MOC_LITERAL(0, 0, 11), // "BasicLogger"
QT_MOC_LITERAL(1, 12, 5), // "onLog"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "file"
QT_MOC_LITERAL(4, 24, 4), // "line"
QT_MOC_LITERAL(5, 29, 4), // "func"
QT_MOC_LITERAL(6, 34, 3), // "tid"
QT_MOC_LITERAL(7, 38, 5), // "level"
QT_MOC_LITERAL(8, 44, 3), // "var"
QT_MOC_LITERAL(9, 48, 2) // "up"

    },
    "BasicLogger\0onLog\0\0file\0line\0func\0tid\0"
    "level\0var\0up"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BasicLogger[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    7,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::VoidStar, QMetaType::Int, QMetaType::QVariant, QMetaType::Bool,    3,    4,    5,    6,    7,    8,    9,

       0        // eod
};

void BasicLogger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BasicLogger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onLog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< void*(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< const QVariant(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BasicLogger::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BasicLogger.data,
    qt_meta_data_BasicLogger,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BasicLogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BasicLogger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BasicLogger.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BasicLogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
