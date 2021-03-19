

cmake_minimum_required (VERSION 3.8)

project(PayrollSystemToPackages)
set(CMAKE_CXX_STANDARD 11)

enable_testing()
set(CTEST_PROJECT_NAME "MyProject")
set(CTEST_NIGHTLY_START_TIME "01:00:00 UTC")

function(GetStaticLibrary NamePackege)
	message("Lilbrary ${NamePackege} is build")
	# Local Path to source of packege
	set(PATH_SRC "src/${NamePackege}")

	# get all paths of files for source of packege
	file(GLOB TARGET_SRC "${PATH_SRC}/*.cpp")
	set(TestFiles ${TARGET_SRC})

	# Delete path to test cpp file in packege
	list(FILTER TARGET_SRC EXCLUDE REGEX "Test.cpp")
	list(FILTER TestFiles INCLUDE REGEX "Test.cpp")

	message(${TARGET_SRC})
	if(NOT TestFiles STREQUAL "")
		message(${TestFiles})
	endif()
	message("${PROJECT_SOURCE_DIR}/include/${NamePackege}/")

	add_library(${NamePackege} STATIC ${TARGET_SRC})
	target_include_directories(${NamePackege} PUBLIC "${PROJECT_SOURCE_DIR}/include/${NamePackege}/")	
	target_include_directories(${NamePackege} PUBLIC "${PROJECT_SOURCE_DIR}/include/")

	if(NOT TestFiles STREQUAL "")
		add_executable (${NamePackege}_test ${TestFiles})
		target_include_directories(${NamePackege}_test PUBLIC "${PROJECT_SOURCE_DIR}/include/${NamePackege}/")
		target_link_libraries(${NamePackege}_test PRIVATE ${NamePackege})
		add_test(NAME ${NamePackege}_test COMMAND ${NamePackege}_test)
	endif()
endfunction()

GetStaticLibrary(Date)
GetStaticLibrary(PayrollDomain)
GetStaticLibrary(PayrollDatebase)
add_executable (${PROJECT_NAME} "main.cpp")