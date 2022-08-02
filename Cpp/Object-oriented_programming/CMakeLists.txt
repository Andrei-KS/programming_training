# CMakeList.txt : CMake project for Object-oriented_programming, include source and define
# project specific logic here.
#

#[[-------------------------------------------------------------------------
                    Configuration cmake project
]]#-------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.8)
enable_testing()

project ("Object-oriented_programming")
# Include sub-projects.
 add_subdirectory ("General_Patterns_OOP")
 add_subdirectory ("PayrollSystem")
 add_subdirectory ("PayrollSystemToPackages")
 add_subdirectory ("DigitalClock")
 add_subdirectory ("SystemOfShoppingBasket")
 add_subdirectory("WeatherStation")