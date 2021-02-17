# CMakeList.txt : CMake project for Object-oriented_programming, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(NUMBER_EXAMPLE 6)

# Configuration file to do correct compilation of example
set(CONFIGURATE_FILE "ConfigurationFile.h")

# Local header files here ONLY
SET(TARGET_H)

# Local source files here
SET(TARGET_SRC)

# Local Path to header and src
set(PATH_H_SRC)

if(${NUMBER_EXAMPLE} EQUAL 1)
	set(PATH_H_SRC
		"Command"
		)
	file(WRITE
		${CONFIGURATE_FILE}
		"#define __EXAMPLE_COMMAND_PRINT__"
		)

elseif(${NUMBER_EXAMPLE} EQUAL 2)
	set(PATH_H_SRC
		"ActiveObjectEngine"
		)
	file(WRITE
		${CONFIGURATE_FILE}
		"#define __EXAMPLE_ACTIVE_OBJECT_SLEEPCOMMAND__"
		)
		
elseif(${NUMBER_EXAMPLE} EQUAL 3)
	set(PATH_H_SRC
		"TemplateMethod"
		)
	file(WRITE
		${CONFIGURATE_FILE}
		"#define __EXAMPLE_TEMPLATE_METHOD_QUICK_SORT__"
		)

elseif(${NUMBER_EXAMPLE} EQUAL 4)
	set(PATH_H_SRC
		"Strategy"
		)
	file(WRITE
		${CONFIGURATE_FILE}
		"#define __EXAMPLE_STRATEGY_QUICK_SORT__"
		)

elseif(${NUMBER_EXAMPLE} EQUAL 5)
	set(PATH_H_SRC
		"Singleton"
		)
	file(WRITE
		${CONFIGURATE_FILE}
		"#define __EXAMPLE_SIMPEL_SINGLETON__"
		)
elseif(${NUMBER_EXAMPLE} EQUAL 6)
	set(PATH_H_SRC
		"Monostate"
		)
	file(WRITE
		${CONFIGURATE_FILE}
		"#define __EXAMPLE_MONOSTATE_TURNSTILE__"
		)
		
endif()


file(GLOB TARGET_SRC "${PATH_H_SRC}/*.cpp")
file(GLOB TARGET_H "${PATH_H_SRC}/*.h")

SET(TARGET_H
	${CONFIGURATE_FILE}
	${TARGET_H}
)

message(${TARGET_H})
message(${TARGET_SRC})

# Add source to this project's executable.
add_executable (Object-oriented_programming "main.cpp" ${TARGET_H} ${TARGET_SRC})

# TODO: Add tests and install targets if needed.
