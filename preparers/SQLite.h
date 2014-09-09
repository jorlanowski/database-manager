#pragma once
#include <string>

namespace preparer
{
class SQLite
{
public:
    template< typename T >
    std::string prepareInsert( T& );

    template< typename T >
    std::string prepareUpdate( T& );

    template< typename T >
    std::string prepareSelect( T& );

    template< typename T >
    std::string prepareRemove( T& );
private:
    template< typename T >
    std::string tableName( );
};
}

#include "SQLite.tpp"
