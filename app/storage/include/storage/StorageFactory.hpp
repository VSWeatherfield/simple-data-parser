#pragma once

#include <memory>

#include "storage/IStorageFactory.hpp"
#include "types/StorageFormat.hpp"

namespace storage {
class StorageFactory : public IStorageFactory {
   public:
    StorageFactory(const types::StorageFormat);
    std::unique_ptr<IReportStorage> createReportStorage() const override;

   private:
    const types::StorageFormat storageFormat;
};
}  // namespace storage