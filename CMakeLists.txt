# Set the project name
project(QtStomp)

# Set the CMake variables required by this project
cmake_minimum_required(VERSION 2.8.11)

# Use automoc, and auto-add the current directory to includes
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find the project's dependencies
find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Test REQUIRED)

# Use C++11
add_definitions(-std=c++11)

# Turn on "make test"
enable_testing()

# Add subdirectores
add_subdirectory(src)
add_subdirectory(tests)


