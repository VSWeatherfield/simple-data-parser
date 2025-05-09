#pragma once

#include <memory>

#include "parsers/IParsersFactory.hpp"
#include "types/ReportFormat.hpp"

namespace parsers {
class ParsersFactory : public IParsersFactory {
   public:
    ParsersFactory(const types::ReportFormat);
    std::unique_ptr<IReportParser> createReportParser() const override;
    std::unique_ptr<ICredentialsParser> createCredentialsParser()
        const override;

   private:
    const types::ReportFormat reportFormat;
};
}  // namespace parsers