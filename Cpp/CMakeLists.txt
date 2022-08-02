# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#

#[[-------------------------------------------------------------------------
                    Configuration cmake project
]]#-------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.8)

project ("Сpp")

enable_testing()

# connecting the necessary modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/_cmake_lib")
include(creat_lib_from_files)
include(creat_test_for_lib)
include(copy_folder)

# Include sub-projects.
#add_subdirectory ("DifferentTasksByAlgorithms")
#add_subdirectory ("Object-oriented_programming")
#add_subdirectory ("Parallel_Programming")
add_subdirectory ("Stroustrup_principles_and_practice")
#add_subdirectory ("WorkOnTheDifferentStuffOfCMake")