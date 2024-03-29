﻿# CMakeList.txt : CMake project for DifferentTasksByAlgorithms, include source and define
# project specific logic here.
#

#[[-------------------------------------------------------------------------
                    Configuration cmake project
]]#-------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.8)

project(ExampelsOOP)
set(CMAKE_CXX_STANDARD 11)
enable_testing()
set(CTEST_PROJECT_NAME "Parallel_Programming")
set(CTEST_NIGHTLY_START_TIME "01:00:00 UTC")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG_BUILD")

# Add source to this project's executable.
# add_executable (DifferentTasksByAlgorithms "TheSkylineProblem.cpp")
# add_executable (DifferentTasksByAlgorithms "ReplaceWords.cpp")
# add_executable (DifferentTasksByAlgorithms "AddAndSearchWord.cpp")
# add_executable (DifferentTasksByAlgorithms "MaxXORofTwoNumbersInArray.cpp")
# add_executable (DifferentTasksByAlgorithms "WordSearch_v2.cpp")
# add_executable (DifferentTasksByAlgorithms "PalindromePairs.cpp")
# add_executable (DifferentTasksByAlgorithms "SimpleBST.cpp" "SimpleBST.h")
# add_executable (DifferentTasksByAlgorithms "ContainsNearbyAlmostDuplicate.h" "ContainsNearbyAlmostDuplicate.cpp")
# add_executable (DifferentTasksByAlgorithms "SearchRange.h" "SearchRange.cpp")
# add_executable (DifferentTasksByAlgorithms "FindClosestElements.h" "FindClosestElements.cpp" )
# add_executable (DifferentTasksByAlgorithms "SmallestDistancePair.cpp" )
# add_executable (DifferentTasksByAlgorithms "HashSet.h" "HashSet.cpp" )
# add_executable (DifferentTasksByAlgorithms "findDuplicateSubtrees.h" "findDuplicateSubtrees.cpp" )
# add_executable (DifferentTasksByAlgorithms "minimumDeviation.cpp" )
# add_executable (DifferentTasksByAlgorithms "SimplifyPath.h" "SimplifyPath.cpp")
add_executable (DifferentTasksByAlgorithms "kWeakestRows.h" "kWeakestRows.cpp")
# TODO: Add tests and install targets if needed.
