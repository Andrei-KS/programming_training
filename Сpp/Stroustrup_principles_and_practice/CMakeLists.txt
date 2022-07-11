# CMakeList.txt : CMake project for Сpp, include source and define
# project specific logic here.
#

#[[----------------------------------------------------------------------------
                    Configuration cmake project
]]#----------------------------------------------------------------------------
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


#[[----------------------------------------------------------------------------
                    The builder's configurations of libs
]]#----------------------------------------------------------------------------

#[[------------------------------------
					Example lib 
]]#------------------------------------
# need choice one of example
# naming rule for examples
# [CH](number chapter)[P](number pag)[TASK/EXERC/DRILL/TRY](numbers)
# TASK/DRILL	- Drill/task 
# EXERC			- Exercises
# TRY				- Try this
# example: CH1P1EXERC1
#
# list of examples:
#-------------------------------------- Chapter_3
# CH3P106TRY					/ Change the "The name and age" program so that it will display age in months. Entered age is expressed in years
# CH3P108TRY					/ Change the "Display working of operators" so that double will become int
# CH3P124TASK1					/ Modify the "Hi, first_name" program
# CH3P124TASK2					/ Add string "How are you?I'm fine. I miss you." to cpp file of CH3P124TASK1 task
# CH3P124TASK3					/ Add new variable friend_name and the string "How long have you met friend_name?" 
# CH3P124TASK4					/ Add new variable friend_sex and the string "If you see friend_name, please ask him/her to call me."
# CH3P125TASK5					/ Add new variable age, string "I heard you just celebrated your birthday and you are age years" and checking age
# CH3P125TASK6					/ Add if statement for age
# CH3P125TASK7					/ Add string "Sincerely yours" and place for signature
# CH3P127EXERC2				/ Converting ml to km
# CH3P127EXERC4				/ Arithmetical operation on int
# CH3P127EXERC5				/ Arithmetical operation on double
# CH3P127EXERC6				/ Enter three integers and then outputs them in ascending order 
# CH3P127EXERC7				/ Enter three strings and then outputs them in ascending order 
# CH3P127EXERC8				/ check parity int
# CH3P127EXERC10				/ The simple calculator
#-------------------------------------- Chapter_4
# CH4P146TRY					/ Converting UAH, RUB and CNY to USD
# CH4P149TRY					/ Converting UAD, CNY, EUR, GBP or RUB to USD using switch
# CH4P151TRY					/ Display char and its number in table
# CH4P154TRY					/ Display char A-Za-z and its number in table using for
# CH4P157TRY					/ Implementation square function without multiply
# CH4P165TRY					/ Implementation a program to muffle unwanted words
# CH4P166TASK1					/ Read and display two int
# CH4P166TASK2					/ display max and min
# CH4P166TASK3					/ display numbers are equal
# CH4P166TASK4					/ Work with double
# CH4P166TASK5					/ The numbers are almost equal
# CH4P166TASK6					/ Reading more than two
# CH4P167TASK7					/ Reading num and unit
# CH4P167TASK8					/ Reading num and unit only [cm], [m], [in] and [ft]
# CH4P167TASK9					/ Count numbers and calculate sum in [m]
# CH4P167TASK10				/ Converting all entered values in [m]
# CH4P167TASK11				/ sort values in vector
# CH4P169EXERC2				/ find median
# CH4P169EXERC3				/ Distances between cities
# CH4P169EXERC4				/ Guess a number from 1 to 100
# CH4P169EXERC5				/ The simple calculator
# CH4P169EXERC8				/ Grains and cells 
#-------------------------------------- Chapter_5
# CH5P188TRY					/ Add checking
# CH5P198TRY					/ Break program and get invalid result
# CH5P199TRY					/ Set valid min and max value
# CH5P209TRY					/ Find bad value for post condition
# CH5P211TASK					/ Fixbug
# CH5P214EXERC2				/ Сelsius to kelvin  
# CH5P214EXERC3				/ Сelsius to kelvin, add checking less than -273.15C
# CH5P214EXERC4				/ Сelsius to kelvin, add checking less than -273.15C into function
# CH5P214EXERC5				/ Kelvin to celsius
# CH5P214EXERC6				/ Celsius to fahrenheit and fahrenheit to celsius
# CH5P214EXERC7				/ Quadratic equation
# CH5P214EXERC8				/ The sum of the first N numbers
#-------------------------------------- Chapter_6
# CH6P250TRY					/ First version calculator
# CH6P262TRY					/ Second version calculator
# CH6P263TASK					/ Correction of the second version
# CH6P264EXERC2				/ Added '{' and '}' to second version calculator
# CH6P264EXERC3				/ Added factorial function (number!) to second version calculator
# CH6P265EXERC6				/ Simple english grammar
# CH6P265EXERC7				/ A grammar for bitwise logical expressions
#-------------------------------------- Chapter_7
# CH7P297TASK4					/ Data for tests
# CH7P297_298TASKS6_11		/ Add a predefined name k meaning 1000, a square root functions
#									/ sqrt() and pow(x,i) to mean “Multiply x with itself i times”.
#									/ Change the “declaration keyword” from let to #.
#									/ Change the “quit keyword” from quit to exit.
# CH7P299EXERC1_2				/ Allow underscores in the calculator’s variable names.
#									/ Provide an assignment operator, '='.
# CH7P299EXERC3				/ Provide named constants that you really can’t change the value of.
# CH7P299EXERC4				/ Define a class called Symbol_table
# CH7P299_300EXERC5_6		/ Modify  Token_stream::get() to return Token(print) when it sees a newline.
#									/ Add key h/H/help for helping information
#
# Below linking chapters and exercises is linked to the
# book of Programming Principles and Practice Using C++/
# Second Edition/ Bjarne Stroustrup/ 2014/
# ISBN-13: 978-0-321-99278-9
#-------------------------------------- Chapter_8
# CH8P297DRILL1				/ Create three files:my.h, my.cpp, and use.cpp.
# CH8P298DRILL3				/ Write a program using a single file containing three namespacesX, Y, and Z
# CH8P300EXERC1				/ Modify the calculator program to make the input stream
#									/ an explicit parameter, rather than simply using cin.
# CH8P300EXERC2				/ Write a function print() that prints a vector of ints
# CH8P300EXERC3				/ Create a vector of Fibonacci numbers
# CH8P300EXERC5				/ Write two functions that reverse the order of elements in a vector<int>
# CH8P301EXERC6				/ Write two functions that reverse the order of elements in a vector<string>
#-------------------------------------- Chapter_9
# CH9P339EXERC2				/ Design and implement a Name_pairs class holding (name,age) pair
# CH9P339EXERC3				/ Replace Name_pair::print() with a (global) operator << and define ==
#									/ and != for Name_pairs.
# CH9P339EXERC5				/ Design and implement a Book class.
# CH9P340EXERC6				/ Add operators for the Book class.
# CH9P340EXERC7				/ Create an enumerated type for the Book class called Genre.
# CH9P340EXERC8				/ Create a Patron class for the library.
# CH9P340EXERC9				/ Create a Library class.
# CH9P340EXERC10				/ Implement leapyear() in Chrono::Date.
# CH9P340EXERC11				/ Design and implement a set of useful helper functions for the Date class.
# CH9P340EXERC13				/ Design and implement a rational number class, Rational.
# CH9P341EXERC14				/ Design and implement a Money class for calculations involving dollars and cents.
# CH9P341EXERC15				/ Refine the Money class by adding a currency.
# CH9P341EXERC16				/ Define an input operator (>>) and output operator (<<) for the Money.
#-------------------------------------- Chapter_10
# CH10P376DRILL1				/ Start a program to work with points. Begin by defining the data type
#									/ Point that has two coordinate members x and y
# CH10P376DRILL2				/ Prompt the user to input seven (x,y) pairs. As the data is entered,
#									/ store it in a vector of Points called original_points
# CH10P376DRILL4				/ Open an ofstream and output each point to a file named mydata.txt.
# CH10P376DRILL5				/ Close the ofstream and then open an ifstream for mydata.txt. Read the data
#									/ from mydata.txt and store it in a new vector called processed_points.
# CH10P376DRILL6_7			/ Print the data elements from both vectors. Compare the two vectors
#									/ and print Something's wrong! if the number of elements or
#									/ the values of elements differ
# CH10P377EXERC1				/ Write a program that produces the sum of all the numbers in a file of
#									/ whitespace-separated integers.
# CH10P377EXERC2				/ Write a program that creates a file of data in the form of the temperature
#									/ Reading type. For testing, fill the file with at least 50
#									/ “temperature readings.” Call this program and the file it
#									/ creates raw_temps.txt.
# CH10P377EXERC3				/ Write a program that reads the data from raw_temps.txt created
#									/ in exercise 2 into a vector and then calculates the mean
#									/ and median temperatures in your data set.
# CH10P377EXERC4				/ Modify the program from exercise 2 to include a temperature 
#									/ suffix c for Celsius or f for Fahrenheit temperatures. Then
#									/ modify the program from exercise 3 to test each temperature,
#									/ converting the Celsius readings to Fahrenheit before putting
#									/ them into the vector
# CH10P377EXERC5				/ Write the function print_year().
#

