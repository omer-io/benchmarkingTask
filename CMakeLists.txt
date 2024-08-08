cmake_minimum_required(VERSION 3.30.1)
project(bmtask)

include(ExternalProject)

ExternalProject_Add(benchmark
    PREFIX ${CMAKE_BINARY_DIR}/benchmark
    GIT_REPOSITORY https://github.com/google/benchmark
    GIT_TAG v1.8.5
    CMAKE_ARGS -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on -DCMAKE_BUILD_TYPE=Release
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(benchmark binary_dir)
ExternalProject_Get_Property(benchmark source_dir)

include_directories(${source_dir}/include)
link_directories(${binary_dir}/src)

add_executable(bmtask main.cpp)

add_dependencies(bmtask benchmark)
target_link_libraries(bmtask ${binary_dir}/src/libbenchmark.a pthread)