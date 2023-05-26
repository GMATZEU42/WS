cmake_minimum_required( VERSION 3.15 )

project(template)

include_directories(./)
add_executable(template main.cpp)

target_compile_features(template PUBLIC cxx_std_17)
