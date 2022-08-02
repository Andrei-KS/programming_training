# CMakeList.txt : CMake project for Сpp, include source and define
# project specific logic here.
#

#[[----------------------------------------------------------------------------
                    Configuration cmake project
]]#----------------------------------------------------------------------------
 

cmake_minimum_required (VERSION 3.8)

project("GeneratorFromLayout")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG_BUILD")

#[[----------------------------------------------------------------------------
                    Task description							
]]#----------------------------------------------------------------------------
# Goal:	Need to create a generator file from a layout file,
#			where replacing parameters will highlight as  ${name_parameter_to_replace}.
#--------------------------------------
# Сonditional:	Can only use inside functions of CMake
#--------------------------------------
# Additional info:	Generated files need to be put in the changing folder,
#							what name depends on the option string
#--------------------------------------


#[[----------------------------------------------------------------------------
                    Task implementation							
]]#----------------------------------------------------------------------------

option(SHOWE_STATUS_MESSAGE "" TRUE)
option(SHOWE_INFO_MESSAGE "" TRUE)

# The future directory name is set here where generated files will be placed 
set(directory_name "${PROJECT_SOURCE_DIR}/ImplementationLayoutDir")

# The name implementation layout
set(generated_file_name "ImplementationLayout")

# set layout file names
set(layout_file_names
	"layout_h"
	"layout_cpp"
)

# set substitutions list
set(current_date)
string(TIMESTAMP current_date "%m/%d/%Y %H:%M:%S")
set(substitutions_list
	"name_file"	"${generated_file_name}"
	"project_source_dir_include" "{PROJECT_SOURCE_DIR}/include"
	"date_generate" "${current_date}"
	"author" "Andrei-KS"
)

if(NOT EXISTS "${directory_name}")
	
	make_directory(${directory_name})
	if(SHOWE_STATUS_MESSAGE)
		message(STATUS "Directory is not found: ${DIRECTORY_NAME}\n\t\tThis directory will be created by generator from layouts")
	endif()
	
	set(current_date)
	string(TIMESTAMP current_date "%m/%d/%Y %H:%M:%S")

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
			file(WRITE "${directory_name}/include/${generated_file_name}.h" "${content_layout_file}")
		elseif(${layout_file_name} MATCHES "[_]cpp$")
			file(WRITE "${directory_name}/src/${generated_file_name}.cpp" "${content_layout_file}")
		endif()
	endforeach()
endif()


#[[-------------------------------------------------------------------------
                    The builder's configuration of main program
]]#-------------------------------------------------------------------------

# builder of Example lib
# set default setting
set(NameLib "GeneratorFromLayout_Exemple")
set(prefixDirectory)
set(EP_CLFF_Includes)
set(EP_CLFF_Src)
set(EP_CLFF_SrcFiles)
set(EP_CLFF_Libs)

set(prefixDirectory "${directory_name}")
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
	PRIVATE "${PROJECT_BINARY_DIR}/GeneratorFromLayout_Exemple.lib"
)