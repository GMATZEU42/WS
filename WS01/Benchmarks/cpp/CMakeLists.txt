cmake_minimum_required( VERSION 3.15 )

project(matrix_square)

add_executable(matrix_square main.cpp)

target_compile_features(matrix_square PUBLIC cxx_std_17)