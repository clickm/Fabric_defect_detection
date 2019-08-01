/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QT_Fabric/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[380];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 31), // "on_pushButton_readImage_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 31), // "on_pushButton_NextImage_clicked"
QT_MOC_LITERAL(4, 76, 30), // "on_pushButton_MethodOK_clicked"
QT_MOC_LITERAL(5, 107, 12), // "deal_process"
QT_MOC_LITERAL(6, 120, 9), // "NumErrors"
QT_MOC_LITERAL(7, 130, 26), // "on_pushButton_Path_clicked"
QT_MOC_LITERAL(8, 157, 20), // "on_waychoose_clicked"
QT_MOC_LITERAL(9, 178, 31), // "on_pushButton_LastImage_clicked"
QT_MOC_LITERAL(10, 210, 12), // "GMM_training"
QT_MOC_LITERAL(11, 223, 12), // "defects_laws"
QT_MOC_LITERAL(12, 236, 6), // "HTuple"
QT_MOC_LITERAL(13, 243, 4), // "hv_J"
QT_MOC_LITERAL(14, 248, 28), // "on_pushButton_Number_clicked"
QT_MOC_LITERAL(15, 277, 9), // "VoicePlay"
QT_MOC_LITERAL(16, 287, 16), // "setLineEditValue"
QT_MOC_LITERAL(17, 304, 5), // "value"
QT_MOC_LITERAL(18, 310, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(19, 332, 13), // "slotdealImage"
QT_MOC_LITERAL(20, 346, 33) // "on_pushButton_startorstop_cli..."

    },
    "MainWindow\0on_pushButton_readImage_clicked\0"
    "\0on_pushButton_NextImage_clicked\0"
    "on_pushButton_MethodOK_clicked\0"
    "deal_process\0NumErrors\0"
    "on_pushButton_Path_clicked\0"
    "on_waychoose_clicked\0"
    "on_pushButton_LastImage_clicked\0"
    "GMM_training\0defects_laws\0HTuple\0hv_J\0"
    "on_pushButton_Number_clicked\0VoicePlay\0"
    "setLineEditValue\0value\0on_pushButton_clicked\0"
    "slotdealImage\0on_pushButton_startorstop_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    1,   92,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    1,   99,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    1,  104,    2, 0x08 /* Private */,
      18,    0,  107,    2, 0x08 /* Private */,
      19,    0,  108,    2, 0x08 /* Private */,
      20,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 12, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_readImage_clicked(); break;
        case 1: _t->on_pushButton_NextImage_clicked(); break;
        case 2: _t->on_pushButton_MethodOK_clicked(); break;
        case 3: _t->deal_process((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_Path_clicked(); break;
        case 5: _t->on_waychoose_clicked(); break;
        case 6: _t->on_pushButton_LastImage_clicked(); break;
        case 7: _t->GMM_training(); break;
        case 8: { HTuple _r = _t->defects_laws((*reinterpret_cast< HTuple(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< HTuple*>(_a[0]) = _r; }  break;
        case 9: _t->on_pushButton_Number_clicked(); break;
        case 10: _t->VoicePlay(); break;
        case 11: _t->setLineEditValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_pushButton_clicked(); break;
        case 13: _t->slotdealImage(); break;
        case 14: _t->on_pushButton_startorstop_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
