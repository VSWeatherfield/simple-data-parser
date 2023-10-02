#pragma once

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>

namespace types {
enum class StorageFormat { txt, sqlite, dummy };
}

std::istream& operator>>(std::istream&, types::StorageFormat&);