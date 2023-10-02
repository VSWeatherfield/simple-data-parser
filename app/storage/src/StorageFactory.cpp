#include "storage/StorageFactory.hpp"

#include "storage/DummyStorage.hpp"
#include "storage/FileStorage.hpp"
#include "storage/SQLiteStorage.hpp"
#include "storage/ValidatedReportStorage.hpp"

namespace storage {
StorageFactory::StorageFactory(const types::StorageFormat storageFormat)
    : storageFormat{storageFormat} {}

std::unique_ptr<IReportStorage> StorageFactory::createReportStorage() const {
    switch (storageFormat) {
        case types::StorageFormat::txt:
            return std::make_unique<
                storage::ValidatedReportStorage<FileStorage>>();
        case types::StorageFormat::sqlite:
            return std::make_unique<
                storage::ValidatedReportStorage<SQLiteStorage>>();
        case types::StorageFormat::dummy:
            return std::make_unique<
                storage::ValidatedReportStorage<DummyStorage>>();
    }

    return nullptr;
}
}  // namespace storage