cmake_minimum_required(VERSION 3.2)

project(dpiaware)

set(sources
    ${CMAKE_CURRENT_SOURCE_DIR}/src/metrics.c
)

if (MSVC)

elseif (UNIX)

    find_path(X11_INCL NAMES Xlib.h REQUIRED)
    find_library(X11_LIBS NAMES libX11.a REQUIRED)
    message(STATUS ${X11_INCL})
    
    set(dpiaware_incl
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${X11_INCL}   
    )

    set(dpiaware_libs
        ${X11_LIBS}   
    )

endif()


add_library(${PROJECT_NAME} STATIC ${sources})
target_include_directories(${PROJECT_NAME} PRIVATE ${dpiaware_incl})
target_link_libraries(${PROJECT_NAME} PRIVATE ${dpiaware_libs})

