/****************************************************************************
** Meta object code from reading C++ file 'cmddialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestE2prom/CmdWidget/cmddialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cmddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cmdDialog_t {
    QByteArrayData data[21];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cmdDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cmdDialog_t qt_meta_stringdata_cmdDialog = {
    {
QT_MOC_LITERAL(0, 0, 9), // "cmdDialog"
QT_MOC_LITERAL(1, 10, 15), // "signals_CmdData"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "QList<char>"
QT_MOC_LITERAL(4, 39, 7), // "CmdData"
QT_MOC_LITERAL(5, 47, 17), // "on_MainCmdchanged"
QT_MOC_LITERAL(6, 65, 11), // "indexOffset"
QT_MOC_LITERAL(7, 77, 16), // "on_SubCmdchanged"
QT_MOC_LITERAL(8, 94, 10), // "GetCmdData"
QT_MOC_LITERAL(9, 105, 9), // "floatText"
QT_MOC_LITERAL(10, 115, 4), // "text"
QT_MOC_LITERAL(11, 120, 7), // "setComm"
QT_MOC_LITERAL(12, 128, 16), // "CANcommuniction*"
QT_MOC_LITERAL(13, 145, 6), // "setCan"
QT_MOC_LITERAL(14, 152, 14), // "initDeviceInfo"
QT_MOC_LITERAL(15, 167, 11), // "DeviceInfo*"
QT_MOC_LITERAL(16, 179, 12), // "p_deviceInfo"
QT_MOC_LITERAL(17, 192, 9), // "setSENDID"
QT_MOC_LITERAL(18, 202, 8), // "p_sendId"
QT_MOC_LITERAL(19, 211, 25), // "on_sendPushButton_clicked"
QT_MOC_LITERAL(20, 237, 11) // "sendCmdData"

    },
    "cmdDialog\0signals_CmdData\0\0QList<char>\0"
    "CmdData\0on_MainCmdchanged\0indexOffset\0"
    "on_SubCmdchanged\0GetCmdData\0floatText\0"
    "text\0setComm\0CANcommuniction*\0setCan\0"
    "initDeviceInfo\0DeviceInfo*\0p_deviceInfo\0"
    "setSENDID\0p_sendId\0on_sendPushButton_clicked\0"
    "sendCmdData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cmdDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   67,    2, 0x0a /* Public */,
       7,    1,   70,    2, 0x0a /* Public */,
       8,    0,   73,    2, 0x0a /* Public */,
       9,    1,   74,    2, 0x0a /* Public */,
      11,    1,   77,    2, 0x0a /* Public */,
      14,    1,   80,    2, 0x0a /* Public */,
      17,    1,   83,    2, 0x0a /* Public */,
      19,    0,   86,    2, 0x08 /* Private */,
      20,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Int, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::UInt,   18,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cmdDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<cmdDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signals_CmdData((*reinterpret_cast< QList<char>(*)>(_a[1]))); break;
        case 1: _t->on_MainCmdchanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_SubCmdchanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->GetCmdData(); break;
        case 4: _t->floatText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: { int _r = _t->setComm((*reinterpret_cast< CANcommuniction*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->initDeviceInfo((*reinterpret_cast< DeviceInfo*(*)>(_a[1]))); break;
        case 7: _t->setSENDID((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 8: _t->on_sendPushButton_clicked(); break;
        case 9: _t->sendCmdData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
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
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CANcommuniction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (cmdDialog::*)(QList<char> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cmdDialog::signals_CmdData)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cmdDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_cmdDialog.data,
    qt_meta_data_cmdDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cmdDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cmdDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cmdDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int cmdDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void cmdDialog::signals_CmdData(QList<char> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
