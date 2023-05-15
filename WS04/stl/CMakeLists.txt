cmake_minimum_required( VERSION 3.15 )

project(stl)

include_directories(./)
add_executable(stl main.cpp)

target_compile_features(stl PUBLIC cxx_std_17)
