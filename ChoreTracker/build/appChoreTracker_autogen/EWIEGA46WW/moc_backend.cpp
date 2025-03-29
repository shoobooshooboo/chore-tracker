/****************************************************************************
** Meta object code from reading C++ file 'backend.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../backend.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN7BackendE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN7BackendE = QtMocHelpers::stringData(
    "Backend",
    "QML.Element",
    "auto",
    "toggledCount_changed",
    "",
    "choresList_changed",
    "dynamicText_changed",
    "increment_toggledCount",
    "get_chores_count",
    "get_chore",
    "index",
    "toggledCount",
    "choresList",
    "std::vector<QString>",
    "dynamicText"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN7BackendE[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
       6,   16, // methods
       3,   60, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   52,    4, 0x06,    4 /* Public */,
       5,    0,   53,    4, 0x06,    5 /* Public */,
       6,    0,   54,    4, 0x06,    6 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   55,    4, 0x02,    7 /* Public */,
       8,    0,   56,    4, 0x02,    8 /* Public */,
       9,    1,   57,    4, 0x02,    9 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,   10,

 // properties: name, type, flags, notifyId, revision
      11, QMetaType::QString, 0x00015001, uint(0), 0,
      12, 0x80000000 | 13, 0x00015009, uint(1), 0,
      14, QMetaType::QString, 0x00015003, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Backend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN7BackendE.offsetsAndSizes,
    qt_meta_data_ZN7BackendE,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'toggledCount'
        QString,
        // property 'choresList'
        std::vector<QString>,
        // property 'dynamicText'
        QString,
        // Q_OBJECT / Q_GADGET
        Backend,
        // method 'toggledCount_changed'
        void,
        // method 'choresList_changed'
        void,
        // method 'dynamicText_changed'
        void,
        // method 'increment_toggledCount'
        void,
        // method 'get_chores_count'
        int,
        // method 'get_chore'
        QString,
        int
    >,
    nullptr
} };

void Backend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Backend *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->toggledCount_changed(); break;
        case 1: _t->choresList_changed(); break;
        case 2: _t->dynamicText_changed(); break;
        case 3: _t->increment_toggledCount(); break;
        case 4: { int _r = _t->get_chores_count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->get_chore((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (Backend::*)();
            if (_q_method_type _q_method = &Backend::toggledCount_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (Backend::*)();
            if (_q_method_type _q_method = &Backend::choresList_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (Backend::*)();
            if (_q_method_type _q_method = &Backend::dynamicText_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->get_toggledCount(); break;
        case 1: *reinterpret_cast< std::vector<QString>*>(_v) = _t->get_choresList(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->get_dynamicText(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->set_dynamicText(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Backend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Backend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN7BackendE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Backend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Backend::toggledCount_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Backend::choresList_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Backend::dynamicText_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
