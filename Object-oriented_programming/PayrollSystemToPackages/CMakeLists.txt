

cmake_minimum_required (VERSION 3.8)

project(PayrollSystemToPackages)
set(CMAKE_CXX_STANDARD 11)
enable_testing()
set(CTEST_PROJECT_NAME "MyProject")
set(CTEST_NIGHTLY_START_TIME "01:00:00 UTC")

#first arg is name lib, that will creted, next args is necessary libs to create current lib
function(GetStaticLibrary)
	#get the name of the package and the names of the libraries that will need to be used 
	set(function_args_ ${ARGV})
	set(FirstArgIsNotGet ON)
	set(LibNames)
	set(NamePackege)
	foreach(currentArg IN LISTS function_args_)
		if(FirstArgIsNotGet)
			set(FirstArgIsNotGet OFF)
			set(NamePackege ${currentArg})
		else()
			list(APPEND LibNames ${currentArg})
			if(currentArg MATCHES ${NamePackege})
				break()
			endif()
		endif()
	endforeach()

	message(STATUS "Lilbrary name is ${NamePackege}")
	message(STATUS "Necessary libs: ${LibNames}")

	# Local Path to source of packege
	set(PATH_SRC "src/${NamePackege}")

	# get all paths of files for source of packege
	file(GLOB TARGET_SRC "${PATH_SRC}/*.cpp")
	set(TestFiles ${TARGET_SRC})

	list(FILTER TARGET_SRC EXCLUDE REGEX "Test.cpp")
	list(FILTER TestFiles INCLUDE REGEX "Test.cpp")

	if(TARGET_SRC)
		message(STATUS "TARGET_SRC: ${TARGET_SRC}")
	endif()
	if(TestFiles)
		message(STATUS "TestFiles: ${TestFiles}")
	endif()
	message(STATUS "${NamePackege} Path to include: ${PROJECT_SOURCE_DIR}/include/${NamePackege}/")
	
	if(TARGET_SRC)
		add_library(${NamePackege} STATIC ${TARGET_SRC})
		target_include_directories(${NamePackege} PUBLIC "${PROJECT_SOURCE_DIR}/include/${NamePackege}/")	
		target_include_directories(${NamePackege} PUBLIC "${PROJECT_SOURCE_DIR}/include/")
	endif()

	if(TestFiles)
		add_executable (${NamePackege}_test ${TestFiles})
		
		target_include_directories(${NamePackege}_test PUBLIC "${PROJECT_SOURCE_DIR}/include/${NamePackege}/")
		target_include_directories(${NamePackege}_test PUBLIC "${PROJECT_SOURCE_DIR}/include/")
		
		set(UsingLibs)
		foreach(currentItem IN LISTS LibNames)
			file(GLOB NameLib "${PROJECT_BINARY_DIR}/${currentItem}.lib")
			list(APPEND UsingLibs ${NameLib})
		endforeach()
		message(STATUS "Using libs: ${UsingLibs}")
		target_link_libraries(${NamePackege}_test PRIVATE ${UsingLibs})
		#target_link_libraries(${NamePackege}_test PRIVATE ${NamePackege})
		add_test(NAME ${NamePackege}_test COMMAND ${NamePackege}_test)
	endif()
endfunction()

list(APPEND Packages 
	Date
	PayrollDomain
	PayrollDatabase
	TransactionApplication
	AbstractTransaction
	TransactionFactory
	PayrollFactory
	PayrollImplementation
	TransactionImplementation
)

foreach(packege IN LISTS Packages)
	GetStaticLibrary(${packege} ${Packages})
endforeach()

add_executable (${PROJECT_NAME} "main.cpp")
