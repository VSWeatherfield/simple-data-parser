#pragma once

#include <type_traits>

#include "parsers/IReportParser.hpp"

namespace parsers {
template <typename BaseReportParser>
class ValidatedReportParser : public BaseReportParser {
   public:
    static_assert(std::is_base_of<IReportParser, BaseReportParser>::value);
    std::optional<types::Report> parseReport(const std::string&) const override;
};
}  // namespace parsers