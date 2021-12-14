cmake_minimum_required(VERSION 3.19)
project(implementation)
find_package(OpenCL REQUIRED)
set (CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\")
#set (QT_PLUGIN_PATH="C:\\Qt\\5.15.2\\mingw81_64\\plugins")
#set (QML2_IMPORT_PATH="C:\\Qt\\5.15.2\\mingw81_64\\qml")
set(COMMANDS
        commands/command.hpp
        commands/camera/camera_commands.cpp
        commands/camera/camera_commands.hpp
        commands/model/model_commands.cpp
        commands/model/model_commands.hpp
        commands/scene/scene_commands.cpp
        commands/scene/scene_commands.hpp
        commands/light/light_commands.cpp
        commands/light/light_commands.hpp
        )

set(DRAWER
        drawer/drawer.hpp
        )

set(EXCEPTIONS
        exceptions/base_exception.hpp
        exceptions/load_exceptions.hpp
        exceptions/model_exceptions.hpp
        exceptions/camera_exceptions.hpp
        exceptions/ui_exceptions.hpp
        )

set(FACADE
        facade/facade.hpp
        facade/facade.cpp
        )

set(LOAD
        load/loaders/loader_creator.hpp
        load/loaders/loaders.cpp
        load/loaders/loaders.hpp
        load/loaders/base/base_loader.cpp
        load/loaders/base/base_loader.hpp
        )

set(MANAGERS
        managers/manager.hpp
        managers/draw/draw_manager.cpp
        managers/draw/draw_manager.hpp
        managers/load/load_manager.cpp
        managers/load/load_manager.hpp
        managers/scene/scene_manager.cpp
        managers/scene/scene_manager.hpp
        )

set(OBJECTS
        objects/material/material.hpp
        objects/material/material.cpp
        objects/object.hpp
        objects/camera/camera.cpp
        objects/camera/camera.hpp
        objects/light/light.cpp
        objects/light/light.hpp
        objects/model/figure.cpp
        objects/model/figure.hpp
        objects/model/sphere.cpp
        objects/model/sphere.hpp
        objects/model/trismodel.cpp
        objects/model/trismodel.hpp
        )

set(SCENE
        scene/scene.cpp
        scene/scene.hpp
        )

set(MATH
        math/linalg.hpp
        math/rays.hpp
        math/rays_handling.cpp
        math/rays_handling.hpp
        math/linalg.cpp)

set (RAYTRACER
        raytracer/raytracer.cpp
        raytracer/raytracer.hpp
        ../consts.hpp
        )

set (RAY
        ray/ray.cpp
        ray/ray.hpp
        )
#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)
find_package(OpenCL REQUIRED)
find_package(OpenMP REQUIRED)
#find_package(Boost 1.60.0 REQUIRED COMPONENTS filesystem)
#message(STATUS "Boost version: ${Boost_VERSION}")


add_library(${PROJECT_NAME}
        ${COMMANDS}
        ${DRAWER}
        ${EXCEPTIONS}
        ${FACADE}
        ${LOAD}
        ${MANAGERS}
        ${OBJECTS}
        ${SCENE}
        ${MATH}
        ${RAYTRACER}
        ${RAY}
        )

target_link_libraries(${PROJECT_NAME} PUBLIC
        OpenCL::OpenCL
        OpenMP::OpenMP_CXX
#        Boost::filesystem
        ${REQUIRED_LIBS_QUALIFIED}
        )

target_include_directories(${PROJECT_NAME} PUBLIC ../implementation)

#find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
