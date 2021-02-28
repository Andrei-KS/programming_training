# CMakeList.txt : CMake project for BuildWithCMake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
project("DifferentLib")
set(CMAKE_CXX_STANDARD 11)

message(${PROJECT_NAME})


option(WITHOUTLIBS "" ON)
option(STATICLIB "" OFF)
option(__DECLSPEC__ "" OFF)
option(__EXPORTING__ "" OFF)
set(__LIBSTRING__)

file(GLOB SRC "${PROJECT_SOURCE_DIR}/src/main.cpp")

if(WITHOUTLIBS)
	# build without libs
	file(GLOB SRC "${PROJECT_SOURCE_DIR}/src/*.cpp")
	set(__LIBSTRING__ "WithoutLIB")
else()
	file(GLOB DIR_SRC_LIB "${PROJECT_SOURCE_DIR}/src/MyFunction.cpp")
	if(STATICLIB)
		set(__LIBSTRING__ "WithStaticLIB")
		add_library(${PROJECT_NAME}lib STATIC ${DIR_SRC_LIB})
		target_include_directories(${PROJECT_NAME}lib PUBLIC "${PROJECT_SOURCE_DIR}/include")
	else()
		set(__LIBSTRING__ "WithShareLIB")
		add_library(${PROJECT_NAME}lib SHARED ${DIR_SRC_LIB})
		target_include_directories(${PROJECT_NAME}lib PUBLIC "${PROJECT_SOURCE_DIR}/include")
	endif()
endif()

message("${SRC}")
configure_file(${PROJECT_SOURCE_DIR}/include/config.h.cmake ${PROJECT_SOURCE_DIR}/include/config.h)

include_directories("${PROJECT_SOURCE_DIR}/include")
add_executable(${PROJECT_NAME} "${SRC}")

if(WITHOUTLIBS)
	message("to do nothing")
else()
	if(STATICLIB)
		target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}lib)
	else()
		target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}lib)
	endif()
endif()