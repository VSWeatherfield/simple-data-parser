#pragma once

#include "storage/IReportStorage.hpp"

namespace storage {
class DummyStorage : public IReportStorage {
   public:
    void storeReport(const types::Report& report) const override;
};
}  // namespace storage