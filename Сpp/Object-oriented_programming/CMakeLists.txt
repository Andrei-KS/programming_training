# CMakeList.txt : CMake project for Object-oriented_programming, include source and define
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


#[[-------------------------------------------------------------------------
                    The builder's configuration of main program
]]#-------------------------------------------------------------------------
# need choice one of example
# 1		- Command					/
# 2		- ActiveObjectEngine		/
# 3		- TemplateMethod			/
# 4		- Strategy					/
# 5		- Singleton					/
# 6		- Monostate					/
# 7		- Factory					/
# 8		- Composite/CompositeShape	/
set(NUMBER_EXAMPLE 8)

# Local header files here ONLY
SET(TARGET_H)

# Local source files here
SET(TARGET_SRC)

# Name exampel
set(NAME_EXAMPEL)

if(${NUMBER_EXAMPLE} EQUAL 1)
	set(PATH_H_SRC
		"Command"
		)
	set(NAME_EXAMPEL
		__EXAMPLE_COMMAND_PRINT__
	)
###-------------------------------------------------------------------------
elseif(${NUMBER_EXAMPLE} EQUAL 2)
	set(PATH_H_SRC
		"ActiveObjectEngine"
		)
	set(NAME_EXAMPEL
		__EXAMPLE_ACTIVE_OBJECT_SLEEPCOMMAND__
	)
###-------------------------------------------------------------------------
elseif(${NUMBER_EXAMPLE} EQUAL 3)
	set(PATH_H_SRC
		"TemplateMethod"
		)
	set(NAME_EXAMPEL
		__EXAMPLE_TEMPLATE_METHOD_QUICK_SORT__
	)
###-------------------------------------------------------------------------
elseif(${NUMBER_EXAMPLE} EQUAL 4)
	set(PATH_H_SRC
		"Strategy"
		)
	set(NAME_EXAMPEL
		__EXAMPLE_STRATEGY_QUICK_SORT__
	)
###-------------------------------------------------------------------------
elseif(${NUMBER_EXAMPLE} EQUAL 5)
	set(PATH_H_SRC
		"Singleton"
		)
	set(NAME_EXAMPEL
		__EXAMPLE_SIMPEL_SINGLETON__
	)
###-------------------------------------------------------------------------
elseif(${NUMBER_EXAMPLE} EQUAL 6)
	set(PATH_H_SRC
		"Monostate"
		)
	set(NAME_EXAMPEL
		__EXAMPLE_MONOSTATE_TURNSTILE__
	)
###-------------------------------------------------------------------------
elseif(${NUMBER_EXAMPLE} EQUAL 7)
	set(PATH_H_SRC
		"Factory"
		)
	set(NAME_EXAMPEL
		__EXAMPLE_SHAPE_FACTORY__
	)
###-------------------------------------------------------------------------
elseif(${NUMBER_EXAMPLE} EQUAL 8)
	set(PATH_H_SRC
		"Composite/CompositeShape"
		)
	set(NAME_EXAMPEL
		__EXAMPLE_COMPOSITE_SHAPE__
	)
endif()


file(GLOB TARGET_SRC "${PATH_H_SRC}/*.cpp")
file(GLOB TARGET_H "${PATH_H_SRC}/*.h")

SET(TARGET_H
	${CONFIGURATE_FILE}
	${TARGET_H}
)

# Configuration file to do correct compilation of example
configure_file(
	"${PROJECT_SOURCE_DIR}/Config.h.in"
	"${PROJECT_SOURCE_DIR}/Config.h"
)
message(${NAME_EXAMPEL})

# Add source to this project's executable.
add_executable (Object-oriented_programming "main.cpp" ${TARGET_H} ${TARGET_SRC})

# TODO: Add tests and install targets if needed.
