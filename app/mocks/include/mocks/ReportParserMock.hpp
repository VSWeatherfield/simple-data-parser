#include <gmock/gmock.h>

#include "parsers/IReportParser.hpp"

namespace parsers {
class ReportParserMock : public parsers::IReportParser {
   public:
    MOCK_CONST_METHOD1(parseReport,
                       std::optional<types::Report>(const std::string&));
};
}  // namespace parsers