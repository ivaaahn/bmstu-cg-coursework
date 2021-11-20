cmake_minimum_required(VERSION 3.19)
project(cg-coursework)
set (CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\")
#set (QT_PLUGIN_PATH "C:\\Qt\\5.15.2\\mingw81_64\\plugins")
#set (QML2_IMPORT_PATH "C:\\Qt\\5.15.2\\mingw81_64\\qml")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets )

add_executable(${PROJECT_NAME}
        main.cpp
        gui/qt/mainwindow.cpp
        gui/qt/mainwindow.h
        gui/qt/design.h
        gui/qt/drawer/qt_drawer.cpp
        gui/qt/drawer/qt_drawer.hpp
        gui/qt/drawer/factory/qt_drawer_factory.hpp
        gui/qt/drawer/factory/qt_drawer_factory.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        ./implementation
        ./gui/qt/)


#find_package(OpenMP REQUIRED)
find_package(OpenCL REQUIRED)
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)


target_link_libraries(${PROJECT_NAME} PUBLIC
        OpenCL::OpenCL
#        OpenMP::OpenMP_CXX
        ${REQUIRED_LIBS_QUALIFIED}
        implementation
        )
add_subdirectory(./implementation)

#target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX)
#target_link_libraries(${PROJECT_NAME} gdi32)

