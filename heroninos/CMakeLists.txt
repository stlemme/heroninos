
set(HERONINOS_SOURCES
	heroninos.cpp
	stable.h
	stable.cpp
	gui/cmdhighlighter.h
	gui/cmdhighlighter.cpp
	gui/cmdtextedit.h
	gui/cmdtextedit.cpp
	gui/shellwidget.h
	gui/shellwidget.cpp
	gui/shellwidget.ui)

source_group_by_path(${CMAKE_CURRENT_SOURCE_DIR} ${HERONINOS_SOURCES})

qt4_auto_wrap(QT4_SOURCES ${HERONINOS_SOURCES})
setup_stable(${HERONINOS_SOURCES} ${QT4_SOURCES})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "add executable: heroninos")
add_executable(heroninos ${QT4_SOURCES} ${HERONINOS_SOURCES})

set_default_target_properties(heroninos ON)

target_link_libraries(heroninos
	hero_controller
	${QT_QTMAIN_LIBRARY}
    ${QT_QTCORE_LIBRARY}
    ${QT_QTGUI_LIBRARY})
