cmake_minimum_required(VERSION 3.30.1)
project(bmtask)

add_subdirectory(benchmark)

add_executable(bmtask main.cpp)
target_link_libraries(bmtask benchmark::benchmark)