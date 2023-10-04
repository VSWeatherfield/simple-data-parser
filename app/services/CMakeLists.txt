project(Services)

add_subdirectory(unit_tests)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(HEADERS ${PROJECT_SOURCE_DIR}/include/services/TaxServiceFactory.hpp
            ${PROJECT_SOURCE_DIR}/include/services/TaxService.hpp)

set(SOURCES ${PROJECT_SOURCE_DIR}/src/TaxServiceFactory.cpp
            ${PROJECT_SOURCE_DIR}/src/TaxService.cpp)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE Interfaces
            Common
            Storage
            Servers)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
