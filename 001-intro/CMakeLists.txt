cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MyProject)

# Add a library target
add_library(simplelib STATIC simplelib.cpp)

# Add the executable
add_executable(main main.cpp)
add_executable(link link.cpp)

# Link the executable with the library
target_link_libraries(link PRIVATE simplelib)
