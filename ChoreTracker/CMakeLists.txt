cmake_minimum_required(VERSION 3.16)

project(ChoreTracker VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

find_package(Qt6 REQUIRED COMPONENTS Widgets Quick Core)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appChoreTracker
    main.cpp
)

qt_add_qml_module(appChoreTracker
    URI ChoreTracker
    VERSION 1.0
    QML_FILES
    Main.qml
        RESOURCES qmldir
        QML_FILES Settings.qml
        QML_FILES Household.qml
        QML_FILES WindowManager.qml
        SOURCES backend.h backend.cpp

            chore.hpp chore.cpp
            encryption.hpp encryption.cpp
            household.hpp household.cpp
            household_manager.hpp household_manager.cpp
            user.hpp user.cpp
            user_manager.hpp user_manager.cpp
            settings_configuration.hpp
        RESOURCES houseFile.csv userFile.csv
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appChoreTracker PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appChoreTracker
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appChoreTracker
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Core
)

include(GNUInstallDirs)
install(TARGETS appChoreTracker
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
