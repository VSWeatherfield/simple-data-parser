#pragma once

#include <memory>

#include "auth/IAuthorization.hpp"
#include "parsers/IReportParser.hpp"
#include "services/ITaxService.hpp"
#include "storage/IReportStorage.hpp"
#include "types/User.hpp"

namespace services {
class TaxService : public ITaxService {
   public:
    TaxService(const types::User&, const auth::IAuthorization&,
               const parsers::IReportParser&, const storage::IReportStorage&);
    ReportStatus onReportRequest(const std::string&) override;

   private:
    const types::User& user;
    const auth::IAuthorization& authManager;
    const parsers::IReportParser& reportParser;
    const storage::IReportStorage& reportStorage;
};
}  // namespace services