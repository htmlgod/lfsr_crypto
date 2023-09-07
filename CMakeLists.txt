cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 20)

# hunter module, keep up-to-date
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.24.14.tar.gz"
    SHA1 "00901c19eefc02d24b16705b5f5a2b4f093a73fb"
)

project(lfsr_crypto)
option(BUILD_TESTS "Build tests" OFF)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

# TODO: define source files here
add_executable(
    ${PROJECT_NAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp
)

# TODO: define include directories here
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

include(cmake/packaging.cmake)
if(BUILD_TESTS)
    enable_testing()
    # TODO: enum tests
    add_executable("${PROJECT_NAME}_tests"
        tests/test.cpp
    )
    target_link_libraries(
      "${PROJECT_NAME}_tests"
      GTest::gtest_main
    )
    include(GoogleTest)
    gtest_discover_tests("${PROJECT_NAME}_tests")
endif()
