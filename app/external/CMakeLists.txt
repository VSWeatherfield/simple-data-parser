project(External)

include(CPM)
cpmaddpackage("gh:jbeder/yaml-cpp#0.8.0")

set(TINYXML2_LIB ${PROJECT_SOURCE_DIR}/tinyxml2/tinyxml2.h
                 ${PROJECT_SOURCE_DIR}/tinyxml2/tinyxml2.cpp)

set(JSON_LIB ${PROJECT_SOURCE_DIR}/nlohmann/json.hpp)

set(SQLITE3_LIB ${PROJECT_SOURCE_DIR}/sqlite3/sqlite3.h
                ${PROJECT_SOURCE_DIR}/sqlite3/sqlite3.c)

add_library(${PROJECT_NAME} STATIC ${TINYXML2_LIB} ${JSON_LIB} ${SQLITE3_LIB})

target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR})