# if the example does not exist that new directory will be created for it by layout
set(name_Example "CH10P377EXERC5")

#[[------------------------------------
					Example's hierarchy
]]#------------------------------------
# processing the example name, if it does not exist, hierarchy will be made for it 

option(SHOWE_STATUS_MESSAGE "" TRUE)
option(SHOWE_INFO_MESSAGE "" TRUE)

# set layout file names
set(layout_file_names
	"layout_h"
	"layout_cpp"
)

# search task description of the name_Example in CMakeLists.txt
file(READ "${PROJECT_SOURCE_DIR}/CMakeLists.txt" task_description)
string(REGEX MATCH "# ${name_Example}\t+[^#]+(#\t+[/][^#]+)*" task_description "${task_description}")
# delete unnecessary characters of the CMakeList.txt file formatting from the task description 
string(REGEX REPLACE "(# ${name_Example}\t+/ |\n$)" "" task_description ${task_description})
string(REGEX REPLACE "\n#\t+/ " " " task_description ${task_description})


# set substitutions list
set(current_date)
string(TIMESTAMP current_date "%m/%d/%Y %H:%M:%S")
set(substitutions_list
	"name_file"	"${name_Example}"
	"project_source_dir_include" "{PROJECT_SOURCE_DIR}/include"
	"date_generate" "${current_date}"
	"author" "Andrei-KS"
	"task_description" "${task_description}"
)

