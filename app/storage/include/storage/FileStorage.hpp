#pragma once

#include "storage/IReportStorage.hpp"

namespace storage {
class FileStorage : public IReportStorage {
   public:
    void storeReport(const types::Report& report) const override;

   private:
    std::optional<std::ofstream> open() const;
};
}  // namespace storage