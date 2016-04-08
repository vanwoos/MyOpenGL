/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Window_t {
    QByteArrayData data[14];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_t qt_meta_stringdata_Window = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Window"
QT_MOC_LITERAL(1, 7, 26), // "on_rotXSlider_valueChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "value"
QT_MOC_LITERAL(4, 41, 26), // "on_rotYSlider_valueChanged"
QT_MOC_LITERAL(5, 68, 26), // "on_rotZSlider_valueChanged"
QT_MOC_LITERAL(6, 95, 27), // "on_rotXSpinBox_valueChanged"
QT_MOC_LITERAL(7, 123, 4), // "arg1"
QT_MOC_LITERAL(8, 128, 27), // "on_rotYSpinBox_valueChanged"
QT_MOC_LITERAL(9, 156, 27), // "on_rotZSpinBox_valueChanged"
QT_MOC_LITERAL(10, 184, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(11, 209, 29), // "on_doubleSpinBox_valueChanged"
QT_MOC_LITERAL(12, 239, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(13, 261, 23) // "on_pushButton_2_clicked"

    },
    "Window\0on_rotXSlider_valueChanged\0\0"
    "value\0on_rotYSlider_valueChanged\0"
    "on_rotZSlider_valueChanged\0"
    "on_rotXSpinBox_valueChanged\0arg1\0"
    "on_rotYSpinBox_valueChanged\0"
    "on_rotZSpinBox_valueChanged\0"
    "on_checkBox_stateChanged\0"
    "on_doubleSpinBox_valueChanged\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    1,   67,    2, 0x08 /* Private */,
       5,    1,   70,    2, 0x08 /* Private */,
       6,    1,   73,    2, 0x08 /* Private */,
       8,    1,   76,    2, 0x08 /* Private */,
       9,    1,   79,    2, 0x08 /* Private */,
      10,    1,   82,    2, 0x08 /* Private */,
      11,    1,   85,    2, 0x08 /* Private */,
      12,    0,   88,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Window *_t = static_cast<Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_rotXSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_rotYSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_rotZSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_rotXSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_rotYSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_rotZSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_doubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Window::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Window.data,
      qt_meta_data_Window,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Window.stringdata0))
        return static_cast<void*>(const_cast< Window*>(this));
    return QWidget::qt_metacast(_clname);
}

int Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
