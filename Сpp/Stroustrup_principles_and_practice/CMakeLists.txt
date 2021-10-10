# CMakeList.txt : CMake project for Сpp, include source and define
# project specific logic here.
#

###----------------------------------------------------------------------------------
# Setting cmake project
###----------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.8)

project("Stroustrup_principles_and_practice")
set(CMAKE_CXX_STANDARD 11)
enable_testing()
set(CTEST_PROJECT_NAME "Stroustrup_principles_and_practice")
set(CTEST_NIGHTLY_START_TIME "01:00:00 UTC")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG_BUILD")

# connecting the necessary modules
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/_cmake_lib")
#include(creat_lib_from_files)
#include(creat_test_for_lib)
#include(copy_folder)

###----------------------------------------------------------------------------------
# End block of setting cmake project
###----------------------------------------------------------------------------------

copy_folder("${PROJECT_SOURCE_DIR}/include" "${PROJECT_BINARY_DIR}/include")


###----------------------------------------------------------------------------------
# block of create lib
###----------------------------------------------------------------------------------

#[[
###------------------------------------------
# ParallelUtilities lib
###------------------------------------------
# create ParallelUtilities lib
# set default setting
set(NameLib "LParallelUtilities")
set(prefixDirectory)
set(ListPathToInclude)
set(ListPathToSrc)
set(ListNamesSRCfiles)
set(ListPathToLibs)

set(prefixDirectory "_lib/ParallelUtilities")
List(APPEND ListPathToInclude 
	"${prefixDirectory}/include"
	)
List(APPEND ListPathToSrc 
	"${prefixDirectory}/src"
	)
List(APPEND ListNamesSRCfiles
	)
List(APPEND ListPathToLibs
	)
CreatLibFromFiles(${NameLib})

###------------------------------------------
# Example lib
###------------------------------------------
# need choice one of example
# 1		- HellowWorld	/
# 2		- WaitingInCaseException	/
# 3		- UsingThreadGuard	/
# 4		- UsingScopedThread	/
# 5		- StartMoreThread	/	Starting more thread and it is joined to started thread
# 6		- NaiveVersionOfAccumulation
# 7		- ProtectingListWithMutex	/
# 8		- UsingThreadsafeStack	/
# 9		- LockingMoreMutexes	/
# 10	- UsingHierarchicalMutex	/
# 11	- UsingConditionVariable	/	Waiting for data with std::condition_variable
# 12	- UsingThreadsafeQueue	/
# 13	- PassingCommandsBetweenThreads	/	executing code on the UI thread using the std::packaged_task 
# 14	- WaitingConditionVariableWithTimeout /
set(ChosenExample 14)

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
		"${PROJECT_SOURCE_DIR}/include"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc 
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
###------------------------------------------
elseif(ChosenExample EQUAL 2)
	set(prefixDirectory "Example/WaitingInCaseException")
	List(APPEND ListPathToInclude 
		"${PROJECT_SOURCE_DIR}/include"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc 
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
###------------------------------------------
elseif(ChosenExample EQUAL 3)
	set(prefixDirectory "Example/UsingThreadGuard")
	List(APPEND ListPathToInclude
		"_lib/ParallelUtilities/include"
		"${PROJECT_SOURCE_DIR}/include"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc 
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
###------------------------------------------
elseif(ChosenExample EQUAL 4)
	set(prefixDirectory "Example/UsingScopedThread")
	List(APPEND ListPathToInclude
		"_lib/ParallelUtilities/include"
		"${PROJECT_SOURCE_DIR}/include"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc 
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
###------------------------------------------
elseif(ChosenExample EQUAL 5)
	set(prefixDirectory "Example/StartMoreThread")
	List(APPEND ListPathToInclude 
		"${PROJECT_SOURCE_DIR}/include"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc 
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
###------------------------------------------
elseif(ChosenExample EQUAL 6)
	set(prefixDirectory "Example/NaiveVersionOfAccumulation")
	List(APPEND ListPathToInclude 
		"${PROJECT_SOURCE_DIR}/include"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc 
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
###------------------------------------------
elseif(ChosenExample EQUAL 7)
	set(prefixDirectory "Example/ProtectingListWithMutex")
	List(APPEND ListPathToInclude 
		"${PROJECT_SOURCE_DIR}/include"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc 
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
###------------------------------------------
elseif(ChosenExample EQUAL 8)
	set(prefixDirectory "Example/UsingThreadsafeStack")
	List(APPEND ListPathToInclude
		"_lib/ParallelUtilities/include"
		"${PROJECT_SOURCE_DIR}/include"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc 
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
###------------------------------------------
elseif(ChosenExample EQUAL 9)
	set(prefixDirectory "Example/LockingMoreMutexes")
	List(APPEND ListPathToInclude
		"_lib/ParallelUtilities/include"
		"${PROJECT_SOURCE_DIR}/include"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc 
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
###------------------------------------------
elseif(ChosenExample EQUAL 10)
	set(prefixDirectory "Example/UsingHierarchicalMutex")
	List(APPEND ListPathToInclude
		"_lib/ParallelUtilities/include"
		"${PROJECT_SOURCE_DIR}/include"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc 
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
###------------------------------------------
elseif(ChosenExample EQUAL 11)
	set(prefixDirectory "Example/UsingConditionVariable")
	List(APPEND ListPathToInclude
		"_lib/ParallelUtilities/include"
		"${PROJECT_SOURCE_DIR}/include"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc sss
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
###------------------------------------------
elseif(ChosenExample EQUAL 12)
	set(prefixDirectory "Example/UsingThreadsafeQueue")
	List(APPEND ListPathToInclude
		"_lib/ParallelUtilities/include"
		"${PROJECT_SOURCE_DIR}/include"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc sss
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
###------------------------------------------
elseif(ChosenExample EQUAL 13)
	set(prefixDirectory "Example/PassingCommandsBetweenThreads")
	List(APPEND ListPathToInclude
		"_lib/ParallelUtilities/include"
		"${PROJECT_SOURCE_DIR}/include"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc sss
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
###------------------------------------------
elseif(ChosenExample EQUAL 14)
	set(prefixDirectory "Example/WaitingConditionVariableWithTimeout")
	List(APPEND ListPathToInclude
		"_lib/ParallelUtilities/include"
		"${PROJECT_SOURCE_DIR}/include"
		"${prefixDirectory}/include"
		)
	List(APPEND ListPathToSrc sss
		"${prefixDirectory}/src"
		)
	List(APPEND ListNamesSRCfiles
		)
	List(APPEND ListPathToLibs
		)
endif()

CreatLibFromFiles(${NameLib})
]]#
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
	)

###----------------------------------------------------------------------------------
# end block of make main program
###----------------------------------------------------------------------------------
