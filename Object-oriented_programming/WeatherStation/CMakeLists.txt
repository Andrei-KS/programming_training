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
List(APPEND includePath 
	"include"
	)

List(APPEND srcPath 
	"src"
	)

List(APPEND namesSrcFiles
	"TemperatureSensor"
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
	)

List(APPEND nameslib
	)

List(APPEND testPath
	"test"
	)

List(APPEND namesTestFiles
	"mainTest"
	"TestTemperatureSensorTest"
	"TestBarometricPressureSensorTest"
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
	)