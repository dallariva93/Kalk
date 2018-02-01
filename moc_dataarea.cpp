/****************************************************************************
** Meta object code from reading C++ file 'dataarea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "VIEW/dataarea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataArea_t {
    QByteArrayData data[12];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataArea_t qt_meta_stringdata_DataArea = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DataArea"
QT_MOC_LITERAL(1, 9, 15), // "outputPerimetro"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "outputArea"
QT_MOC_LITERAL(4, 37, 12), // "outputAngoli"
QT_MOC_LITERAL(5, 50, 15), // "QVector<Angolo>"
QT_MOC_LITERAL(6, 66, 10), // "outputLati"
QT_MOC_LITERAL(7, 77, 15), // "QVector<double>"
QT_MOC_LITERAL(8, 93, 11), // "outputSomma"
QT_MOC_LITERAL(9, 105, 17), // "outputSottrazione"
QT_MOC_LITERAL(10, 123, 21), // "outputMoltiplicazione"
QT_MOC_LITERAL(11, 145, 15) // "outputDivisione"

    },
    "DataArea\0outputPerimetro\0\0outputArea\0"
    "outputAngoli\0QVector<Angolo>\0outputLati\0"
    "QVector<double>\0outputSomma\0"
    "outputSottrazione\0outputMoltiplicazione\0"
    "outputDivisione"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       3,    1,   57,    2, 0x0a /* Public */,
       4,    1,   60,    2, 0x0a /* Public */,
       6,    1,   63,    2, 0x0a /* Public */,
       8,    1,   66,    2, 0x0a /* Public */,
       9,    1,   69,    2, 0x0a /* Public */,
      10,    1,   72,    2, 0x0a /* Public */,
      11,    1,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void DataArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataArea *_t = static_cast<DataArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->outputPerimetro((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->outputArea((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->outputAngoli((*reinterpret_cast< QVector<Angolo>(*)>(_a[1]))); break;
        case 3: _t->outputLati((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 4: _t->outputSomma((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->outputSottrazione((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->outputMoltiplicazione((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->outputDivisione((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    }
}

const QMetaObject DataArea::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_DataArea.data,
      qt_meta_data_DataArea,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataArea.stringdata0))
        return static_cast<void*>(const_cast< DataArea*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int DataArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
