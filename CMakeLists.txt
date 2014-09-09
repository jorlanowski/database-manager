cmake_minimum_required( VERSION 2.8 )

project( database-manager )

set( TARGET
    ${PROJECT}
)

set( SOURCES
    USAGE_DatabaseManager.cpp
    drivers/SQLite.cpp
)

#add_library(
#    ${PROJECT}
#    SHARED
#    ${SOURCES}
#)
include_directories("${PROJECT_SOURCE_DIR}/drivers")
include_directories( "${PROJECT_SOURCE_DIR}" )
add_subdirectory( drivers )
add_subdirectory( preparers )
add_executable(
    database-manager
    ${SOURCES}
)

target_link_libraries( database-manager SQLITE3 )
