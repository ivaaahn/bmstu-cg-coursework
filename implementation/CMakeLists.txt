cmake_minimum_required(VERSION 3.19)
project(implementation)

set(COMMANDS
        commands/command.hpp
        commands/camera/camera_commands.cpp
        commands/camera/camera_commands.hpp
        commands/model/model_commands.cpp
        commands/model/model_commands.hpp
        commands/scene/scene_commands.cpp
        commands/scene/scene_commands.hpp
        commands/light/light_commands.cpp commands/light/light_commands.hpp)


set(CONFIG_MANAGER
#        config_manager/creator/config_manager_creator.hpp
#        config_manager/creator/config_manager_creator.cpp
#        config_manager/registration/registration_maker.hpp
#        config_manager/registration/registration_maker.cpp
#        config_manager/solution/solution.hpp
#        config_manager/solution/solution.cpp
#        config_manager/config_manager.hpp
#        config_manager/config_manager.cpp
        )

set(DRAWER
        drawer/drawer.hpp)

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
#        load/builders/camera/camera_builder.cpp
#        load/builders/camera/camera_builder.hpp
#        load/builders/model/model_builder.cpp
#        load/builders/model/model_builder.hpp
#        load/directors/load_director.hpp
#        load/directors/camera/camera_director.cpp
#        load/directors/camera/camera_director.hpp
#        load/directors/model/model_director.cpp
#        load/directors/model/model_director.hpp
#        load/solutions/camera/camera_load_solution.cpp
#        load/solutions/camera/camera_load_solution.hpp
#        load/solutions/model/model_load_solution.cpp
#        load/solutions/model/model_load_solution.hpp
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
#        managers/transform/transform_manager.cpp
#        managers/transform/transform_manager.hpp
        )

set(OBJECTS
        objects/material/material.hpp
        objects/material/material.cpp
        objects/object.hpp
        objects/camera/camera.cpp
        objects/camera/camera.hpp
        objects/light/light.cpp
        objects/light/light.hpp
#        objects/composite/composite.cpp
#        objects/composite/composite.hpp
#        objects/model/model.cpp
#        objects/model/model.hpp
#        objects/model/model_details/model_details.cpp
#        objects/model/model_details/model_details.hpp
#        objects/model/model_details/point/point.hpp
#        objects/model/model_details/point/point.cpp
#        objects/model/model_details/edge/edge.hpp
#        objects/model/model_details/edge/edge.cpp
        objects/model/figure.cpp objects/model/figure.hpp
#        objects/model/figure_data.cpp objects/model/figure_data.hpp
        objects/model/sphere.cpp objects/model/sphere.hpp)

set(SCENE
        scene/scene.cpp
        scene/scene.hpp
        )

set(MATH
        math/linalg.hpp
        math/rays.hpp)

set(VISITOR
#        visitor/visitor.hpp
#        visitor/draw_visitor/draw_visitor.cpp
#        visitor/draw_visitor/draw_visitor.hpp
        exceptions/camera_exceptions.hpp
        math/rays_handling.cpp math/rays_handling.hpp)


add_library(${PROJECT_NAME}
        ${COMMANDS}
        ${CONFIG_MANAGER}
        ${DRAWER}
        ${EXCEPTIONS}
        ${FACADE}
        ${LOAD}
        ${MANAGERS}
        ${OBJECTS}
        ${SCENE}
        ${VISITOR}
        ${MATH}
        )

target_include_directories(${PROJECT_NAME} PUBLIC ../implementation)
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)