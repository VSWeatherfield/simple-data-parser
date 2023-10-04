#pragma once

#include <cstdint>
#include <optional>

#include "types/ReportFormat.hpp"
#include "types/StorageFormat.hpp"

struct StartupConfig {
    const std::uint16_t port;
    const types::ReportFormat report_format;
    const types::StorageFormat storage_format;
};

std::optional<const StartupConfig> optionsToStartupConfig(int argc,
                                                          char* argv[]);