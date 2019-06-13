/****************************************************************************
** Meta object code from reading C++ file 'teste2promwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestE2prom/teste2promwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'teste2promwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestE2promWidget_t {
    QByteArrayData data[13];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestE2promWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestE2promWidget_t qt_meta_stringdata_TestE2promWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TestE2promWidget"
QT_MOC_LITERAL(1, 17, 33), // "on_SetCmdSelectpushButton_cli..."
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 33), // "on_QueCmdSelectpushButton_cli..."
QT_MOC_LITERAL(4, 86, 26), // "on_StartpushButton_clicked"
QT_MOC_LITERAL(5, 113, 25), // "on_StoppushButton_clicked"
QT_MOC_LITERAL(6, 139, 11), // "Slot_setCmd"
QT_MOC_LITERAL(7, 151, 11), // "QList<char>"
QT_MOC_LITERAL(8, 163, 10), // "p_cmd_List"
QT_MOC_LITERAL(9, 174, 11), // "Slot_QueCmd"
QT_MOC_LITERAL(10, 186, 12), // "Slot_timeout"
QT_MOC_LITERAL(11, 199, 13), // "Slot_timeout1"
QT_MOC_LITERAL(12, 213, 21) // "on_pushButton_clicked"

    },
    "TestE2promWidget\0on_SetCmdSelectpushButton_clicked\0"
    "\0on_QueCmdSelectpushButton_clicked\0"
    "on_StartpushButton_clicked\0"
    "on_StoppushButton_clicked\0Slot_setCmd\0"
    "QList<char>\0p_cmd_List\0Slot_QueCmd\0"
    "Slot_timeout\0Slot_timeout1\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestE2promWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    1,   63,    2, 0x08 /* Private */,
       9,    1,   66,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    0,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestE2promWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestE2promWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_SetCmdSelectpushButton_clicked(); break;
        case 1: _t->on_QueCmdSelectpushButton_clicked(); break;
        case 2: _t->on_StartpushButton_clicked(); break;
        case 3: _t->on_StoppushButton_clicked(); break;
        case 4: _t->Slot_setCmd((*reinterpret_cast< QList<char>(*)>(_a[1]))); break;
        case 5: _t->Slot_QueCmd((*reinterpret_cast< QList<char>(*)>(_a[1]))); break;
        case 6: _t->Slot_timeout(); break;
        case 7: _t->Slot_timeout1(); break;
        case 8: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<char> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<char> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TestE2promWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_TestE2promWidget.data,
    qt_meta_data_TestE2promWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TestE2promWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestE2promWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestE2promWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TestE2promWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
