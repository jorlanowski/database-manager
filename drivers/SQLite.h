#pragma once
#include <string>
#include <sqlite3.h>

struct SQLiteConfiguration
{
    SQLiteConfiguration(){}
    SQLiteConfiguration( const char* aName ) { name = aName; } 
    const char* name;
};

class SQLite
{
public:
    typedef SQLiteConfiguration Configuration;
    ~SQLite();

    void configure( SQLiteConfiguration& aConfiguration );

    void execute( std::string aQuery );
private:
    sqlite3 *mDb;
    SQLiteConfiguration mLastConfiguration;

    static int dummyCallback( void *aArgPassed, int aArgc, char** aArgv, char** aColName ){}

};
