/****************************************************************************
** Meta object code from reading C++ file 'uiobjectstablewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../qosbrowser/src/fend/uimain/uiobjectstablewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiobjectstablewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UiObjectsTableWidget_t {
    QByteArrayData data[23];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UiObjectsTableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UiObjectsTableWidget_t qt_meta_stringdata_UiObjectsTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "UiObjectsTableWidget"
QT_MOC_LITERAL(1, 21, 21), // "on_btnBuckets_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 26), // "on_tableView_doubleClicked"
QT_MOC_LITERAL(4, 71, 11), // "QModelIndex"
QT_MOC_LITERAL(5, 83, 5), // "index"
QT_MOC_LITERAL(6, 89, 16), // "onObjectsSuccess"
QT_MOC_LITERAL(7, 106, 15), // "QList<MyObject>"
QT_MOC_LITERAL(8, 122, 7), // "objects"
QT_MOC_LITERAL(9, 130, 13), // "onPathChanged"
QT_MOC_LITERAL(10, 144, 7), // "newPath"
QT_MOC_LITERAL(11, 152, 16), // "onPageNumChanged"
QT_MOC_LITERAL(12, 169, 5), // "start"
QT_MOC_LITERAL(13, 175, 6), // "maxLen"
QT_MOC_LITERAL(14, 182, 21), // "on_btnRefresh_clicked"
QT_MOC_LITERAL(15, 204, 20), // "on_btnUpload_clicked"
QT_MOC_LITERAL(16, 225, 15), // "onUploadSuccess"
QT_MOC_LITERAL(17, 241, 5), // "jobId"
QT_MOC_LITERAL(18, 247, 17), // "onDownloadSuccess"
QT_MOC_LITERAL(19, 265, 22), // "on_btnDownload_clicked"
QT_MOC_LITERAL(20, 288, 11), // "showMessage"
QT_MOC_LITERAL(21, 300, 5), // "title"
QT_MOC_LITERAL(22, 306, 4) // "info"

    },
    "UiObjectsTableWidget\0on_btnBuckets_clicked\0"
    "\0on_tableView_doubleClicked\0QModelIndex\0"
    "index\0onObjectsSuccess\0QList<MyObject>\0"
    "objects\0onPathChanged\0newPath\0"
    "onPageNumChanged\0start\0maxLen\0"
    "on_btnRefresh_clicked\0on_btnUpload_clicked\0"
    "onUploadSuccess\0jobId\0onDownloadSuccess\0"
    "on_btnDownload_clicked\0showMessage\0"
    "title\0info"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UiObjectsTableWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    1,   70,    2, 0x08 /* Private */,
       6,    1,   73,    2, 0x08 /* Private */,
       9,    1,   76,    2, 0x08 /* Private */,
      11,    2,   79,    2, 0x08 /* Private */,
      14,    0,   84,    2, 0x08 /* Private */,
      15,    0,   85,    2, 0x08 /* Private */,
      16,    1,   86,    2, 0x08 /* Private */,
      18,    1,   89,    2, 0x08 /* Private */,
      19,    0,   92,    2, 0x08 /* Private */,
      20,    2,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   21,   22,

       0        // eod
};

void UiObjectsTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UiObjectsTableWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnBuckets_clicked(); break;
        case 1: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->onObjectsSuccess((*reinterpret_cast< const QList<MyObject>(*)>(_a[1]))); break;
        case 3: _t->onPathChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onPageNumChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_btnRefresh_clicked(); break;
        case 6: _t->on_btnUpload_clicked(); break;
        case 7: _t->onUploadSuccess((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->onDownloadSuccess((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_btnDownload_clicked(); break;
        case 10: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
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

QT_INIT_METAOBJECT const QMetaObject UiObjectsTableWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_UiObjectsTableWidget.data,
    qt_meta_data_UiObjectsTableWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UiObjectsTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UiObjectsTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UiObjectsTableWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UiObjectsTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
