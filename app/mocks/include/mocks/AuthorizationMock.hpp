#include <gmock/gmock.h>

#include "auth/IAuthorization.hpp"

namespace auth {
class AuthorizationMock : public auth::IAuthorization {
   public:
    MOCK_CONST_METHOD2(isAuthorized, bool(const types::Login&, std::uint32_t));
};
}  // namespace auth