cmake_minimum_required(VERSION 3.10)

project(Parsers)

add_subdirectory(unit_tests)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(HEADERS
    ${PROJECT_SOURCE_DIR}/include/parsers/ParsersFactory.hpp
    ${PROJECT_SOURCE_DIR}/include/parsers/JsonParser.hpp
    ${PROJECT_SOURCE_DIR}/include/parsers/XmlParser.hpp
    ${PROJECT_SOURCE_DIR}/include/parsers/YamlParser.hpp
    ${PROJECT_SOURCE_DIR}/include/parsers/ValidatedReportParser.hpp)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/ParsersFactory.cpp
    ${PROJECT_SOURCE_DIR}/src/JsonParser.cpp
    ${PROJECT_SOURCE_DIR}/src/XmlParser.cpp
    ${PROJECT_SOURCE_DIR}/src/YamlParser.cpp
    ${PROJECT_SOURCE_DIR}/src/ValidatedReportParser.cpp)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries(
    ${PROJECT_NAME}
    yaml-cpp
    Common
    External
    Interfaces)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
