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

# create LmyLibMath lib
set(NamePackege LmyLibMath)
if(NOT EXISTS "${PROJECT_BINARY_DIR}/${NamePackege}.lib")
	file(WRITE "${PROJECT_BINARY_DIR}/${NamePackege}.lib" "IS EMPTY")
endif()

set(includePath)
set(srcPath)
set(namesSrcFiles)
set(nameslib)
set(testPath)
set(namesTestFiles)

List(APPEND includePath 
	"include"
	)

List(APPEND srcPath 
	"src"
	)

List(APPEND namesSrcFiles
	"myLibMath"
	)

List(APPEND nameslib
	)

List(APPEND testPath
	"test"
	)

List(APPEND namesTestFiles
	"mainTestMath"
	)

include(CreatPackageFromFiles.cmake)
CreatPackageFromFiles(LmyLibMath
	NESINCLUDE ${includePath}
	NESSRCPATH ${srcPath}
	NESSRC ${namesSrcFiles}
	NESLIB ${nameslib}
	NESTEST ${namesTestFiles}
	NESTESTPATH ${testPath}
	)

# create LWeatherStation lib
set(NamePackege LWeatherStation)
if(NOT EXISTS "${PROJECT_BINARY_DIR}/${NamePackege}.lib")
	file(WRITE "${PROJECT_BINARY_DIR}/${NamePackege}.lib" "IS EMPTY")
endif()
set(includePath)
set(srcPath)
set(namesSrcFiles)
set(nameslib)
set(testPath)
set(namesTestFiles)

List(APPEND includePath 
	"include"
	)

List(APPEND srcPath 
	"src"
	)

List(APPEND namesSrcFiles
	"TemperatureSensor"
	"TemperatureType"
	"TestTemperatureSensor"
	"Observable"
	"Observer"
	"MonitoringScreen"
	"MonitoringScreenImplementation"
	"TemperatureObserver"
	"ObserverMScreen"
	"BarometricPressureSensor"
	"TestBarometricPressureSensor"
	"TestBarometricPressureSensorTest"
	"BarometricPressureObserver"
	"BarometricPressureTrendSensor"
	"BarometricPressureTrendObserver"
	"AlarmListener"
	"AlarmClock"
	)

List(APPEND nameslib
	"${PROJECT_BINARY_DIR}/LmyLibMath"
	)

List(APPEND testPath
	"test"
	)

List(APPEND namesTestFiles
	"mainTest"
	"TestTemperatureSensorTest"
	"TestBarometricPressureSensorTest"
	"TestMonitoringScreenImplementation"
	)

include(CreatPackageFromFiles.cmake)
CreatPackageFromFiles(LWeatherStation
	NESINCLUDE ${includePath}
	NESSRCPATH ${srcPath}
	NESSRC ${namesSrcFiles}
	NESLIB ${nameslib}
	NESTEST ${namesTestFiles}
	NESTESTPATH ${testPath}
	)

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