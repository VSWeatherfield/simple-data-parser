#pragma once

#include <memory>

#include "storage/IReportStorage.hpp"

namespace storage {
class IStorageFactory {
   public:
    virtual ~IStorageFactory() = default;
    virtual std::unique_ptr<IReportStorage> createReportStorage() const = 0;
};
}  // namespace storage