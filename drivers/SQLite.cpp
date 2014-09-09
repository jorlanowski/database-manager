#include "SQLite.h"
#include <iostream>

SQLite::~SQLite()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    int lStatus;
    if ( mDb ) // TODO: check if mDb cannot be a rubbish
    {
        lStatus = sqlite3_close( mDb );
        // TODO: handle lStatus
    }
}

void SQLite::configure( SQLiteConfiguration& aConfiguration )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    int lStatus;
    // TODO: check if mDb is not already initialized
    lStatus = sqlite3_open( aConfiguration.name, &mDb );
    // TODO: handle errors
}

void SQLite::execute( std::string aQuery )
{
    std::cout << __PRETTY_FUNCTION__ << " " << aQuery << std::endl;
    int lStatus;
    char *lErrMsg = 0;
    int lCallbackArgument = 0;
    lStatus = sqlite3_exec( mDb, aQuery.c_str(), &SQLite::dummyCallback,
                            (void*)lCallbackArgument, &lErrMsg );
    std::cout << __PRETTY_FUNCTION__ << " " << lErrMsg << std::endl;

    sqlite3_free( lErrMsg );
}
