
set(HERO_CONTROLLER_SOURCES
    controller.h
	controller.cpp)

source_group_by_path(${CMAKE_CURRENT_SOURCE_DIR} ${HERO_CONTROLLER_SOURCES})

qt4_auto_wrap(QT4_SOURCES ${HERO_CONTROLLER_SOURCES})

message(STATUS "add static library: hero_controller")
add_library(hero_controller STATIC ${QT4_SOURCES} ${HERO_CONTROLLER_SOURCES})

set_default_target_properties(hero_controller ON)

target_link_libraries(hero_controller
	hero_cmd
	hero_core
	hero_db)
