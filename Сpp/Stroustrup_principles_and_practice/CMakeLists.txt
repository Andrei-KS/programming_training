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
# TRY		- Try this
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
# CH3P127EXERC10		/ The simple calculator
#------------------------------------ Chapter_4
# CH4P146TRY			/ Converting UAH, RUB and CNY to USD
# CH4P149TRY			/ Converting UAD, CNY, EUR, GBP or RUB to USD using switch
# CH4P151TRY			/ Display char and its number in table
# CH4P154TRY			/ Display char A-Za-z and its number in table using for
# CH4P157TRY			/ Implementation square function without multiply
# CH4P165TRY			/ Implementation a program to muffle unwanted words
# CH4P166TASK1			/ Read and display two int
# CH4P166TASK2			/ display max and min
# CH4P166TASK3			/ display numbers are equal
# CH4P166TASK4			/ Work with double
# CH4P166TASK5			/ The numbers are almost equal
# CH4P166TASK6			/ Reading more than two
# CH4P167TASK7			/ Reading num and unit
# CH4P167TASK8			/ Reading num and unit only [cm], [m], [in] and [ft]
# CH4P167TASK9			/ Count numbers and calculate sum in [m]
# CH4P167TASK10		/ Converting all entered values in [m]
# CH4P167TASK11		/ sort values in vector
# CH4P169EXERC2		/ find median
# CH4P169EXERC3		/ Distances between cities
# CH4P169EXERC4		/ Guess a number from 1 to 100
# CH4P169EXERC5		/ The simple calculator
# CH4P169EXERC8		/ Grains and cells 
#------------------------------------ Chapter_5
# CH5P188TRY			/ Add checking
# CH5P198TRY			/ Break program and get invalid result
# CH5P199TRY			/ Set valid min and max value
# CH5P209TRY			/ Find bad value for post condition
# CH5P211TASK			/ Fixbug
# CH5P214EXERC2		/ Сelsius to kelvin  
# CH5P214EXERC3		/ Сelsius to kelvin, add checking less than -273.15C
# CH5P214EXERC4		/ Сelsius to kelvin, add checking less than -273.15C into function

# if sample is not exist that new directory will created for this example by mock
set(name_Example "CH5P214EXERC4")
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