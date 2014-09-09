SET( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSQLITE_THREADSAFE=0" )
add_library( SQLITE3 sqlite3.c )
target_link_libraries( SQLITE3 dl )
