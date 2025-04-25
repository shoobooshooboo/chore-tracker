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
    "userDataChanged",
    "",
    "householdNamesChanged",
    "householdUsersChanged",
    "curHouseholdChanged",
    "set_household",
    "index",
    "set_chore_status",
    "status",
    "add_chore",
    "name",
    "location",
    "dueDate",
    "doesRecurr",
    "recurrence",
    "username",
    "curHouseholdName",
    "householdNames",
    "QVariantList",
    "householdUsers",
    "choreNames",
    "choreLocations",
    "choreDates",
    "choreStatuses"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN7BackendE[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
       7,   16, // methods
       8,   82, // properties
       0,    0, // enums/sets
       1,  122, // constructors
       0,       // flags
       4,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   58,    4, 0x06,    9 /* Public */,
       5,    0,   59,    4, 0x06,   10 /* Public */,
       6,    0,   60,    4, 0x06,   11 /* Public */,
       7,    0,   61,    4, 0x06,   12 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   62,    4, 0x02,   13 /* Public */,
      10,    2,   65,    4, 0x02,   15 /* Public */,
      12,    5,   70,    4, 0x02,   18 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    9,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString,   13,   14,   15,   16,   17,

 // constructors: parameters
    0x80000000 | 4,

 // properties: name, type, flags, notifyId, revision
      18, QMetaType::QString, 0x00015001, uint(0), 0,
      19, QMetaType::QString, 0x00015001, uint(3), 0,
      20, 0x80000000 | 21, 0x00015009, uint(1), 0,
      22, 0x80000000 | 21, 0x00015009, uint(2), 0,
      23, 0x80000000 | 21, 0x00015009, uint(3), 0,
      24, 0x80000000 | 21, 0x00015009, uint(3), 0,
      25, 0x80000000 | 21, 0x00015009, uint(3), 0,
      26, 0x80000000 | 21, 0x00015009, uint(3), 0,

 // constructors: name, argc, parameters, tag, flags, initial metatype offsets
       0,    0,   81,    4, 0x0e,   24 /* Public */,

       0        // eod
};

Q_CONSTINIT const QMetaObject Backend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN7BackendE.offsetsAndSizes,
    qt_meta_data_ZN7BackendE,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'username'
        QString,
        // property 'curHouseholdName'
        QString,
        // property 'householdNames'
        QVariantList,
        // property 'householdUsers'
        QVariantList,
        // property 'choreNames'
        QVariantList,
        // property 'choreLocations'
        QVariantList,
        // property 'choreDates'
        QVariantList,
        // property 'choreStatuses'
        QVariantList,
        // Q_OBJECT / Q_GADGET
        Backend,
        // method 'userDataChanged'
        void,
        // method 'householdNamesChanged'
        void,
        // method 'householdUsersChanged'
        void,
        // method 'curHouseholdChanged'
        void,
        // method 'set_household'
        void,
        int,
        // method 'set_chore_status'
        void,
        int,
        bool,
        // method 'add_chore'
        void,
        QString,
        QString,
        QString,
        bool,
        QString
    >,
    nullptr
} };

void Backend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Backend *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { Backend *_r = new Backend();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) Backend(); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->userDataChanged(); break;
        case 1: _t->householdNamesChanged(); break;
        case 2: _t->householdUsersChanged(); break;
        case 3: _t->curHouseholdChanged(); break;
        case 4: _t->set_household((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->set_chore_status((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 6: _t->add_chore((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (Backend::*)();
            if (_q_method_type _q_method = &Backend::userDataChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (Backend::*)();
            if (_q_method_type _q_method = &Backend::householdNamesChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (Backend::*)();
            if (_q_method_type _q_method = &Backend::householdUsersChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (Backend::*)();
            if (_q_method_type _q_method = &Backend::curHouseholdChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->get_user_name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->get_cur_household_name(); break;
        case 2: *reinterpret_cast< QVariantList*>(_v) = _t->getHouseholdNames(); break;
        case 3: *reinterpret_cast< QVariantList*>(_v) = _t->getHouseholdUsers(); break;
        case 4: *reinterpret_cast< QVariantList*>(_v) = _t->getChoreNames(); break;
        case 5: *reinterpret_cast< QVariantList*>(_v) = _t->getChoreLocations(); break;
        case 6: *reinterpret_cast< QVariantList*>(_v) = _t->getChoreDates(); break;
        case 7: *reinterpret_cast< QVariantList*>(_v) = _t->getChoreStatuses(); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Backend::userDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Backend::householdNamesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Backend::householdUsersChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Backend::curHouseholdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
