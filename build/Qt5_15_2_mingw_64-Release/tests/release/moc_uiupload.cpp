/****************************************************************************
** Meta object code from reading C++ file 'uiupload.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../qosbrowser/src/fend/uitransfer/uiupload.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiupload.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UiUpload_t {
    QByteArrayData data[14];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UiUpload_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UiUpload_t qt_meta_stringdata_UiUpload = {
    {
QT_MOC_LITERAL(0, 0, 8), // "UiUpload"
QT_MOC_LITERAL(1, 9, 13), // "onStartUpload"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "jobId"
QT_MOC_LITERAL(4, 30, 3), // "key"
QT_MOC_LITERAL(5, 34, 9), // "localPath"
QT_MOC_LITERAL(6, 44, 15), // "onUploadProcess"
QT_MOC_LITERAL(7, 60, 14), // "transferedSize"
QT_MOC_LITERAL(8, 75, 9), // "totalSize"
QT_MOC_LITERAL(9, 85, 15), // "onUploadSuccess"
QT_MOC_LITERAL(10, 101, 7), // "onError"
QT_MOC_LITERAL(11, 109, 3), // "api"
QT_MOC_LITERAL(12, 113, 3), // "msg"
QT_MOC_LITERAL(13, 117, 3) // "req"

    },
    "UiUpload\0onStartUpload\0\0jobId\0key\0"
    "localPath\0onUploadProcess\0transferedSize\0"
    "totalSize\0onUploadSuccess\0onError\0api\0"
    "msg\0req"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UiUpload[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x08 /* Private */,
       6,    3,   41,    2, 0x08 /* Private */,
       9,    1,   48,    2, 0x08 /* Private */,
      10,    3,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::ULongLong, QMetaType::ULongLong,    3,    7,    8,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QJsonValue,   11,   12,   13,

       0        // eod
};

void UiUpload::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UiUpload *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onStartUpload((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->onUploadProcess((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< qulonglong(*)>(_a[2])),(*reinterpret_cast< qulonglong(*)>(_a[3]))); break;
        case 2: _t->onUploadSuccess((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onError((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QJsonValue(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UiUpload::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_UiUpload.data,
    qt_meta_data_UiUpload,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UiUpload::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UiUpload::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UiUpload.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UiUpload::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
