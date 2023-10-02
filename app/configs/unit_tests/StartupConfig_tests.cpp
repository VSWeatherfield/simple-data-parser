#include <gtest/gtest.h>

#include <string>

#include "configs/StartupConfig.hpp"
#include "types/ReportFormat.hpp"

char arg0[] = "Program name";
char arg1[] = "--port";
char arg2[] = "8000";
char arg3[] = "--rf";
char arg4[] = "xml";
char arg5[] = "yaml";
char arg6[] = "--sf";
char arg7[] = "txt";
char arg8[] = "-";

TEST(StartupConfigTests, validOptions_returnsXmlStartupConfig) {
    char* argv[] = {&arg0[0], &arg1[0], &arg2[0], &arg3[0],
                    &arg4[0], &arg6[0], &arg7[0], NULL};
    const auto config = optionsToStartupConfig(7, argv);
    ASSERT_TRUE(config);
    ASSERT_EQ(config->port, 8000);
    ASSERT_EQ(config->report_format, types::ReportFormat::Xml);
    ASSERT_EQ(config->storage_format, types::StorageFormat::txt);
}

TEST(StartupConfigTests, yamlFormat_returnsYamlStartupConfig) {
    char* argv[] = {&arg0[0], &arg1[0], &arg2[0], &arg3[0],
                    &arg5[0], &arg6[0], &arg8[0], NULL};
    const auto config = optionsToStartupConfig(7, argv);
    ASSERT_TRUE(config);
    ASSERT_EQ(config->port, 8000);
    ASSERT_EQ(config->report_format, types::ReportFormat::Yaml);
    ASSERT_EQ(config->storage_format, types::StorageFormat::dummy);
}

TEST(StartupConfigTests, helpOption_returnsEmptyStartupConfig) {
    char help[] = "--help";
    char* argv[] = {&arg0[0], &help[0], NULL};
    const auto config = optionsToStartupConfig(2, argv);
    ASSERT_FALSE(config);
}

TEST(StartupConfigTests, notAllOptions_throws) {
    char* argv[] = {&arg0[0], &arg1[0], &arg2[0], NULL};
    ASSERT_ANY_THROW(optionsToStartupConfig(3, argv));
}