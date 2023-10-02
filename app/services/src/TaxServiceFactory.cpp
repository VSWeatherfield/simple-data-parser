#include "services/TaxServiceFactory.hpp"

#include "services/TaxService.hpp"

namespace services {
TaxServiceFactory::TaxServiceFactory(
    const auth::IAuthorization& authManager,
    const parsers::IReportParser& reportParser,
    const storage::IReportStorage& reportStorage)
    : authManager{authManager},
      reportParser{reportParser},
      reportStorage{reportStorage} {}

std::unique_ptr<ITaxService> TaxServiceFactory::create(
    const types::User& user) const {
    return std::make_unique<TaxService>(user, authManager, reportParser,
                                        reportStorage);
}
}  // namespace services