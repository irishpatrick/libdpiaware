cmake_minimum_required(VERSION 3.2)

project(dpiaware)

set(sources
    ${CMAKE_CURRENT_SOURCE_DIR}/src/control.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/metrics.c
)

if (MSVC)

elseif (UNIX)

    find_package(PkgConfig)

    pkg_check_modules(X11 REQUIRED x11)

    find_path(X11_INCL NAMES Xlib.h REQUIRED)
    find_library(X11_LIBS NAMES libX11.a REQUIRED)
    find_library(XCB_LIBS NAMES libxcb.a REQUIRED)
    find_library(XAU_LIBS NAMES libXau.a REQUIRED)
    find_library(XDMCP_LIBS NAMES libXdmcp.a REQUIRED)
    find_library(DL_LIBS NAMES libdl.a REQUIRED)
    
    set(dpiaware_incl
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${X11_INCLUDE_DIRECTORIES}
    )

    set(dpiaware_libs
        ${X11_LIBRARIES}
    )

endif()


add_library(${PROJECT_NAME} STATIC ${sources})
target_include_directories(${PROJECT_NAME} PRIVATE ${dpiaware_incl})
target_link_libraries(${PROJECT_NAME} PRIVATE ${dpiaware_libs})

