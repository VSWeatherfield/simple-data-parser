project(Parsers)

add_subdirectory(unit_tests)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

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
    PRIVATE yaml-cpp
            Common
            External
            Interfaces)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
