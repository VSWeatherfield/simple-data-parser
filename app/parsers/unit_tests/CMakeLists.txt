project(ParsersTests)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCES
    JsonParser_tests.cpp
    XmlParser_tests.cpp
    YamlParser_tests.cpp
    ValidatedReportParser_tests.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE GTest::GTest
            GTest::Main
            yaml-cpp
            Interfaces
            External
            Common
            Parsers)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
