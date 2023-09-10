cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 20)

project(lfsr)

add_library(
    ${PROJECT_NAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/lfsr.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
