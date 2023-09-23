cmake_minimum_required(VERSION 3.22)

project(
    ServerDataParser
    VERSION 1.0.0
    LANGUAGES C CXX)

# Set C++ standard to 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable pthread
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# Options
option(ENABLE_WARNINGS "Enable compiler warnings for a target" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable compiler warnings as errors" OFF)

option(ENABLE_SANITIZE_ADDR "Enable address sanitizer" ON)
option(ENABLE_SANITIZE_UNDEF "Enable undefined sanitizer" ON)
option(ENABLE_SANITIZE_LEAK "Enable leak sanitizer (GCC/Clang only)" ON)
option(ENABLE_SANITIZE_THREAD "Enable thread sanitizer (GCC/Clang only)" OFF)

option(ENABLE_CLANG_TIDY "Enable to add clang tidy." ON)

# Set the executable name
set(EXECUTABLE_NAME Executable)

# Set the CMake module path
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

include(Tools)

# Include compiler warnings if enabled
if(ENABLE_WARNINGS)
    include(Warnings)
endif()

add_cmake_format_target()
add_clang_format_target()

# Include sanitizers if enabled
if(ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizer)
    add_sanitizer_flags()
endif()

# Source files
set(SOURCE ${PROJECT_SOURCE_DIR}/main.cpp
           ${PROJECT_SOURCE_DIR}/external/tinyxml2/tinyxml2.cpp)

# Include directories
set(EXE_INCLUDES "./")

# Find required packages
find_package(Threads REQUIRED)
find_package(
    Boost
    COMPONENTS system
    REQUIRED)

# Create the executable
add_executable(${EXECUTABLE_NAME} ${SOURCE})

# Set include directories for the executable
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${EXE_INCLUDES})

# Link required libraries
target_link_libraries(${EXECUTABLE_NAME} ${Boost_SYSTEM_LIBRARY})

# Add unit tests
add_subdirectory(tests/unit_tests)

# Set compiler warnings for the executable if enabled
if(ENABLE_WARNINGS)
    target_set_warnings(${EXECUTABLE_NAME} ON OFF)
endif()

if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target(${EXECUTABLE_NAME})
endif()
