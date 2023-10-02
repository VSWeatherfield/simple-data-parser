#pragma once

#include <type_traits>

#include "storage/IReportStorage.hpp"

namespace storage {
template <typename BaseReportStorage>
class ValidatedReportStorage : public BaseReportStorage {
   public:
    static_assert(std::is_base_of<IReportStorage, BaseReportStorage>::value);

    void storeReport(const types::Report& report) const override;

   private:
    std::string filePath;
};
}  // namespace storage