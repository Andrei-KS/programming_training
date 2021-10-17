# CMakeList.txt : CMake project for Сpp, include source and define
# project specific logic here.
#

#[[-------------------------------------------------------------------------
                    Configuration cmake project
]]#-------------------------------------------------------------------------
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


#[[-------------------------------------------------------------------------
                    The builder's configurations of libs
]]#-------------------------------------------------------------------------

#[[------------------------------------
					Example lib 
]]#------------------------------------
# need choice one of example
# naming rule for examples
# [CH](number chapter)[P](number pag)[TASK/EXERC/TRY](number)
# TASK	- Drill/task 
# EXERC	- Exercises
# TRY	- Try this
# example: CH1P1EXERC1
#
# list of examples:
#------------------------------------ Chapter_3
# CH3P106TRY			/ Change the "The name and age" program so that it will display age in months. Entered age is expressed in years
# CH3P108TRY			/ Change the "Display working of operators" so that double will become int
# CH3P124TASK1			/ Modify the "Hi, first_name" program
# CH3P124TASK2			/ Add string "How are you?I'm fine. I miss you." to cpp file of CH3P124TASK1 task
# CH3P124TASK3			/ Add new variable friend_name and the string "How long have you met friend_name?" 
# CH3P124TASK4			/ Add new variable friend_sex and the string "If you see friend_name, please ask him/her to call me."
# CH3P125TASK5			/ Add new variable age, string "I heard you just celebrated your birthday and you are age years" and checking age
# CH3P125TASK6			/ Add if statement for age
# CH3P125TASK7			/ Add string "Sincerely yours" and place for signature
# CH3P127EXERC2		/ Converting ml to km
# CH3P127EXERC4		/ Arithmetical operation on int
# CH3P127EXERC5		/ Arithmetical operation on double
# CH3P127EXERC6		/ Enter three integers and then outputs them in ascending order 
# CH3P127EXERC7		/ Enter three strings and then outputs them in ascending order 
# CH3P127EXERC8		/ check parity int

# if sample is not exist that new directory will created for this example by mock
set(name_Example "CH3P127EXERC8")
set(parent_dir "Chapter_")
if(name_Example MATCHES "^CH([0-9]+)P")
	set(parent_dir "${parent_dir}${CMAKE_MATCH_1}")
else()
	set(parent_dir "${parent_dir}EmptyNumber")
endif()
set(dir_Example "${PROJECT_SOURCE_DIR}/${parent_dir}/Example/${name_Example}")
if(NOT EXISTS "${dir_Example}")
	message(STATUS "Directori is not found: ${dir_Example}\n\t\tThis directory will created by generator from a mocks")
	set(src_dir_Example "${dir_Example}/src")
	set(include_dir_Example "${dir_Example}/include")
	make_directory(${src_dir_Example})
	make_directory(${include_dir_Example})
	
	set(current_date)
	string(TIMESTAMP current_date "%m/%d/%Y %H:%M:%S")
	
	set(currnet_search_list
		"name_file"
		"project_source_dir_include"
		"date_generate"
		"author"
		"ln"							# last element in list, don't change, because at loops of replace semicolon is lost
	)
	set(currnet_replace_list
		"${name_Example}"
		"${PROJECT_SOURCE_DIR}/include"
		"${current_date}"
		"Andrei-KS"
		"\\\\\;"						# last element in list, don't change, because at loops of replace semicolon is lost
	)
	list(TRANSFORM currnet_search_list PREPEND "[$][{]")
	list(TRANSFORM currnet_search_list APPEND "[}]")
	foreach(mock_file_name IN LISTS currnet_search_list)
		message(${mock_file_name})
	endforeach()
	foreach(mock_file_name IN LISTS currnet_replace_list)
		message(${mock_file_name})
	endforeach()
	set(current_mock_file_names
		"mock_header"
		"mock_src"
	)
	foreach(mock_file_name IN LISTS current_mock_file_names)
		message("${mock_file}")
		list(LENGTH currnet_search_list stop_value)
		file(READ "${PROJECT_SOURCE_DIR}/include/${mock_file_name}" content_mock_file)
		message("${content_mock_file}")
		math(EXPR stop_value "${stop_value} - 1" OUTPUT_FORMAT DECIMAL) 
		foreach(index RANGE 0 ${stop_value} 1)
			list(GET currnet_search_list ${index} current_search_element)
			list(GET currnet_replace_list ${index} current_replace_element)
			string(REGEX REPLACE
				"${current_search_element}"
				"${current_replace_element}"
				content_mock_file
				${content_mock_file}
			)
		endforeach()
		message("${content_mock_file}")
		if(${mock_file_name} MATCHES "[_]header$")
			file(WRITE "${include_dir_Example}/${name_Example}RunExmple.h" ${content_mock_file})
		elseif(${mock_file_name} MATCHES "[_]src$")
			file(WRITE "${src_dir_Example}/${name_Example}RunExmple.cpp" ${content_mock_file})
		endif()
	endforeach()
endif()

# builder of Example lib
# set default setting
set(NameLib "Stroustrup_principles_and_practice_Exemple")
set(prefixDirectory)
set(EP_CLFF_Includes)
set(EP_CLFF_Src)
set(EP_CLFF_SrcFiles)
set(EP_CLFF_Libs)

set(prefixDirectory "${parent_dir}/Example/${name_Example}/")
List(APPEND EP_CLFF_Includes 
	"${PROJECT_SOURCE_DIR}/include"
	"${prefixDirectory}/include"
)
List(APPEND EP_CLFF_Src 
	"${prefixDirectory}/src"
)
List(APPEND EP_CLFF_SrcFiles
)
List(APPEND EP_CLFF_Libs
)

creat_lib_from_files(${NameLib})





#[[-------------------------------------------------------------------------
                    The builder's configuration of main program
]]#-------------------------------------------------------------------------
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
	PRIVATE "${PROJECT_BINARY_DIR}/Stroustrup_principles_and_practice_Exemple.lib"
)