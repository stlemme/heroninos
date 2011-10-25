
set(HERO_CMD_SOURCES
    abstractcmd.h
    abstractcmd.cpp
    abstractcmdargument.h
    abstractcmdargument.cpp
    abstractcmdfragment.h
    abstractcmdfragment.cpp
    variantcmdflag.h
    variantcmdflag.cpp
    arg_filepath.h
    arg_filepath.cpp
    arg_passphrase.h
    arg_passphrase.cpp
    cmd_make.h
    cmd_make.cpp)

source_group_by_path(${CMAKE_CURRENT_SOURCE_DIR} ${HERO_CMD_SOURCES})

qt4_auto_wrap(QT4_SOURCES ${HERO_CMD_SOURCES})

message(STATUS "add static library: hero_cmd")
add_library(hero_cmd STATIC ${QT4_SOURCES} ${HERO_CMD_SOURCES})

set_default_target_properties(hero_cmd ON)
