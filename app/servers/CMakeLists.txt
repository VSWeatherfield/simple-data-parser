project(Servers)

set(HEADERS ${PROJECT_SOURCE_DIR}/include/servers/ReportSession.hpp
            ${PROJECT_SOURCE_DIR}/include/servers/Server.hpp)

set(SOURCES ${PROJECT_SOURCE_DIR}/src/ReportSession.cpp
            ${PROJECT_SOURCE_DIR}/src/Server.cpp)

find_package(
    Boost
    COMPONENTS system
    REQUIRED)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries(
    ${PROJECT_NAME}
    ${Boost_SYSTEM_LIBRARY}
    Parsers
    Services
    Common
    pthread)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
