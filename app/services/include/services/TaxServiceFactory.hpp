#pragma once

#include "auth/IAuthorization.hpp"
#include "parsers/IReportParser.hpp"
#include "services/ITaxServiceFactory.hpp"
#include "storage/IReportStorage.hpp"

namespace services {
class TaxServiceFactory : public ITaxServiceFactory {
   public:
    TaxServiceFactory(const auth::IAuthorization&,
                      const parsers::IReportParser&,
                      const storage::IReportStorage&);
    std::unique_ptr<ITaxService> create(const types::User&) const override;

   private:
    const auth::IAuthorization& authManager;
    const parsers::IReportParser& reportParser;
    const storage::IReportStorage& reportStorage;
};
}  // namespace services