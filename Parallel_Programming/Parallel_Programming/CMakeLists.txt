# CMakeList.txt : CMake project for Parallel_Programming, include source and define
# project specific logic here.
#

###----------------------------------------------------------------------------------
# Setting cmake project
###----------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.8)

project(Parallel_Programming)
set(CMAKE_CXX_STANDARD 11)
enable_testing()
set(CTEST_PROJECT_NAME "Parallel_Programming")
set(CTEST_NIGHTLY_START_TIME "01:00:00 UTC")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG_BUILD")

# connecting the necessary modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/_cmake")
include(CreatLibFromFiles)
include(CreatTestForLib)
include(CopyFolder)

###----------------------------------------------------------------------------------
# End block of setting cmake project
###----------------------------------------------------------------------------------




###----------------------------------------------------------------------------------
# block of create lib
###----------------------------------------------------------------------------------

# need choice one of example
# 1 - HellowWorld
set(ChosenExample 1)

# create Example lib
# set default setting
set(NameLib "CurrentExemple")
set(prefixDirectory)
set(ListPathToInclude)
set(ListPathToSrc)
set(ListNamesSRCfiles)
set(ListPathToLibs)

if(ChosenExample EQUAL 1)
	set(prefixDirectory "Example/HelowWorld")
	List(APPEND ListPathToInclude 
		"${PROJECT_SOURCE_DIR}/include/"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc 
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
endif()

CreatLibFromFiles(${NameLib})

###----------------------------------------------------------------------------------
# end block of create lib
###----------------------------------------------------------------------------------






###----------------------------------------------------------------------------------
# block of make main program
###----------------------------------------------------------------------------------

# Setting main program
# Setting SRC
set(ListPathToSrc)
List(APPEND ListPathToSrc
	"${PROJECT_SOURCE_DIR}/src/main.cpp"
	)

# Setting header
set(ListPathToInclude)
List(APPEND ListPathToInclude
	"${PROJECT_SOURCE_DIR}/include"
	)


# include header to main function
include_directories(${ListPathToInclude})

# Add source to this project's executable.
add_executable (${PROJECT_NAME} ${ListPathToSrc})

target_link_libraries(${PROJECT_NAME}
	PRIVATE "${PROJECT_BINARY_DIR}/CurrentExemple.lib"
	)

###----------------------------------------------------------------------------------
# block of make main program
###----------------------------------------------------------------------------------