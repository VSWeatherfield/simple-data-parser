#pragma once

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>

namespace types {
enum class ReportFormat { Json, Xml };
}

std::istream& operator>>(std::istream&, types::ReportFormat&);