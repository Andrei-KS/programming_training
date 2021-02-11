# CMakeList.txt : CMake project for Object-oriented_programming, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(NUMBER_EXAMPLE 2)

# Configuration file to do correct compilation of example
set(CONFIGURATE_FILE "ConfigurationFile.h")

# Local header files here ONLY
SET(TARGET_H
	${CONFIGURATE_FILE}
	)

# Local source files here
SET(TARGET_SRC)

if(${NUMBER_EXAMPLE} EQUAL 1)
	set(TARGET_H
		${TARGET_H}
		"Command/CommandPrint.h"
		)
	SET(TARGET_SRC
		"Command/CommandPrint.cpp"
		)
	file(WRITE
		${CONFIGURATE_FILE}
		"#define __COMMAND_PRINT__"
		)

elseif(${NUMBER_EXAMPLE} EQUAL 2)
	set(TARGET_H
		${TARGET_H}
		"ActiveObjectEngine/ActiveObjectEngine.h"
		"ActiveObjectEngine/TestSleepCommand.h"
		"ActiveObjectEngine/SleepCommand.h"
		)
	SET(TARGET_SRC
		"ActiveObjectEngine/ActiveObjectEngine.cpp"
		"ActiveObjectEngine/TestSleepCommand.cpp"
		"ActiveObjectEngine/SleepCommand.cpp"
		)
	file(WRITE
		${CONFIGURATE_FILE}
		"#define __ACTIVE_OBJECT_SLEEPCOMMAND__"
		)
endif()

# Add source to this project's executable.
add_executable (Object-oriented_programming "main.cpp" ${TARGET_H} ${TARGET_SRC})

# TODO: Add tests and install targets if needed.
