cmake_minimum_required(VERSION 3.16)
project(CornerGrocer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(CornerGrocer main.cpp ItemTracker.cpp)

if(MSVC)
    target_compile_options(CornerGrocer PRIVATE /W4)
else()
    target_compile_options(CornerGrocer PRIVATE -Wall -Wextra -Wpedantic)
endif()
