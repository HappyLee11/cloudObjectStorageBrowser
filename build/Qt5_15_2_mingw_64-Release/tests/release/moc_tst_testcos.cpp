/****************************************************************************
** Meta object code from reading C++ file 'tst_testcos.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../tests/testcos/tst_testcos.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_testcos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestCos_t {
    QByteArrayData data[15];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestCos_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestCos_t qt_meta_stringdata_TestCos = {
    {
QT_MOC_LITERAL(0, 0, 7), // "TestCos"
QT_MOC_LITERAL(1, 8, 12), // "initTestCase"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 15), // "cleanupTestCase"
QT_MOC_LITERAL(4, 38, 12), // "test_buckets"
QT_MOC_LITERAL(5, 51, 19), // "test_isBucketExists"
QT_MOC_LITERAL(6, 71, 22), // "test_getBucketLocation"
QT_MOC_LITERAL(7, 94, 14), // "test_putBucket"
QT_MOC_LITERAL(8, 109, 17), // "test_deleteBucket"
QT_MOC_LITERAL(9, 127, 15), // "test_getObjects"
QT_MOC_LITERAL(10, 143, 21), // "test_getObjects2_data"
QT_MOC_LITERAL(11, 165, 16), // "test_getObjects2"
QT_MOC_LITERAL(12, 182, 19), // "test_getObjectError"
QT_MOC_LITERAL(13, 202, 14), // "test_putObject"
QT_MOC_LITERAL(14, 217, 14) // "test_getObject"

    },
    "TestCos\0initTestCase\0\0cleanupTestCase\0"
    "test_buckets\0test_isBucketExists\0"
    "test_getBucketLocation\0test_putBucket\0"
    "test_deleteBucket\0test_getObjects\0"
    "test_getObjects2_data\0test_getObjects2\0"
    "test_getObjectError\0test_putObject\0"
    "test_getObject"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestCos[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestCos::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestCos *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->cleanupTestCase(); break;
        case 2: _t->test_buckets(); break;
        case 3: _t->test_isBucketExists(); break;
        case 4: _t->test_getBucketLocation(); break;
        case 5: _t->test_putBucket(); break;
        case 6: _t->test_deleteBucket(); break;
        case 7: _t->test_getObjects(); break;
        case 8: _t->test_getObjects2_data(); break;
        case 9: _t->test_getObjects2(); break;
        case 10: _t->test_getObjectError(); break;
        case 11: _t->test_putObject(); break;
        case 12: _t->test_getObject(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TestCos::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TestCos.data,
    qt_meta_data_TestCos,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TestCos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestCos::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestCos.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestCos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
