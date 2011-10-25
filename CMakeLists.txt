
cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)

# macros

macro(QT4_AUTO_WRAP outfiles)

    set(moc_headers "")
    set(ui_files "")
    set(qrc_files "")

    foreach(fileName ${ARGV})

        if(fileName MATCHES "\\.h$")
            FILE(STRINGS ${fileName} lines REGEX Q_OBJECT)
            IF(lines)
                LIST(APPEND moc_headers ${fileName})
                MESSAGE(STATUS "moc: ${fileName}")
            endif()
        endif()
        
        if(fileName MATCHES "\\.ui$")
            LIST(APPEND ui_files ${fileName})
            MESSAGE(STATUS "uic: ${fileName}")
        endif()

        if(fileName MATCHES "\\.qrc$")
            LIST(APPEND qrc_files ${fileName})
            MESSAGE(STATUS "qrc: ${fileName}")
        endif()

    endforeach()

    qt4_wrap_cpp(mocGeneratedByHeader ${moc_headers})
    qt4_wrap_ui(uicGenerated ${ui_files})

    qt4_add_resources(mocGeneratedByRessources ${qrc_files})

    list(APPEND ${outfiles}
        ${uicGenerated}
        ${mocGeneratedByHeader} 
        ${mocGeneratedByRessources})

    source_group("_ Qt Generated" FILES 
        ${uicGenerated}
        ${mocGeneratedByHeader}
        ${mocGeneratedByRessources})

    source_group("_ CMake Rules" REGULAR_EXPRESSION "rule$")

endmacro()


macro(SOURCE_GROUP_BY_PATH parent_path)

    foreach(filename ${ARGV})
    
        get_filename_component(path "${filename}" REALPATH)
        file(RELATIVE_PATH path ${parent_path} ${path})
        get_filename_component(path "${path}" PATH)
        string(REPLACE "/" "\\" path "${path}")

        if(${filename} MATCHES "h$|hpp$|cpp$|c$|cu$|ui$|qrc$|vsf$|fsf$")
            SOURCE_GROUP("${path}" FILES ${filename})
        endif()

    endforeach()

endmacro()


macro(SETUP_STABLE)

    foreach(arg in ${ARGV})
        LIST(APPEND sources ${arg})
    endforeach()

    set_source_files_properties(${sources}
        PROPERTIES
        COMPILE_FLAGS "/FIstable.h /Yustable.h")

    set_source_files_properties(stable.cpp
        PROPERTIES
        COMPILE_FLAGS "/Ycstable.h")

endmacro()


macro(SET_DEFAULT_TARGET_PROPERTIES target w4)

    if(MSVC)

        if(w4)
            SET_TARGET_PROPERTIES(${target}
                PROPERTIES
                COMPILE_FLAGS "/W4 /arch:SSE2 /fp:fast /Ot /GS-"
                LINK_FLAGS_DEBUG "/NODEFAULTLIB:msvcrt"
                DEBUG_POSTFIX "d${DEBUG_POSTFIX}")
        else(w4)
            SET_TARGET_PROPERTIES(${target}
                PROPERTIES
                COMPILE_FLAGS "/arch:SSE2 /fp:fast /Ot /GS-"
                LINK_FLAGS_DEBUG "/NODEFAULTLIB:msvcrt"
                DEBUG_POSTFIX "d${DEBUG_POSTFIX}")
        endif()

    else(MSVC)

        SET_TARGET_PROPERTIES(${target}
            PROPERTIES
            DEBUG_POSTFIX "d${DEBUG_POSTFIX}")

    endif()

endmacro()

# config

set(PROJECT_NAME heroninos)

project(${PROJECT_NAME} C CXX)

set(VERSION_MAJOR "0" CACHE STRING "${PROJECT_NAME} Major Version")
set(VERSION_MINOR "0" CACHE STRING "${PROJECT_NAME} Minor Version")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

# 3rdp and resources

find_package(Qt4)

include_directories(
    ${CMAKE_BINARY_DIR}
	${CMAKE_SOURCE_DIR}
    ${QT_INCLUDES})
	
# 

add_subdirectory("hero_cmd")
add_subdirectory("hero_controller")
add_subdirectory("hero_core")
add_subdirectory("hero_db")
#add_subdirectory("hero_vis")

add_subdirectory("heroninos")