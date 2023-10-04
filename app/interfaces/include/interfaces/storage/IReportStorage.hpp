#pragma once

#include <optional>
#include <string>

#include "types/Report.hpp"

namespace storage {
class IReportStorage {
   public:
    virtual ~IReportStorage() = default;
    virtual void storeReport(const types::Report& report) const = 0;
};
}  // namespace storage