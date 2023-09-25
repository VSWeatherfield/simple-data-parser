#include <gmock/gmock.h>

#include "parsers/IReportParser.hpp"

namespace parsers {
class ReportParserMock : public parsers::IReportParser {
   public:
    MOCK_CONST_METHOD1(parse,
                       std::optional<types::Report>(const std::string_view));
};
}  // namespace parsers