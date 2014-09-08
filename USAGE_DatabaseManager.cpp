#include "DatabaseManager.h"
#include "drivers/SQLite.h"
#include <string>

namespace SQLiteNamespace
{
    class Preparer
    {
    public:
        template< typename T >
        std::string prepareInsert( T& ) { return std::string(); }
    };

    class ErrorHandler
    {
    };
}


struct MyObject
{
    unsigned int id;
    char* name;
};

typedef SQLite DatabaseType;
typedef SQLiteNamespace::Preparer Preparer;
typedef SQLite::Configuration DatabaseConfiguration;
typedef SQLiteNamespace::ErrorHandler ErrorHandler;
int main()
{
    MyObject myObject;

    
    DatabaseManager<DatabaseType, Preparer, ErrorHandler> dbm;
    DatabaseConfiguration configuration( "FILE_NAME" );

    dbm.configure( configuration );
//    dbm.initialize( configuration );

    myObject.id = 1;
    myObject.name = "Some name";
    
    dbm.add( myObject );
    return 0;
}
