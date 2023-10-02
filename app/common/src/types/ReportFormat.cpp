#include "types/ReportFormat.hpp"

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>

std::istream& operator>>(std::istream& in, types::ReportFormat& report_format) {
    std::string token;
    in >> token;

    boost::algorithm::to_lower(token);

    if (token == "json")
        report_format = types::ReportFormat::Json;
    else if (token == "xml")
        report_format = types::ReportFormat::Xml;
    else if (token == "yaml")
        report_format = types::ReportFormat::Yaml;
    else
        in.setstate(std::ios_base::failbit);

    return in;
}