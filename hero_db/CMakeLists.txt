
set(HERO_DB_SOURCES
	migration.h
	migration.cpp
    sessionaccess.h
	sessionaccess.cpp)

source_group_by_path(${CMAKE_CURRENT_SOURCE_DIR} ${HERO_DB_SOURCES})

qt4_auto_wrap(QT4_SOURCES ${HERO_DB_SOURCES})

message(STATUS "add static library: hero_db")
add_library(hero_db STATIC ${QT4_SOURCES} ${HERO_DB_SOURCES})

set_default_target_properties(hero_db ON)

target_link_libraries(hero_db
	${QT_USE_QTSQL})
