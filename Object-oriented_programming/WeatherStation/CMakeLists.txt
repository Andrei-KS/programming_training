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

# create LmyLibMath lib
# setting arguments for a function  CreatPackageFromFiles
set(NameLib "LmyLibMath")
set(ListPathToInclude)
set(ListPathToSrc)
set(ListNamesSRCfiles)
set(ListPathToLibs)
List(APPEND ListPathToInclude 
	"include"
	)

List(APPEND ListPathToSrc 
	"src"
	)

List(APPEND ListNamesSRCfiles
	"myLibMath"
	)

List(APPEND ListPathToLibs
	)
CreatLibFromFiles(${NameLib})
# add test
set(NameTest UTestMath)
set(ListPathToTestSrc)
set(ListNamesTestSRCfiles)
List(APPEND ListPathToTestSrc
	"test"
	)
List(APPEND ListNamesTestSRCfiles
	"UTestMath"
	)

List(APPEND ListPathToLibs
	"${PROJECT_BINARY_DIR}/${NameLib}"
	)
CreatTestForLib(${NameTest})

# create LWeatherStation lib
# setting arguments for a function  CreatPackageFromFiles
set(NameLib "LWeatherStation")
set(ListPathToInclude)
set(ListPathToSrc)
set(ListNamesSRCfiles)
set(ListPathToLibs)

List(APPEND ListPathToInclude 
	"include"
	)

List(APPEND ListPathToSrc 
	"src"
	)

List(APPEND ListNamesSRCfiles
	"TemperatureSensor"
	"TemperatureSensorImp"
	"TemperatureType"
	"TestTemperatureSensor"
	"Observable"
	"Observer"
	"MonitoringScreen"
	"MonitoringScreenImplementation"
	"TemperatureObserver"
	"ObserverMScreen"
	"BarometricPressureSensor"
	"BarometricPressureSensorImp"
	"TestBarometricPressureSensor"
	"TestBarometricPressureSensorTest"
	"BarometricPressureObserver"
	"BarometricPressureTrendSensor"
	"BarometricPressureTrendObserver"
	"AlarmListener"
	"AlarmClock"
	"StationToolkit"
	"TestStationToolkit"
	"ClockListner"
	"AlarmClockImp"
	"TestAlarmClockImp"
	)

List(APPEND ListPathToLibs
	"${PROJECT_BINARY_DIR}/LmyLibMath"
	)
CreatLibFromFiles(${NameLib})
# add test BarometricPressureSensor
set(NameTest LWS_UTest_BarometricPressureSensor)
set(ListPathToTestSrc)
set(ListNamesTestSRCfiles)
List(APPEND ListPathToTestSrc
	"test"
	)
List(APPEND ListNamesTestSRCfiles
	"mainUTest"
	"TestBarometricPressureSensorTest"
	"TestMonitoringScreenImplementation"
	)

List(APPEND ListPathToLibs
	"${PROJECT_BINARY_DIR}/${NameLib}"
	)
CreatTestForLib(${NameTest})

# add test TemperatureSensorTest
set(NameTest LWS_UTest_TemperatureSensor)
set(ListNamesTestSRCfiles)
List(APPEND ListNamesTestSRCfiles
	"mainUTest"
	"TestTemperatureSensorTest"
	"TestMonitoringScreenImplementation"
	)
CreatTestForLib(${NameTest})

###
# end block of create libs
###


# include header to main function
include_directories("${PROJECT_SOURCE_DIR}/include")

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} 
	PRIVATE "${PROJECT_BINARY_DIR}/LWeatherStation.lib"
	PRIVATE "${PROJECT_BINARY_DIR}/LmyLibMath.lib"
	)