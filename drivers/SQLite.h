#pragma once
#include <string>
#include <sqlite3.h>

struct SQLiteConfiguration
{
    SQLiteConfiguration(){}
    SQLiteConfiguration( const char* ) {} 
    const char* name;
};

class SQLite
{
public:
    typedef SQLiteConfiguration Configuration;
    ~SQLite();

    void configure( Configuration& aConfiguration );

    void execute( std::string aQuery );
private:
    sqlite3 *mDb;
    Configuration mLastConfiguration;

    static int dummyCallback( void *aArgPassed, int aArgc, char** aArgv, char** aColName ){}

};
