#include <gmock/gmock.h>

#include "parsers/ICredentialsParser.hpp"

namespace parsers {
class CredentialsParserMock : public parsers::ICredentialsParser {
   public:
    MOCK_CONST_METHOD1(parseCredentials,
                       std::optional<types::User>(const std::string_view));
};
}  // namespace parsers