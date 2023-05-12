cmake_minimum_required( VERSION 3.15 )

project(example1)

# Build runtime in the same directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/")

file(GLOB INCLUDE_LIST "*.h")
file(GLOB SOURCE_LIST "*.cpp")

add_executable(example1 ${SOURCE_LIST} ${INCLUDE_LIST})

target_compile_features(example1 PUBLIC cxx_std_17)
