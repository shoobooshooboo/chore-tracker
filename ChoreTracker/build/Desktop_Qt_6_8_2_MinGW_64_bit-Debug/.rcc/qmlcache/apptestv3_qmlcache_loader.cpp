#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>
#include <QtCore/qhash.h>
#include <QtCore/qstring.h>

namespace QmlCacheGeneratedCode {
<<<<<<< HEAD:ChoreTracker/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/.rcc/qmlcache/appChoreTracker_qmlcache_loader.cpp
namespace _qt_qml_ChoreTracker_Main_qml { 
=======
namespace _qt_qml_testv3_Main_ui_0x2e_qml { 
>>>>>>> b5a4fc4ff8ae2e6355af27a8887777500d5a6988:ChoreTracker/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/.rcc/qmlcache/apptestv3_qmlcache_loader.cpp
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_testv3_Settings_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
<<<<<<< HEAD:ChoreTracker/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/.rcc/qmlcache/appChoreTracker_qmlcache_loader.cpp
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/ChoreTracker/Main.qml"), &QmlCacheGeneratedCode::_qt_qml_ChoreTracker_Main_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/ChoreTracker/Settings.qml"), &QmlCacheGeneratedCode::_qt_qml_ChoreTracker_Settings_qml::unit);
=======
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/testv3/Main.ui.qml"), &QmlCacheGeneratedCode::_qt_qml_testv3_Main_ui_0x2e_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/testv3/Settings.qml"), &QmlCacheGeneratedCode::_qt_qml_testv3_Settings_qml::unit);
>>>>>>> b5a4fc4ff8ae2e6355af27a8887777500d5a6988:ChoreTracker/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/.rcc/qmlcache/apptestv3_qmlcache_loader.cpp
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.structVersion = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qmlcache_apptestv3)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qmlcache_apptestv3))
int QT_MANGLE_NAMESPACE(qCleanupResources_qmlcache_apptestv3)() {
    return 1;
}
