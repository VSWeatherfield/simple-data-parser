#include "types/StorageFormat.hpp"

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>

std::istream& operator>>(std::istream& in, types::StorageFormat& storage_format) {
    std::string token;
    in >> token;

    boost::algorithm::to_lower(token);

    if (token == "txt")
        storage_format = types::StorageFormat::txt;
    else if (token == "sqlite")
        storage_format = types::StorageFormat::sqlite;
    else if (token == "-")
        storage_format = types::StorageFormat::dummy;
    else
        in.setstate(std::ios_base::failbit);

    return in;
}