#include <gtest/gtest.h>

#include <boost/asio.hpp>
#include <optional>
#include <string>

#include "constants/Constants.hpp"
#include "mocks/AuthenticationMock.hpp"
#include "mocks/CredentialsParserMock.hpp"
#include "mocks/TaxServiceFactoryMock.hpp"
#include "servers/ReportSession.hpp"

using namespace constants;
using ::testing::Return;
using ::testing::StrictMock;

struct ReportSessionTests : testing::Test {
    // TODO: corectly handle socket stuff
    // since it's done poorly, I can't correctly test
    // reportsession. I you got it, please share the code

    ReportSessionTests()
        : ioService(),
          socket(ioService),
          sut(std::move(socket), authMock, parserMock, taxServiceFactoryMock) {}

    types::User user;
    StrictMock<auth::AuthenticationMock> authMock;
    StrictMock<parsers::CredentialsParserMock> parserMock;
    StrictMock<services::TaxServiceFactoryMock> taxServiceFactoryMock;
    boost::asio::io_service ioService;
    tcp::socket socket;
    servers::ReportSession sut;

    const std::string validJsonCredentials =
        R"({"login": "John Doe", "password": "@12345"})";
};

// TEST_F(ReportSessionTests, SuccessfulLoginAndReportHandling) {
//     EXPECT_CALL(parserMock, parseCredentials(validJsonCredentials))
//         .WillOnce(Return(user));

//     sut.start();
// }