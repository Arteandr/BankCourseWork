cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(CourseWork VERSION 0.1)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(main main.cpp ${SRC_FILES})

target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)
