/****************************************************************************
** Meta object code from reading C++ file 'uibucketstablewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../qosbrowser/src/fend/uimain/uibucketstablewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uibucketstablewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UiBucketsTableWidget_t {
    QByteArrayData data[14];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UiBucketsTableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UiBucketsTableWidget_t qt_meta_stringdata_UiBucketsTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "UiBucketsTableWidget"
QT_MOC_LITERAL(1, 21, 26), // "on_tableView_doubleClicked"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 61, 5), // "index"
QT_MOC_LITERAL(5, 67, 16), // "onBucketsSuccess"
QT_MOC_LITERAL(6, 84, 15), // "QList<MyBucket>"
QT_MOC_LITERAL(7, 100, 7), // "buckets"
QT_MOC_LITERAL(8, 108, 16), // "onPageNumChanged"
QT_MOC_LITERAL(9, 125, 5), // "start"
QT_MOC_LITERAL(10, 131, 6), // "maxLen"
QT_MOC_LITERAL(11, 138, 26), // "on_btnCreateBucket_clicked"
QT_MOC_LITERAL(12, 165, 11), // "onDelBucket"
QT_MOC_LITERAL(13, 177, 21) // "on_btnRefresh_clicked"

    },
    "UiBucketsTableWidget\0on_tableView_doubleClicked\0"
    "\0QModelIndex\0index\0onBucketsSuccess\0"
    "QList<MyBucket>\0buckets\0onPageNumChanged\0"
    "start\0maxLen\0on_btnCreateBucket_clicked\0"
    "onDelBucket\0on_btnRefresh_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UiBucketsTableWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       8,    2,   50,    2, 0x08 /* Private */,
      11,    0,   55,    2, 0x08 /* Private */,
      12,    0,   56,    2, 0x08 /* Private */,
      13,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UiBucketsTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UiBucketsTableWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->onBucketsSuccess((*reinterpret_cast< const QList<MyBucket>(*)>(_a[1]))); break;
        case 2: _t->onPageNumChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_btnCreateBucket_clicked(); break;
        case 4: _t->onDelBucket(); break;
        case 5: _t->on_btnRefresh_clicked(); break;
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
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UiBucketsTableWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_UiBucketsTableWidget.data,
    qt_meta_data_UiBucketsTableWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UiBucketsTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UiBucketsTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UiBucketsTableWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UiBucketsTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
