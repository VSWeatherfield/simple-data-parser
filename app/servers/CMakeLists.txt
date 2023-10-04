project(Servers)

add_subdirectory(unit_tests)

find_package(
    Boost
    COMPONENTS system
    REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

set(HEADERS ${PROJECT_SOURCE_DIR}/include/servers/ReportSession.hpp
            ${PROJECT_SOURCE_DIR}/include/servers/Server.hpp)

set(SOURCES ${PROJECT_SOURCE_DIR}/src/ReportSession.cpp
            ${PROJECT_SOURCE_DIR}/src/Server.cpp)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

set(COMON_LINK_LIBS
    ${PROJECT_NAME}
    ${Boost_SYSTEM_LIBRARY}
    Interfaces
    Common
    pthread)

if(WIN32)
    target_link_libraries(${COMON_LINK_LIBS} ws2_32)
else()
    target_link_libraries(${COMON_LINK_LIBS})
endif(WIN32)

target_link_libraries(
    ${PROJECT_NAME}
    ${Boost_SYSTEM_LIBRARY}
    Interfaces
    Common
    pthread)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
