
# Version required
cmake_minimum_required(VERSION 3.10)

# Project's name
project(quicksort)

# Includes
include_directories(include)

# Source files
set(SOURCES
    ./src/main.cpp
    ./src/FileSystem.cpp
)

# Source files to add
add_executable(quicksort ${SOURCES})
