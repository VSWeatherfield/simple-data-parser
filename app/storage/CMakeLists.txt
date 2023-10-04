project(Storage)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

set(HEADERS
    ${PROJECT_SOURCE_DIR}/include/storage/StorageFactory.hpp
    ${PROJECT_SOURCE_DIR}/include/storage/FileStorage.hpp
    ${PROJECT_SOURCE_DIR}/include/storage/SQLiteStorage.hpp
    ${PROJECT_SOURCE_DIR}/include/storage/DummyStorage.hpp
    ${PROJECT_SOURCE_DIR}/include/storage/ValidatedReportStorage.hpp)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/StorageFactory.cpp
    ${PROJECT_SOURCE_DIR}/src/FileStorage.cpp
    ${PROJECT_SOURCE_DIR}/src/SQLiteStorage.cpp
    ${PROJECT_SOURCE_DIR}/src/DummyStorage.cpp
    ${PROJECT_SOURCE_DIR}/src/ValidatedReportStorage.cpp)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries(
    ${PROJECT_NAME}
    Common
    External
    Interfaces)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
