#pragma once

template< typename T >
struct Filter
{
};

template< typename DBDriver, typename DBPreparer, typename ErrorHandlePolicy >
class DatabaseManager : public DBDriver, public DBPreparer, public ErrorHandlePolicy
{
typedef typename DBDriver::Configuration Configuration;
public:

    bool configure( Configuration& );

    template< typename T >
    bool add( T& aObject );

    template< typename T >
    bool update( T& aObject );

    template< typename T >
    bool get( T& aObject, Filter< T >& aFilter );

    template< typename T >
    bool remove( T& aObject );
};

template< typename DBDriver, typename DBPreparer, typename ErrorHandlePolicy >
template< typename T >
bool DatabaseManager< DBDriver, DBPreparer, ErrorHandlePolicy >::add( T& x )
{
    DBDriver::execute( DBPreparer::prepareInsert( x ) );
}

template< typename DBDriver, typename DBPreparer, typename ErrorHandlePolicy >
bool DatabaseManager< DBDriver, DBPreparer, ErrorHandlePolicy >::configure( Configuration& aConfiguration )
{
    DBDriver::configure( aConfiguration );
}
