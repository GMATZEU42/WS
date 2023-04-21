cmake_minimum_required( VERSION 3.15 )

project(matrix_square)

include_directories(blitz_lib/include)
link_directories(blitz_lib/lib)

add_executable(matrix_square main.cpp)

target_compile_features(matrix_square PUBLIC cxx_std_17)
target_link_libraries(matrix_square PUBLIC blitz)