set(parent_dir "Chapter_")
if(name_Example MATCHES "^CH([0-9]+)P")
	set(parent_dir "${parent_dir}${CMAKE_MATCH_1}")
else()
	set(parent_dir "${parent_dir}EmptyNumber")
endif()

set(dir_Example "${PROJECT_SOURCE_DIR}/${parent_dir}/Example/${name_Example}")
if(NOT EXISTS "${dir_Example}")

	make_directory(${dir_Example})
	if(SHOWE_STATUS_MESSAGE)
		message(STATUS "Directory is not found: ${dir_Example}\n\t\tThis directory will be created by generator from layouts")
	endif()

	set(src_dir_Example "${dir_Example}/src")
	set(include_dir_Example "${dir_Example}/include")
	make_directory(${src_dir_Example})
	make_directory(${include_dir_Example})
	
	# get the number of items on the list
	list(LENGTH substitutions_list length_substitutions_list)
	# get the max valid index of the list
	math(EXPR upper_number_substitutions_list "${length_substitutions_list} - 1" OUTPUT_FORMAT DECIMAL)

	foreach(index RANGE 0 ${upper_number_substitutions_list} 2)
			list(GET substitutions_list ${index} list_item)
			list(REMOVE_AT substitutions_list ${index})
			list(INSERT substitutions_list ${index} "[$][{]${list_item}[}]")
	endforeach()


	if(SHOWE_INFO_MESSAGE)
		message("length_substitutions_list:\t"${length_substitutions_list})
		message("upper_number_substitutions_list:\t"${upper_number_substitutions_list})
		foreach(index RANGE 0 ${upper_number_substitutions_list} 2)
			list(GET substitutions_list ${index} search_item)
			math(EXPR index_replace_item "${index} + 1" OUTPUT_FORMAT DECIMAL)
			list(GET substitutions_list ${index_replace_item} replace_item)
			message(${search_item}"\t<-\t"${replace_item})
		endforeach()
	endif()

	foreach(layout_file_name IN LISTS layout_file_names)

		# get content from the current layout file
		file(READ "${PROJECT_SOURCE_DIR}/include/${layout_file_name}" content_layout_file)
		
		if(SHOWE_INFO_MESSAGE)
			message("layout_file_name:\t${layout_file_name}")
			message("content_layout_file:\n${content_layout_file}")
		endif()
 
		foreach(index RANGE 0 ${upper_number_substitutions_list} 2)
			list(GET substitutions_list ${index} search_item)
			math(EXPR index_replace_item "${index} + 1" OUTPUT_FORMAT DECIMAL)
			list(GET substitutions_list ${index_replace_item} replace_item)

			string(REGEX REPLACE
				"${search_item}"
				"${replace_item}"
				content_layout_file
				"${content_layout_file}"
			)
		endforeach()
		
		if(SHOWE_INFO_MESSAGE)	
			message("content_layout_file: ${content_layout_file}")
		endif()

		if(${layout_file_name} MATCHES "[_]h$")
			file(WRITE "${include_dir_Example}/${name_Example}RunExmple.h" "${content_layout_file}")
		elseif(${layout_file_name} MATCHES "[_]cpp$")
			file(WRITE "${src_dir_Example}/${name_Example}RunExmple.cpp" "${content_layout_file}")
		endif()

	endforeach()

endif()

# builder of Example lib
# set default setting
set(NameLib "${name_Example}")
set(prefixDirectory)
set(EP_CLFF_Includes)
set(EP_CLFF_Src)
set(EP_CLFF_SrcFiles)
set(EP_CLFF_Libs)

set(prefixDirectory "${parent_dir}/Example/${name_Example}/")
List(APPEND EP_CLFF_Includes 
	"${PROJECT_SOURCE_DIR}/include"
	"${prefixDirectory}/include"
	"${PROJECT_SOURCE_DIR}/lib/include"
)
List(APPEND EP_CLFF_Src 
	"${prefixDirectory}/src"
	"${PROJECT_SOURCE_DIR}/lib/src"
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
	PRIVATE "${PROJECT_BINARY_DIR}/${name_Example}.lib"
)