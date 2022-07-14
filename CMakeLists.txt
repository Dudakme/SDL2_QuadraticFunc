cmake_minimum_required(VERSION 3.1)

project(A
    VERSION 1.0.0
    DESCRIPTION "test"
    LANGUAGES CXX
)

add_executable(A ./main.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(A ${SDL2_LIBRARIES})