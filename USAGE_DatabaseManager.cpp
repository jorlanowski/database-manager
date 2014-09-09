#include "DatabaseManager.h"
#include "drivers/SQLite.h"
#include "preparers/SQLite.h"
#include "preparers/SQLite.tpp"
#include "sample_structs/MyObject.h"

#include <string>

namespace SQLiteNamespace
{
    class ErrorHandler
    {
    };
}

typedef SQLite DatabaseType;
typedef preparer::SQLite Preparer;
typedef SQLite::Configuration DatabaseConfiguration;
typedef SQLiteNamespace::ErrorHandler ErrorHandler;
int main()
{
    MyObject myObject;

    DatabaseManager<DatabaseType, Preparer, ErrorHandler> dbm;
    DatabaseConfiguration configuration( "database.sqlite" );

    dbm.configure( configuration );

    myObject.id = 1;
    myObject.name = "Some name";

    dbm.add( myObject );
    return 0;
}
