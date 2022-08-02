# CMakeList.txt : CMake project for Object-oriented_programming, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(WeatherStation)

set(CMAKE_CXX_STANDARD 11)
enable_testing()
set(CTEST_PROJECT_NAME "WeatherStation")
set(CTEST_NIGHTLY_START_TIME "01:00:00 UTC")
###
# block of create libs
###
include(CreatLibFromFiles.cmake)
include(CreatTestForLib.cmake)

# create LmyUtest lib
# setting arguments for a function  CreatPackageFromFiles
set(NameLib "LmyUtest")
set(prefixDirectory)
set(ListPathToInclude)
set(ListPathToSrc)
set(ListNamesSRCfiles)
set(ListPathToLibs)

set(prefixDirectory "_Lib/UTest")
List(APPEND ListPathToInclude 
	"${prefixDirectory}/include"
	)

List(APPEND ListPathToSrc 
	"${prefixDirectory}/src"
	)

List(APPEND ListNamesSRCfiles
	"mainUTest"
	)

List(APPEND ListPathToLibs
	)
CreatLibFromFiles(${NameLib})

# create LmyLibMath lib
# setting arguments for a function  CreatPackageFromFiles
set(NameLib "LmyLibMath")
set(prefixDirectory)
set(ListPathToInclude)
set(ListPathToSrc)
set(ListNamesSRCfiles)
set(ListPathToLibs)

set(prefixDirectory "_Lib/Math")
List(APPEND ListPathToInclude 
	"${prefixDirectory}/include"
	)

List(APPEND ListPathToSrc 
	"${prefixDirectory}/src"
	)

List(APPEND ListNamesSRCfiles
	)

List(APPEND ListPathToLibs
	)
CreatLibFromFiles(${NameLib})
# add test
set(NameTest UTestMath)
set(ListPathToTestSrc)
set(ListNamesTestSRCfiles)
List(APPEND ListPathToInclude
	"_Lib/UTest/include"
	)
List(APPEND ListPathToTestSrc
	"${prefixDirectory}/test"
	)
List(APPEND ListNamesTestSRCfiles
	"UTestMath"
	)

List(APPEND ListPathToLibs
	"${PROJECT_BINARY_DIR}/${NameLib}"
	"${PROJECT_BINARY_DIR}/LmyUtest"
	)
CreatTestForLib(${NameTest})

# create LmyDate lib
# setting arguments for a function  CreatPackageFromFiles
set(NameLib "LmyDate")
set(prefixDirectory)
set(ListPathToInclude)
set(ListPathToSrc)
set(ListNamesSRCfiles)
set(ListPathToLibs)

set(prefixDirectory "_Lib/Date")
List(APPEND ListPathToInclude 
	"${prefixDirectory}/include"
	)

List(APPEND ListPathToSrc 
	"${prefixDirectory}/src"
	)

List(APPEND ListNamesSRCfiles
	)

List(APPEND ListPathToLibs
	)
CreatLibFromFiles(${NameLib})
# add test
set(NameTest UTestDate)
set(ListPathToTestSrc)
set(ListNamesTestSRCfiles)
List(APPEND ListPathToInclude
	"_Lib/UTest/include"
	)
List(APPEND ListPathToTestSrc
	"${prefixDirectory}/test"
	)
List(APPEND ListNamesTestSRCfiles
	"UTestDate"
	)

List(APPEND ListPathToLibs
	"${PROJECT_BINARY_DIR}/${NameLib}"
	"${PROJECT_BINARY_DIR}/LmyUtest"
	)
CreatTestForLib(${NameTest})

# create LmyStringProcessingUtilits lib
# setting arguments for a function  CreatPackageFromFiles
set(NameLib "LmyStringProcessingUtilits")
set(prefixDirectory)
set(ListPathToInclude)
set(ListPathToSrc)
set(ListNamesSRCfiles)
set(ListPathToLibs)

