#include <gmock/gmock.h>

#include "services/ITaxServiceFactory.hpp"

namespace services {
class TaxServiceFactoryMock : public services::ITaxServiceFactory {
   public:
    MOCK_CONST_METHOD1(create,
                       std::unique_ptr<ITaxService>(const types::User&));
};
}  // namespace services