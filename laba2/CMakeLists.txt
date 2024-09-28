cmake_minimum_required(VERSION 3.10)

project(laba2)

add_executable(GCDTest unit.cpp)
target_link_libraries(GCDTest gtest gtest_main)
