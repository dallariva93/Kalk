/****************************************************************************
** Meta object code from reading C++ file 'polygoncreator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "VIEW/polygoncreator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'polygoncreator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PolygonCreator_t {
    QByteArrayData data[7];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PolygonCreator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PolygonCreator_t qt_meta_stringdata_PolygonCreator = {
    {
QT_MOC_LITERAL(0, 0, 14), // "PolygonCreator"
QT_MOC_LITERAL(1, 15, 12), // "triangleSlot"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 17), // "quadrilateralSlot"
QT_MOC_LITERAL(4, 47, 12), // "pentagonSlot"
QT_MOC_LITERAL(5, 60, 9), // "addColore"
QT_MOC_LITERAL(6, 70, 7) // "Colore*"

    },
    "PolygonCreator\0triangleSlot\0\0"
    "quadrilateralSlot\0pentagonSlot\0addColore\0"
    "Colore*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PolygonCreator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void PolygonCreator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PolygonCreator *_t = static_cast<PolygonCreator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->triangleSlot(); break;
        case 1: _t->quadrilateralSlot(); break;
        case 2: _t->pentagonSlot(); break;
        case 3: _t->addColore((*reinterpret_cast< Colore*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject PolygonCreator::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PolygonCreator.data,
      qt_meta_data_PolygonCreator,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PolygonCreator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PolygonCreator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PolygonCreator.stringdata0))
        return static_cast<void*>(const_cast< PolygonCreator*>(this));
    return QWidget::qt_metacast(_clname);
}

int PolygonCreator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
