cmake_minimum_required(VERSION 3.21)
project(CLRS_cpp_imp)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS})

find_package(benchmark REQUIRED)


set(TEST_SOURCES
    source/test.cpp
)

set(BENCHMARK_SOURCES
    source/benchmark.cpp
)

add_executable(insertion_sort_tests ${TEST_SOURCES})
target_link_libraries(insertion_sort_tests PRIVATE
    GTest::GTest GTest::Main
)
add_test(NAME insertion_sort_tests 
    COMMAND
    insertion_sort_tests
)

add_executable(insertion_sort_benchmark ${BENCHMARK_SOURCES})
target_link_libraries(insertion_sort_benchmark 
    PRIVATE
    benchmark::benchmark
)

