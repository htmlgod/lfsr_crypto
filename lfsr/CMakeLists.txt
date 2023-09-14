cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 20)

include("../cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.24.14.tar.gz"
    SHA1 "00901c19eefc02d24b16705b5f5a2b4f093a73fb"
)

project(lfsr)

hunter_add_package(Boost)
find_package(Boost CONFIG REQUIRED)


add_library(
    ${PROJECT_NAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/lfsr.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PUBLIC Boost::boost)
