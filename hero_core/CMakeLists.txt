
set(HERO_CORE_SOURCES
	abstractsessionaccess.h
    session.h
	session.cpp)

source_group_by_path(${CMAKE_CURRENT_SOURCE_DIR} ${HERO_CORE_SOURCES})

qt4_auto_wrap(QT4_SOURCES ${HERO_CORE_SOURCES})

message(STATUS "add static library: hero_core")
add_library(hero_core STATIC ${QT4_SOURCES} ${HERO_CORE_SOURCES})

set_default_target_properties(hero_core ON)
