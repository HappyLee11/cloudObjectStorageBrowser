/****************************************************************************
** Meta object code from reading C++ file 'uimain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../qosbrowser/src/fend/uimain/uimain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uimain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UiMain_t {
    QByteArrayData data[14];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UiMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UiMain_t qt_meta_stringdata_UiMain = {
    {
QT_MOC_LITERAL(0, 0, 6), // "UiMain"
QT_MOC_LITERAL(1, 7, 9), // "onUnLogin"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 16), // "onBucketsSuccess"
QT_MOC_LITERAL(4, 35, 15), // "QList<MyBucket>"
QT_MOC_LITERAL(5, 51, 7), // "buckets"
QT_MOC_LITERAL(6, 59, 16), // "onObjectsSuccess"
QT_MOC_LITERAL(7, 76, 15), // "QList<MyObject>"
QT_MOC_LITERAL(8, 92, 7), // "objects"
QT_MOC_LITERAL(9, 100, 12), // "showTransfer"
QT_MOC_LITERAL(10, 113, 7), // "onError"
QT_MOC_LITERAL(11, 121, 3), // "api"
QT_MOC_LITERAL(12, 125, 3), // "msg"
QT_MOC_LITERAL(13, 129, 3) // "req"

    },
    "UiMain\0onUnLogin\0\0onBucketsSuccess\0"
    "QList<MyBucket>\0buckets\0onObjectsSuccess\0"
    "QList<MyObject>\0objects\0showTransfer\0"
    "onError\0api\0msg\0req"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UiMain[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    1,   40,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,
       9,    0,   46,    2, 0x08 /* Private */,
      10,    3,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QJsonValue,   11,   12,   13,

       0        // eod
};

void UiMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UiMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onUnLogin(); break;
        case 1: _t->onBucketsSuccess((*reinterpret_cast< const QList<MyBucket>(*)>(_a[1]))); break;
        case 2: _t->onObjectsSuccess((*reinterpret_cast< const QList<MyObject>(*)>(_a[1]))); break;
        case 3: _t->showTransfer(); break;
        case 4: _t->onError((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QJsonValue(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<MyBucket> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<MyObject> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UiMain::staticMetaObject = { {
    QMetaObject::SuperData::link<UiQosDialog::staticMetaObject>(),
    qt_meta_stringdata_UiMain.data,
    qt_meta_data_UiMain,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UiMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UiMain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UiMain.stringdata0))
        return static_cast<void*>(this);
    return UiQosDialog::qt_metacast(_clname);
}

int UiMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = UiQosDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
