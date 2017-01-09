CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)
project(Braino)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

# Set bin and lib dirrectories.
# http://stackoverflow.com/a/6595001/5415895
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR})

# https://cmake.org/Wiki/CMake:How_To_Find_Libraries#Using_external_libraries_that_CMake_doesn.27t_yet_have_modules_for
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(Boost 1.58 REQUIRED)
find_package(MySQLConnectorCPP REQUIRED)

add_subdirectory(${PROJECT_SOURCE_DIR}/braino)

file(COPY cmake/braino.sh DESTINATION ${PROJECT_BINARY_DIR})