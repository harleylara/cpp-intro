cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MyProject)

# Set a CMake variable for the debug flag
option(DEBUG_FLAG "Enable DEBUG messages" ON)

# Add compile definition based on the value of DEBUG_FLAG
add_compile_definitions(DEBUG=${DEBUG_FLAG})

# Add a library target
add_library(simplelib STATIC simplelib.cpp)

# Add the executable
add_executable(main main.cpp)
add_executable(link link.cpp)
add_executable(pre pre.cpp)

# Link the executable with the library
target_link_libraries(link PRIVATE simplelib)