set(prefixDirectory "_Lib/StringProcessingUtilits")
List(APPEND ListPathToInclude 
	"${prefixDirectory}/include"
	)

List(APPEND ListPathToSrc 
	"${prefixDirectory}/src"
	)

List(APPEND ListNamesSRCfiles
	)

List(APPEND ListPathToLibs
	)
CreatLibFromFiles(${NameLib})
# add test
set(NameTest UTestSplitStringToVector)
set(ListPathToTestSrc)
set(ListNamesTestSRCfiles)
List(APPEND ListPathToInclude
	"_Lib/UTest/include"
	)
List(APPEND ListPathToTestSrc
	"${prefixDirectory}/test"
	)
List(APPEND ListNamesTestSRCfiles
	"UTestSplitStringToVector"
	)

List(APPEND ListPathToLibs
	"${PROJECT_BINARY_DIR}/${NameLib}"
	"${PROJECT_BINARY_DIR}/LmyUtest"
	)
CreatTestForLib(${NameTest})
# add test UTestGetStringOfGivenLength
set(NameTest UTestGetStringOfGivenLength)
set(ListNamesTestSRCfiles)
List(APPEND ListNamesTestSRCfiles
	"UTestGetStringOfGivenLength"
	)
CreatTestForLib(${NameTest})



# create LWeatherStation lib
# setting arguments for a function  CreatPackageFromFiles
set(NameLib "LWeatherStation")
set(prefixDirectory)
set(ListPathToInclude)
set(ListPathToSrc)
set(ListNamesSRCfiles)
set(ListPathToLibs)

List(APPEND ListPathToInclude 
	"include"
	"_Lib/Math/include"
	"_Lib/Date/include"
	"_Lib/StringProcessingUtilits/include"
	)

List(APPEND ListPathToSrc 
	"src"
	)

List(APPEND ListNamesSRCfiles
	)

List(APPEND ListPathToLibs
	"${PROJECT_BINARY_DIR}/LmyLibMath"
	"${PROJECT_BINARY_DIR}/LmyDate"
	"${PROJECT_BINARY_DIR}/LmyStringProcessingUtilits"
	)
CreatLibFromFiles(${NameLib})

# add test BarometricPressureSensor
set(NameTest LWS_UTest_BarometricPressureSensor)
set(ListPathToTestSrc)
set(ListNamesTestSRCfiles)
List(APPEND ListPathToInclude
	"_Lib/UTest/include"
	)
List(APPEND ListPathToTestSrc
	"test"
	)
List(APPEND ListNamesTestSRCfiles
	"TestBarometricPressureSensorTest"
	"TestMonitoringScreenImplementation"
	)

List(APPEND ListPathToLibs
	"${PROJECT_BINARY_DIR}/${NameLib}"
	"${PROJECT_BINARY_DIR}/LmyUtest"
	)
CreatTestForLib(${NameTest})

# add test TemperatureSensorTest
set(NameTest LWS_UTest_TemperatureSensor)
set(ListNamesTestSRCfiles)
List(APPEND ListNamesTestSRCfiles
	"TestTemperatureSensorTest"
	"TestMonitoringScreenImplementation"
	)
CreatTestForLib(${NameTest})

###
# end block of create libs
###

if(NOT EXISTS "${PROJECT_BINARY_DIR}/_StorageForData")
	file(WRITE "${PROJECT_BINARY_DIR}/_StorageForData" "")
endif()

# include header to main function
include_directories("${PROJECT_SOURCE_DIR}/include;${PROJECT_SOURCE_DIR}/_Lib/Date/include")

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} 
	PRIVATE "${PROJECT_BINARY_DIR}/LWeatherStation.lib"
	PRIVATE "${PROJECT_BINARY_DIR}/LmyLibMath.lib"
	PRIVATE "${PROJECT_BINARY_DIR}/LmyDate.lib"
	PRIVATE "${PROJECT_BINARY_DIR}/LmyStringProcessingUtilits.lib"
	)