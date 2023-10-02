#include <gmock/gmock.h>

#include "auth/IAuthentication.hpp"

namespace auth {
class AuthenticationMock : public auth::IAuthentication {
   public:
    MOCK_CONST_METHOD2(authenticate,
                       bool(const types::Login&, const types::Password&));
};
}  // namespace auth