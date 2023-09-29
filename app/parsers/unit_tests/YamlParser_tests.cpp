#include <gtest/gtest.h>

#include <optional>

#include "parsers/YamlParser.hpp"
#include "types/Report.hpp"
#include "yaml-cpp/yaml.h"

using YAML::Node;  // Import the YAML Node class

struct YamlParserTests : testing::Test {
    parsers::YamlParser sut;
};

TEST_F(YamlParserTests, whenValidData_parseReportReturnsReport) {
    const std::string yamlReport = R"(
        payer: 1
        tax: VAT
        amount: 1000
        year: 2020
    )";

    const std::optional<types::Report> parsedReport =
        sut.parseReport(yamlReport);
    const types::Report expectedReport{1, "VAT", 1000, 2020};

    ASSERT_TRUE(parsedReport);
    ASSERT_EQ(*parsedReport, expectedReport);
}

TEST_F(YamlParserTests, whenMissingFields_parseReportReturnsNull) {
    const std::string yamlReport = R"(
        payer: 1
        year: 2020
    )";

    ASSERT_EQ(sut.parseReport(yamlReport), std::nullopt);
}

TEST_F(YamlParserTests, whenEmptyReport_parseReportReturnsNull) {
    const std::string yamlReport = "";

    ASSERT_EQ(sut.parseReport(yamlReport), std::nullopt);
}

TEST_F(YamlParserTests, whenNumericDataInvalid_parseReportReturnsNull) {
    const std::string yamlReport = R"(
        payer: One
        tax: VAT
        amount: Ten
        year: Hundred
    )";

    ASSERT_EQ(sut.parseReport(yamlReport), std::nullopt);
}

TEST_F(YamlParserTests, whenValidData_parseCredentialsReturnsUser) {
    const types::User user{{"John Doe"}, {"Password"}};
    const std::string yamlCreds = R"(
        login: John Doe
        password: Password
    )";
    const std::optional<types::User> parsedUser =
        sut.parseCredentials(yamlCreds);
    ASSERT_TRUE(parsedUser);
    ASSERT_EQ(parsedUser->login.value, user.login.value);
    ASSERT_EQ(parsedUser->password.value, user.password.value);
}

TEST_F(YamlParserTests, whenMissingFields_parseCredentialsReturnsNull) {
    const std::string yamlCreds = R"(
        login: John Doe
    )";

    ASSERT_EQ(sut.parseCredentials(yamlCreds), std::nullopt);
}