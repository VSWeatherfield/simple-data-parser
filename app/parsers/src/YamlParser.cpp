#include "parsers/YamlParser.hpp"

#include <iostream>
#include <stdexcept>

#include "yaml-cpp/yaml.h"

namespace parsers {

std::optional<types::Report> YamlParser::parseReport(
    const std::string_view rawReport) const {
    try {
        const YAML::Node node = YAML::Load(rawReport.data());

        if (!node.IsNull() && node.IsMap()) {
            const auto payer = node["payer"].as<std::uint32_t>();
            const auto tax = node["tax"].as<std::string>();
            const auto amount = node["amount"].as<double>();
            const auto year = node["year"].as<std::uint16_t>();

            return types::Report{payer, tax, amount, year};
        }

        return std::nullopt;
    } catch (const std::exception& e) {
        std::cerr << __FILE__ << ' ' << e.what() << '\n';
        return std::nullopt;
    }
}

std::optional<types::User> YamlParser::parseCredentials(
    const std::string_view rawCredentials) const {
    try {
        const YAML::Node node = YAML::Load(rawCredentials.data());

        if (!node.IsNull() && node.IsMap()) {
            const auto login = node["login"].as<std::string>();
            const auto password = node["password"].as<std::string>();

            return types::User{login, password};
        }

        return std::nullopt;
    } catch (const std::exception& e) {
        std::cerr << __FILE__ << ' ' << e.what() << '\n';
        return std::nullopt;
    }
}

}  // namespace parsers