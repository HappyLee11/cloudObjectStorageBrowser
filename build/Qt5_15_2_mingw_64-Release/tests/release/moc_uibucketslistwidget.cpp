/****************************************************************************
** Meta object code from reading C++ file 'uibucketslistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../qosbrowser/src/fend/uimain/uibucketslistwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uibucketslistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UiBucketsListWidget_t {
    QByteArrayData data[12];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UiBucketsListWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UiBucketsListWidget_t qt_meta_stringdata_UiBucketsListWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "UiBucketsListWidget"
QT_MOC_LITERAL(1, 20, 16), // "onBucketsSuccess"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 15), // "QList<MyBucket>"
QT_MOC_LITERAL(4, 54, 7), // "buckets"
QT_MOC_LITERAL(5, 62, 25), // "on_listView_doubleClicked"
QT_MOC_LITERAL(6, 88, 11), // "QModelIndex"
QT_MOC_LITERAL(7, 100, 5), // "index"
QT_MOC_LITERAL(8, 106, 17), // "showBucketObjects"
QT_MOC_LITERAL(9, 124, 10), // "bucketName"
QT_MOC_LITERAL(10, 135, 12), // "onTextEdited"
QT_MOC_LITERAL(11, 148, 4) // "text"

    },
    "UiBucketsListWidget\0onBucketsSuccess\0"
    "\0QList<MyBucket>\0buckets\0"
    "on_listView_doubleClicked\0QModelIndex\0"
    "index\0showBucketObjects\0bucketName\0"
    "onTextEdited\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UiBucketsListWidget[] = {

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
       1,    1,   34,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,
       8,    1,   40,    2, 0x08 /* Private */,
      10,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void UiBucketsListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UiBucketsListWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onBucketsSuccess((*reinterpret_cast< const QList<MyBucket>(*)>(_a[1]))); break;
        case 1: _t->on_listView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->showBucketObjects((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onTextEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<MyBucket> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UiBucketsListWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_UiBucketsListWidget.data,
    qt_meta_data_UiBucketsListWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UiBucketsListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UiBucketsListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UiBucketsListWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UiBucketsListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
