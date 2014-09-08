#include "DatabaseManager.h"
#include <string>

namespace SQLite
{
    class SQLite
    {
    public:
        class Configuration
        {
        public:
            Configuration(){}
            Configuration( const char* ) {} 
        };
        void insert( std::string ){}
    };

    class Preparer
    {
    public:
        template< typename T >
        std::string prepare( T& ) { return std::string(); }
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

typedef SQLite::SQLite DatabaseType;
typedef SQLite::Preparer Preparer;
typedef SQLite::SQLite::Configuration DatabaseConfiguration;
typedef SQLite::ErrorHandler ErrorHandler;
int main()
{
    MyObject myObject;

    
    DatabaseManager<DatabaseType, Preparer, ErrorHandler> dbm;
    DatabaseConfiguration configuration( "FILE_NAME" );

//    dbm.initialize( configuration );

    myObject.id = 1;
    myObject.name = "Some name";
    
    dbm.add( myObject );
    return 0;
}
