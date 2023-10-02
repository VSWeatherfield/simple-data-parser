#include <gmock/gmock.h>

#include "storage/IReportStorage.hpp"

namespace storage {
class ReportStorageMock : public storage::IReportStorage {
   public:
    MOCK_CONST_METHOD1(storeReport, void(const types::Report& report));
};
}  // namespace storage
