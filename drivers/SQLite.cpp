#include "SQLite.h"

SQLite::~SQLite()
{
    int lStatus;
    if ( mDb ) // TODO: check if mDb cannot be a rubbish
    {
        lStatus = sqlite3_close( mDb );
        // TODO: handle lStatus
    }
}

void SQLite::configure( Configuration& aConfiguration )
{
    int lStatus;
    // TODO: check if mDb is not already initialized
    lStatus = sqlite3_open( aConfiguration.name, &mDb );
    // TODO: handle errors
}

void SQLite::execute( std::string aQuery ) 
{
    int lStatus;
    char *lErrMsg = 0;
    int lCallbackArgument = 0;
    lStatus = sqlite3_exec( mDb, aQuery.c_str(), &SQLite::dummyCallback, (void*)lCallbackArgument, &lErrMsg );
}
