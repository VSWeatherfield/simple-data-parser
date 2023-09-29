project(External)

if(USE_CPM)
    message(STATUS "Using CPM")
    include(CPM)
    cpmaddpackage("gh:jbeder/yaml-cpp#0.8.0")
endif()

set(TINYXML2_LIB ${PROJECT_SOURCE_DIR}/tinyxml2/tinyxml2.h
                 ${PROJECT_SOURCE_DIR}/tinyxml2/tinyxml2.cpp)

set(JSON_LIB ${PROJECT_SOURCE_DIR}/nlohmann/json.hpp)

add_library(${PROJECT_NAME} STATIC ${TINYXML2_LIB} ${JSON_LIB})

target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR})
