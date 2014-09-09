#install( FILES
#            createTables.sql
#         DESTINATION
#            ${PROJECT_BINARY_DIR} )
add_custom_target( sql ALL
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/*.sql ${PROJECT_BINARY_DIR}
)

