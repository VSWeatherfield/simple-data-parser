#include "services/TaxService.hpp"

#include "constants/Constants.hpp"

namespace services {
TaxService::TaxService(const types::User& user,
                       const auth::IAuthorization& authManager,
                       const parsers::IReportParser& reportParser,
                       const storage::IReportStorage& reportStorage)
    : user{user},
      authManager{authManager},
      reportParser{reportParser},
      reportStorage(reportStorage) {}

ReportStatus TaxService::onReportRequest(const std::string_view request) {
    const auto report = reportParser.parseReport(request);
    if (report != std::nullopt and
        authManager.isAuthorized(user.login, report->payer)) {
        reportStorage.storeReport(*report);
        return constants::OK;
    }
    return constants::NOK;
}
}  // namespace services