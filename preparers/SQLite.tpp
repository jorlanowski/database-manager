#pragma once
#include "sample_structs/MyObject.h"
#include <sstream>

namespace preparer
{
template< >
std::string SQLite::tableName<MyObject>( )
{
    return "MyObjects";
}

template< >
std::string SQLite::prepareInsert( MyObject& aObject )
{
    std::stringstream lStream;
    lStream << "INSERT INTO " << tableName<MyObject>() << " VALUES(" << aObject.id << ",'" << aObject.name << "');";
    return lStream.str();
}


}
