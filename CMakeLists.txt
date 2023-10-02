cmake_minimum_required(VERSION 3.10)

project(
    ServerDataParser
    VERSION 1.0.0
    LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

option(ENABLE_WARNINGS "Enable compiler warnings for a target" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable compiler warnings as errors" OFF)
option(ENABLE_SANITIZE_ADDR "Enable address sanitizer" ON)
option(ENABLE_SANITIZE_UNDEF "Enable undefined sanitizer" ON)
option(ENABLE_SANITIZE_LEAK "Enable leak sanitizer (GCC/Clang only)" ON)
option(ENABLE_SANITIZE_THREAD "Enable thread sanitizer (GCC/Clang only)" OFF)
option(ENABLE_CLANG_TIDY "Enable to add clang tidy." ON)

enable_testing()

set(EXECUTABLE_NAME ${PROJECT_NAME})

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(Tools)

if(ENABLE_WARNINGS)
    include(Warnings)
endif()

if(ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizer)
    add_sanitizer_flags()
endif()

add_cmake_format_target()
add_clang_format_target()

add_executable(${EXECUTABLE_NAME} main.cpp)

add_subdirectory(app)

target_link_libraries(
    ${EXECUTABLE_NAME}
    Interfaces
    Servers
    Services
    Configs
    Auth
    Parsers)

if(ENABLE_WARNINGS)
    target_set_warnings(${EXECUTABLE_NAME} ON OFF)
endif()

if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target(${EXECUTABLE_NAME})
endif()
