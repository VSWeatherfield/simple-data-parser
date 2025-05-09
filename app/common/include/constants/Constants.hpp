#pragma once

#include <string>
#include <unordered_set>

namespace constants {
const std::string OK = "OK";
const std::string NOK = "NOK";

const std::unordered_set<std::string> validTaxNames = {
    "corporate income tax", "individual income tax", "value added tax",
    "withholding tax"
    "property tax",
    "exit tax"};
}  // namespace constants