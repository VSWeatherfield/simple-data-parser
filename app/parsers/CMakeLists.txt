cmake_minimum_required(VERSION 3.10)

project(Parsers)

add_subdirectory(unit_tests)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(HEADERS
    ${PROJECT_SOURCE_DIR}/include/parsers/IReportParser.hpp
    ${PROJECT_SOURCE_DIR}/include/parsers/JsonReportParser.hpp
    ${PROJECT_SOURCE_DIR}/include/parsers/XmlReportParser.hpp)

set(SOURCES ${PROJECT_SOURCE_DIR}/src/XmlReportParser.cpp
            ${PROJECT_SOURCE_DIR}/src/JsonReportParser.cpp)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Common External)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
