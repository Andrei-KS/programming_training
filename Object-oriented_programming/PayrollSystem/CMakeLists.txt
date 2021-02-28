# CMakeList.txt : CMake project for Object-oriented_programming, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(PayrollSystem)

set(CMAKE_CXX_STANDARD 11)

# Local header files here ONLY
SET(TARGET_H)

# Local source files here
SET(TARGET_SRC)

# Local Path to header and src
set(PATH_H "include")

# Local Path to src
set(PATH_SRC "src")

file(GLOB_RECURSE TARGET_SRC ${PATH_H} *.cpp)
file(GLOB_RECURSE TARGET_H ${PATH_SRC} *.h)

include_directories("${PROJECT_SOURCE_DIR}/include")

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "main.cpp" ${TARGET_H} ${TARGET_SRC})