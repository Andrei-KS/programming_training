# CMakeList.txt : CMake project for Сpp, include source and define
# project specific logic here.
#

#[[----------------------------------------------------------------------------
                    Configuration cmake project
]]#----------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.8)

project("Stroustrup_principles_and_practice")
set(CMAKE_CXX_STANDARD 11)
enable_testing()
set(CTEST_PROJECT_NAME "Stroustrup_principles_and_practice")
set(CTEST_NIGHTLY_START_TIME "01:00:00 UTC")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG_BUILD")

# connecting the necessary modules
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/_cmake_lib")
#include(creat_lib_from_files)
#include(creat_test_for_lib)
#include(copy_folder)

#[[-------------------------------------------------------------------------
                    The builder's configuration of main program
]]#-------------------------------------------------------------------------
# Setting main program
# Setting SRC
set(list_Path_To_Src)
List(APPEND list_Path_To_Src
   "${PROJECT_SOURCE_DIR}/src/main.cpp"
)

# Setting header
set(list_Path_To_Include)
List(APPEND list_Path_To_Include
   "${PROJECT_SOURCE_DIR}/include"
)

# include header to main function
include_directories(${list_Path_To_Include})

# Add source to this project's executable.
add_executable (${PROJECT_NAME} ${list_Path_To_Src})

#[[----------------------------------------------------------------------------
                    The builder's configurations of libs
]]#----------------------------------------------------------------------------

#[[------------------------------------
                    Example lib 
]]#------------------------------------
# need choice one of example
# naming rule for examples
# [CH](number chapter)[P](number pag)[TASK/EXERC/DRILL/TRY](numbers)[_FLTK]
# TASK/DRILL    - Drill/task 
# EXERC         - Exercises
# TRY           - Try this
# ILLUST        - illustration
# if _FLTK is added to the name FLTK will include in the project
# example1: CH1P1EXERC1
# example2: CH1P1EXERC1_FLTK
#
# list of examples:
#-------------------------------------- Chapter_3
#-------------------------------------- Objects, Types, and Values
# CH3P106TRY                / Change the "The name and age" program so that it will display age in months. Entered age is expressed in years
# CH3P108TRY                / Change the "Display working of operators" so that double will become int
# CH3P124TASK1              / Modify the "Hi, first_name" program
# CH3P124TASK2              / Add string "How are you?I'm fine. I miss you." to cpp file of CH3P124TASK1 task
# CH3P124TASK3              / Add new variable friend_name and the string "How long have you met friend_name?" 
# CH3P124TASK4              / Add new variable friend_sex and the string "If you see friend_name, please ask him/her to call me."
# CH3P125TASK5              / Add new variable age, string "I heard you just celebrated your birthday and you are age years" and checking age
# CH3P125TASK6              / Add if statement for age
# CH3P125TASK7              / Add string "Sincerely yours" and place for signature
# CH3P127EXERC2             / Converting ml to km
# CH3P127EXERC4             / Arithmetical operation on int
# CH3P127EXERC5             / Arithmetical operation on double
# CH3P127EXERC6             / Enter three integers and then outputs them in ascending order 
# CH3P127EXERC7             / Enter three strings and then outputs them in ascending order 
# CH3P127EXERC8             / check parity int
# CH3P127EXERC10            / The simple calculator
#-------------------------------------- Chapter_4
#-------------------------------------- Computation
# CH4P146TRY                / Converting UAH, RUB and CNY to USD
# CH4P149TRY                / Converting UAD, CNY, EUR, GBP or RUB to USD using switch
# CH4P151TRY                / Display char and its number in table
# CH4P154TRY                / Display char A-Za-z and its number in table using for
# CH4P157TRY                / Implementation square function without multiply
# CH4P165TRY                / Implementation a program to muffle unwanted words
# CH4P166TASK1              / Read and display two int
# CH4P166TASK2              / display max and min
# CH4P166TASK3              / display numbers are equal
# CH4P166TASK4              / Work with double
# CH4P166TASK5              / The numbers are almost equal
# CH4P166TASK6              / Reading more than two
# CH4P167TASK7              / Reading num and unit
# CH4P167TASK8              / Reading num and unit only [cm], [m], [in] and [ft]
# CH4P167TASK9              / Count numbers and calculate sum in [m]
# CH4P167TASK10             / Converting all entered values in [m]
# CH4P167TASK11             / sort values in vector
# CH4P169EXERC2             / find median
# CH4P169EXERC3             / Distances between cities
# CH4P169EXERC4             / Guess a number from 1 to 100
# CH4P169EXERC5             / The simple calculator
# CH4P169EXERC8             / Grains and cells 
#-------------------------------------- Chapter_5
#-------------------------------------- Errors
# CH5P188TRY                / Add checking
# CH5P198TRY                / Break program and get invalid result
# CH5P199TRY                / Set valid min and max value
# CH5P209TRY                / Find bad value for post condition
# CH5P211TASK               / Fixbug
# CH5P214EXERC2             / Сelsius to kelvin  
# CH5P214EXERC3             / Сelsius to kelvin, add checking less than -273.15C
# CH5P214EXERC4             / Сelsius to kelvin, add checking less than -273.15C into function
# CH5P214EXERC5             / Kelvin to celsius
# CH5P214EXERC6             / Celsius to fahrenheit and fahrenheit to celsius
# CH5P214EXERC7             / Quadratic equation
# CH5P214EXERC8             / The sum of the first N numbers
#-------------------------------------- Chapter_6
#-------------------------------------- Writing a Program
# CH6P250TRY                / First version calculator
# CH6P262TRY                / Second version calculator
# CH6P263TASK               / Correction of the second version
# CH6P264EXERC2             / Added '{' and '}' to second version calculator
# CH6P264EXERC3             / Added factorial function (number!) to second version calculator
# CH6P265EXERC6             / Simple english grammar
# CH6P265EXERC7             / A grammar for bitwise logical expressions
#-------------------------------------- Chapter_7
#-------------------------------------- Completing a Program
# CH7P297TASK4              / Data for tests
# CH7P297_298TASKS6_11      / Add a predefined name k meaning 1000, a square root functions
#                           / sqrt() and pow(x,i) to mean “Multiply x with itself i times”.
#                           / Change the “declaration keyword” from let to #.
#                           / Change the “quit keyword” from quit to exit.
# CH7P299EXERC1_2           / Allow underscores in the calculator’s variable names.
#                           / Provide an assignment operator, '='.
# CH7P299EXERC3             / Provide named constants that you really can’t change the value of.
# CH7P299EXERC4             / Define a class called Symbol_table
# CH7P299_300EXERC5_6       / Modify  Token_stream::get() to return Token(print) when it sees a newline.
#                           / Add key h/H/help for helping information
#
# Below linking chapters and exercises is linked to the
# book of Programming Principles and Practice Using C++/
# Second Edition/ Bjarne Stroustrup/ 2014/
# ISBN-13: 978-0-321-99278-9
#-------------------------------------- Chapter_8
#-------------------------------------- Technicalities: Functions, etc.
# CH8P297DRILL1             / Create three files:my.h, my.cpp, and use.cpp.
# CH8P298DRILL3             / Write a program using a single file containing three namespacesX, Y, and Z
# CH8P300EXERC1             / Modify the calculator program to make the input stream
#                           / an explicit parameter, rather than simply using cin.
# CH8P300EXERC2             / Write a function print() that prints a vector of ints
# CH8P300EXERC3             / Create a vector of Fibonacci numbers
# CH8P300EXERC5             / Write two functions that reverse the order of elements in a vector<int>
# CH8P301EXERC6             / Write two functions that reverse the order of elements in a vector<string>
#-------------------------------------- Chapter_9
#-------------------------------------- Technicalities: Classes, etc.
# CH9P339EXERC2             / Design and implement a Name_pairs class holding (name,age) pair
# CH9P339EXERC3             / Replace Name_pair::print() with a (global) operator << and define ==
#                           / and != for Name_pairs.
# CH9P339EXERC5             / Design and implement a Book class.
# CH9P340EXERC6             / Add operators for the Book class.
# CH9P340EXERC7             / Create an enumerated type for the Book class called Genre.
# CH9P340EXERC8             / Create a Patron class for the library.
# CH9P340EXERC9             / Create a Library class.
# CH9P340EXERC10            / Implement leapyear() in Chrono::Date.
# CH9P340EXERC11            / Design and implement a set of useful helper functions for the Date class.
# CH9P340EXERC13            / Design and implement a rational number class, Rational.
# CH9P341EXERC14            / Design and implement a Money class for calculations involving dollars and cents.
# CH9P341EXERC15            / Refine the Money class by adding a currency.
# CH9P341EXERC16            / Define an input operator (>>) and output operator (<<) for the Money.
#-------------------------------------- Chapter_10
#-------------------------------------- Input and Output Streams
# CH10P376DRILL1            / Start a program to work with points. Begin by defining the data type
#                           / Point that has two coordinate members x and y
# CH10P376DRILL2            / Prompt the user to input seven (x,y) pairs. As the data is entered,
#                           / store it in a vector of Points called original_points
# CH10P376DRILL4            / Open an ofstream and output each point to a file named mydata.txt.
# CH10P376DRILL5            / Close the ofstream and then open an ifstream for mydata.txt. Read the data
#                           / from mydata.txt and store it in a new vector called processed_points.
# CH10P376DRILL6_7          / Print the data elements from both vectors. Compare the two vectors
#                           / and print Something's wrong! if the number of elements or
#                           / the values of elements differ
# CH10P377EXERC1            / Write a program that produces the sum of all the numbers in a file of
#                           / whitespace-separated integers.
# CH10P377EXERC2            / Write a program that creates a file of data in the form of the temperature
#                           / Reading type. For testing, fill the file with at least 50
#                           / “temperature readings.” Call this program and the file it
#                           / creates raw_temps.txt.
# CH10P377EXERC3            / Write a program that reads the data from raw_temps.txt created
#                           / in exercise 2 into a vector and then calculates the mean
#                           / and median temperatures in your data set.
# CH10P377EXERC4            / Modify the program from exercise 2 to include a temperature 
#                           / suffix c for Celsius or f for Fahrenheit temperatures. Then
#                           / modify the program from exercise 3 to test each temperature,
#                           / converting the Celsius readings to Fahrenheit before putting
#                           / them into the vector
# CH10P377EXERC5            / Write the function print_year().
# CH10P377EXERC6            / Define a Roman_int class for holding Roman numerals (as ints) with a
#                           / << and >>. Provide Roman_int with an as_int() member that returns
#                           / the int value, so that if r is a Roman_int, we can write
#                           / cout << "Roman" << r << " equals " << r.as_int() << '\n';.
# CH10P378EXERC7            / Make a version of the calculator from Chapter 7 that accepts Roman
#                           / numerals rather than the usual Arabic ones, for example, XXI + CIV == CXXV.
# CH10P378EXERC8            / Write a program that accepts two file names and produces a new file that
#                           / is the contents of the first file followed by the contents of the second; that
#                           / is, the program concatenates the two files.
# CH10P378EXERC9            / Write a program that takes two files containing sorted whitespace-separated
#                           / words and merges them, preserving order.
# CH10P378EXERC10           / Add a command from x to the calculator from Chapter 7 that makes it
#                           / take input from a file x. Add a command to y to the calculator that makes
#                           / it write its output (both standard output and error output) to file y. 
# CH10P378EXERC11           / Write a program that produces the sum of all the whitespace-separated
#                           / integers in a text file. For example, bears: 17 elephants 9 end should output 26.
#-------------------------------------- Chapter_11
#-------------------------------------- Customizing Input and Output
# CH11P382TRY               / Output your birth year in decimal, hexadecimal, and octal form. Label eachvalue.
#                           / Label each value.
# CH11P384TRY               / Complete the code fragment above to make it into a program. Try the suggested input; 
#                           / then type in 1234 1234 1234 1234
# CH11P386TRY               / Write some code to print the number 1234567.89 three times, first using
#                           / defaultfloat, then fixed, then scientific.
# CH11P388TRY               / Make a simple table including the last name, first name, telephone number,
#                           / and email address for yourself and at least five of your friends.
# CH11P407DRILL1_4          / Declare an integer birth_year and assign it the year you were born.
#                           / Output your birth_year in decimal, hexadecimal, and octal form.
#                           / Label each value with the name of the base used.
#                           / Did you line up your output in columns using the tab character? If not,
#                           / do it.
# CH11P408EXERC1            / Write a program that reads a text file and converts its input to all lower
#                           / case, producing a new file.
# CH11P408EXERC2            / Write a program that given a file name and a word outputs each line that
#                           / contains that word together with the line number. Hint: getline()
# CH11P408EXERC3            / Write a program that removes all vowels from a file (“disemvowels”). For
#                           / example, Once upon a time! becomes nc pn tm!.
# CH11P408EXERC4            / Write a program that prompts the user to enter several integers in any
#                           / combination of octal, decimal, or hexadecimal, using the 0 and 0x base
#                           / suffixes; interprets the numbers correctly; and converts them to decimal
#                           / form.Then your program should output the values in properly spaced
#                           / columns like this:
#                           /    0x43 hexadecimal converts to 67 decimal
# CH11P408EXERC5            / Write a program that reads strings and for each string outputs the
#                           / character classification of each character, as defined by
#                           / the character classification. Note that a character can have several
#                           / classifications (e.g., x is both a letter and an alphanumeric).
# CH11P408EXERC6            / Write a program that replaces punctuation with whitespace. Consider
#                           / . (dot), ; (semicolon), , (comma), ? (question mark), - (dash), ' (single
#                           / quote) punctuation characters. Don’t modify characters within a pair of
#                           / double quotes ("). For example, " - don't use the as-if rule." becomes
#                           / " don t use the as if rule ".
# CH11P408EXERC7            / Modify the program from the previous exercise so that it replaces don't
#                           / with do not, can't with can not, etc.; leaves hyphens within words intact
#                           / (so that we get “ do not use the as-if rule ”); and converts all characters
#                           / to lower case.
# CH11P408EXERC8            / Use the program from the previous exercise to make a dictionary.
#                           / Run the result on a multi-page text file, look at the result,
#                           / and see if you can improve the program to make a better dictionary.
# CH11P408EXERC9            / Write a program is content next subprograms: one program that
#                           / converts an ordinary text file into binary and one program that reads
#                           / binary and converts it to text.
# CH11P408EXERC10           / Write a function vector<string> split(const string& s) that returns a vector
#                           / of whitespace-separated substrings from the argument s
# CH11P408EXERC11           / Write a function vector<string> split(const string& s, const string& w)
#                           / that returns a vector of whitespace-separated substrings from
#                           / the argument s, where whitespace is defined as “ordinary whitespace” plus the
#                           / characters in w.
# CH11P408EXERC12           / Reverse the order of characters in a text file. For example, asdfghjkl
#                           / becomes lkjhgfdsa. Warning: There is no really good, portable, and efficient
#                           / way of reading a file backward.
# CH11P408EXERC13           / Reverse the order of words (defined as whitespace-separated strings) in a
#                           / file. For example, Norwegian Blue parrot becomes parrot Blue Norwegian.
#                           / You are allowed to assume that all the strings from the file will fit into
#                           / memory at once.
# CH11P408EXERC14           / Write a program that reads a text file and writes out how many characters
#                           / of each character classification are in the file
# CH11P408EXERC15           / Write a program that reads a file of whitespace-separated numbers and
#                           / outputs a file of numbers using scientific format and precision 8 in four
#                           / fields of 20 characters per line.
# CH11P408EXERC16           / Write a program to read a file of whitespace-separated numbers and
#                           / output them in order (lowest value first), one value per line. Write a value
#                           / only once, and if it occurs more than once write the count of its occurrences
#                           / on its line. For example, 7 5 5 7 3 117 5 should give
#                           /   3
#                           /   5      3
#                           /   7      2
#                           /   117
#-------------------------------------- Chapter_12
#-------------------------------------- A Display Model
# CH12P415_FLTK             / Preparatory work for the start of the graphics learning.
# CH12P415DRILL1_FLTK       / Get an empty Simple_window with the size 600 by 400 and a label My
#                           / window compiled, linked, and run. #include Graph.h and Simple_window.h
#                           / in your code; and include Graph.cpp and Window.cpp in your project.
# CH12P415DRILL2_FLTK       / Now add the examples from §12.7 one by one, testing between each
#                           / added subsection example.
# CH12P438EXERC1_FLTK       / Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the
#                           / Polygon red and the lines of the Rectangle blue.
# CH12P438EXERC2_FLTK       / Draw a 100-by-30 Rectangle and place the text “Howdy!” inside it.
# CH12P438EXERC3_FLTK       / Draw your initials 150 pixels high. Use a thick line. Draw each initial in
#                           / a different color
# CH12P438EXERC4_FLTK       / Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.
# CH12P438EXERC5_FLTK       / Draw a red ¼-inch frame around a rectangle that is three-quarters the
#                           / height of your screen and two-thirds the width. 
# CH12P438EXERC6_FLTK       / What happens when you draw a Shape that doesn’t fit inside its window?
#                           / What happens when you draw a Window that doesn’t fit on your screen?
#                           / Write two programs that illustrate these two phenomena.
# CH12P438EXERC7_FLTK       / Draw a two-dimensional house seen from the front, the way a child
#                           / would: with a door, two windows, and a roof with a chimney. Feel free to
#                           / add details; maybe have “smoke” come out of the chimney.
# CH12P438EXERC8_FLTK       / Draw the Olympic five rings. If you can’t remember the colors, look
#                           / them up.
# CH12P438EXERC9_FLTK       / Display an image on the screen, e.g., a photo of a friend. Label the image
#                           / both with a title on the window and with a caption in the window.
# CH12P438EXERC10_FLTK      / Draw the file diagram from §12.8.
# CH12P438EXERC11_FLTK      / Draw a series of regular polygons, one inside the other. The innermost
#                           / should be an equilateral triangle, enclosed by a square, enclosed by a
#                           / pentagon, etc. For the mathematically adept only: let all the points of
#                           / each N-polygon touch sides of the (N+1)-polygon. Hint: The trigonometric
#                           / functions are found in <cmath> 
# CH12P438EXERC12_FLTK      / A superellipse is a two-dimensional shape defined by the equation
#                           /     m     n
#                           /  |x|   |y|
#                           /  |-| + |-| = 1;  m,n > 0.  
#                           /  |a|   |b|
#                           / Look up superellipse on the web to get a better idea of what such shapes
#                           / look like. Write a program that draws “starlike” patterns by connecting
#                           / points on a superellipse. Take a, b, m, n, and N as arguments. Select N
#                           / points on the superellipse defined by a, b, m, and n. Make the points
#                           / equally spaced for some definition of “equal.” Connect each of those N
#                           / points to one or more other points (if you like you can make the number
#                           / of points to which to connect a point another argument or just use N–1,
#                           / i.e., all the other points).
# CH12P439EXERC13_FLTK      / Find a way to add color to the lines from the previous exercise. Make
#                           / some lines one color and other lines another color or other colors.
#-------------------------------------- Chapter_13
#-------------------------------------- Graphics Classes
# CH13P445ILLUST_FLTK       / "two lines"
# CH13P447ILLUST_FLTK       / "Lines"
# CH13P448ILLUST_FLTK       / "Grid"
# CH13P462ILLUST_FLTK       / "Rectangle"
# CH13P467ILLUST_FLTK       / "Managing unnamed objects"
# CH13P483DRILL1_5_FLTK     / 1. Make an 800-by-1000 Simple_window.
#                           / 2. Put an 8-by-8 grid on the leftmost 800-by-800 part of that window
#                           / (so that each square is 100 by 100).
#                           / 3. Make the eight squares on the diagonal starting from the top
#                           / left corner red (use Rectangle).
#                           / 4. Find a 200-by-200-pixel image (JPEG or GIF) and place three
#                           / copies of iton the grid (each image covering four squares). If
#                           / you can’t find an image that is exactly 200 by 200, use
#                           / set_mask() to pick a 200-by-200 section of a larger image.
#                           / Don’t obscure the red squares.
#                           / 5. Add a 100-by-100 image. Have it move around from square
#                           / to square when you click the “Next” button. Just put wait_for_button()
#                           / in a loop with some code that picks a new square for your image.
# CH13P484EXERC1_FLTK       / Define a class Arc, which draws a part of an ellipse. Hint: fl_arc().
# CH13P484EXERC2_FLTK       / Draw a box with rounded corners. Define a class Box, consisting of four
#                           / lines and four arcs
# CH13P484EXERC3_FLTK       / Define a class Arrow, which draws a line with an arrowhead.
# CH13P484EXERC4_FLTK       / Define functions n(), s(), e(), w(), center(), ne(), se(), sw(), and nw(). Each
#                           / takes a Rectangle argument and returns a Point. These functions define
#                           / “connection points” on and in the rectangle. For example, nw(r) is the
#                           / northwest (top left) corner of a Rectangle called r.
# CH13P484EXERC5_FLTK       / Define the functions from exercise 4 for a Circle and an Ellipse. Place the
#                           / connection points on or outside the shape but not outside the bounding
#                           / rectangle.
# CH13P484EXERC6_FLTK       / Write a program that draws a class diagram like the one in §12.6. It will
#                           / simplify matters if you start by defining a Box class that is a rectangle with
#                           / a text label.
# CH13P484EXERC7_FLTK       / Make an RGB color chart (e.g., search the web for “RGB color chart”).
# CH13P484EXERC8_FLTK       / Define a class Regular_hexagon (a regular hexagon is a six-sided polygon
#                           / with all sides of equal length). Use the center and the distance from the
#                           / center to a corner point as constructor arguments.
# CH13P484EXERC9_FLTK       / Tile a part of a window with Regular_hexagons (use at least eight hexagons).
# CH13P485EXERC10_FLTK      / Define a class Regular_polygon. Use the center, the number of sides (>2),
#                           / and the distance from the center to a corner as constructor arguments.
# CH13P485EXERC11_FLTK      / Draw a 300-by-200-pixel ellipse. Draw a 400-pixel-long x axis and a
#                           / 300-pixel-long y axis through the center of the ellipse. Mark the foci.
#                           / Mark a point on the ellipse that is not on one of the axes. Draw the two
#                           / lines from the foci to the point.
# CH13P485EXERC12_FLTK      / Draw a circle. Move a mark around on the circle (let it move a bit each
#                           / time you hit the “Next” button).
# CH13P485EXERC13_FLTK      / Draw the color matrix from §13.10, but without lines around each color
# CH13P485EXERC14_FLTK      / Define a right triangle class. Make an octagonal shape out of eight right
#                           / triangles of different colors.
# CH13P485EXERC15_FLTK      / “Tile” a window with small right triangles.
# CH13P485EXERC16_FLTK      / Do the previous exercise, but with hexagons.
# CH13P485EXERC17_FLTK      / Do the previous exercise, but using hexagons of a few different colors.
# CH13P485EXERC18_FLTK      / Define a class Poly that represents a polygon but checks that its points
#                           / really do make a polygon in its constructor. Hint: You’ll have to supply
#                           / the points to the constructor.
# CH13P485EXERC19_FLTK      / Define a class Star. One parameter should be the number of points. Draw
#                           / a few stars with differing numbers of points, differing line colors,
#                           / and differing fill colors.
#-------------------------------------- Chapter_14
#-------------------------------------- Graphics Class Design
# CH14P516EXERC1_FLTK       / Define two classes Smiley and Frowny, which are both derived from class
#                           / Circle and have two eyes and a mouth. Next, derive classes from Smiley
#                           / and Frowny which add an appropriate hat to each
# CH14P516EXERC2_FLTK       / Try to copy a Shape. What happens?
# CH14P516EXERC3_FLTK       / Define an abstract class and try to define an object of that type. What
#                           / happens?
# CH14P516EXERC4_FLTK       / Define a class Immobile_Circle, which is just like Circle but can’t be moved.
# CH14P516EXERC5_FLTK       / Define a Striped_rectangle where instead of fill, the rectangle is “filled”
#                           / by drawing one-pixel-wide horizontal lines across the inside of the rectangle
#                           / (say, draw every second line like that). You may have to play with the
#                           / width of lines and the line spacing to get a pattern you like.
# CH14P516EXERC6_FLTK       / Define a Striped_circle using the technique from Striped_rectangle
# CH14P516EXERC7_FLTK       / Define a Striped_closed_polyline using the technique from Striped_
#                           / rectangle (this requires some algorithmic inventiveness).
# CH14P516EXERC8_FLTK       / Define a class Octagon to be a regular octagon. Write a test that exercises
#                           / all of its functions (as defined by you or inherited from Shape).
# CH14P516EXERC9_FLTK       / Define a Group to be a container of Shapes with suitable operations
#                           / applied to the various members of the Group. Hint: Vector_ref. Use a
#                           / Group to define a checkers (draughts) board where pieces can be moved
#                           / under program control.
# CH14P517EXERC10_FLTK      / Define a class Pseudo_window that looks as much like a Window as you
#                           / can make it without heroic efforts. It should have rounded corners,
#                           / a label, and control icons. Maybe you could add some fake “contents,” such
#                           / as an image. It need not actually do anything. It is acceptable (and indeed
#                           / recommended) to have it appear within a Simple_window.
# CH14P517EXERC11_FLTK      / Define a Binary_tree class derived from Shape. Give the number of levels
#                           / as a parameter (levels==0 means no nodes, levels==1 means one node,
#                           / levels==2 means one top node with two sub-nodes, levels==3 means one
#                           / top node with two sub-nodes each with two sub-nodes, etc.). Let a node
#                           / be represented by a small circle. Connect the nodes by lines (as is
#                           / conventional). P.S. In computer science, trees grow downward from a top node
#                           / (amusingly, but logically, often called the root).
# CH14P517EXERC12_FLTK      / Modify Binary_tree to draw its nodes using a virtual function. Then,
#                           / derive a new class from Binary_tree that overrides that virtual function to
#                           / use a different representation for a node (e.g., a triangle).
# CH14P517EXERC13_FLTK      / Modify Binary_tree to take a parameter (or parameters) to indicate what
#                           / kind of line to use to connect the nodes (e.g., an arrow pointing down
#                           / or a red arrow pointing up). Note how this exercise and the last use two
#                           / alternative ways of making a class hierarchy more flexible and useful.
# CH14P517EXERC14_FLTK      / Add an operation to Binary_tree that adds text to a node. You may have
#                           / to modify the design of Binary_tree to implement this elegantly. Choose
#                           / a way to identify a node; for example, you might give a string "lrrlr" for
#                           / navigating left, right, right, left, and right down a binary tree (the root
#                           / node would match both an initial l and an initial r).
# CH14P517EXERC15_FLTK      / Define a class Iterator with a pure virtual function next() that returns
#                           / a double* (see Chapter 17). Now derive Vector_iterator and List_iterator
#                           / from Iterator so that next() for a Vector_iterator yields a pointer to
#                           / the next element of a vector<double> and List_iterator does the same
#                           / for a list<double>. You initialize a Vector_iterator with a vector<double>
#                           / and the first call of next() yields a pointer to its first element, if any.
#                           / If there is no next element, return 0. Test this by using a function void
#                           / print(Iterator&) to print the elements of a vector<double> and a list<double>.
# CH14P517EXERC16_FLTK      / Define a class Controller with four virtual functions on(), off(), set_level(int),
#                           / and show(). Derive at least two classes from Controller. One should be a
#                           / simple test class where show() prints out whether the class is set to on or
#                           / off and what is the current level. The second derived class should somehow
#                           / control the line color of a Shape; the exact meaning of “level” is up
#                           / to you. Try to find a third “thing” to control with such a Controller class.
# CH14P518EXERC17_FLTK      / The exceptions defined in the C++ standard library, such as exception,
#                           / runtime_error, and out_of_range (§5.6.3), are organized into a class
#                           / hierarchy (with a useful virtual function what() returning a string supposedly
#                           / explaining what went wrong). Search your information sources for the
#                           / C++ standard exception class hierarchy and draw a class hierarchy diagram of it.
#-------------------------------------- Chapter_15
#-------------------------------------- Graphing Functions and Data
# CH15P546DRILL1_5_FLTK     / Function graphing drill:
#                           / 1. Make an empty 600-by-600 Window labeled “Function graphs.”
#                           / 2. Note that you’ll need to make a project with the properties specified in the
#                           / “installation of FLTK” note from the course website.
#                           / 3. You’ll need to move Graph.cpp and Window.cpp into your project.
#                           / 4. Add an x axis and a y axis each of length 400, labeled “1 = = 20 pixels”
#                           / and with a notch every 20 pixels. The axes should cross at (300,300).
#                           / 5. Make both axes red.
#

# if the example does not exist that new directory will be created for it by layout
set(name_Example "CH15P546DRILL1_5_FLTK")

#[[------------------------------------
                    Example's hierarchy
]]#------------------------------------
# processing the example name, if it does not exist, hierarchy will be made for it 

option(SHOWE_STATUS_MESSAGE "" TRUE)
option(SHOWE_INFO_MESSAGE "" TRUE)

# set layout file names
set(layout_file_names
  "layout_h"
  "layout_cpp"
)

# search task description of the name_Example in CMakeLists.txt
file(READ "${PROJECT_SOURCE_DIR}/CMakeLists.txt" task_Description)
string(REGEX MATCH "# ${name_Example}(\t|[ ])+[^#]+(#(\t|[ ])+[/]([^#]|#[A-Za-z])+)*" task_Description "${task_Description}")
# delete unnecessary characters of the CMakeList.txt file formatting from the task description
if(task_Description)
  string(REGEX REPLACE "(# ${name_Example}(\t|[ ])+/[ ]?|\n$)" "" task_Description ${task_Description})
  string(REGEX REPLACE "#(\t|[ ])+/[ ]?" "* " task_Description ${task_Description})
  string(APPEND task_Description "\n*")
endif()

if(SHOWE_STATUS_MESSAGE)
  message(STATUS "task_Description:\n${task_Description}")
endif()

set(is_FLTK)
if(name_Example MATCHES "_FLTK")
  set(is_FLTK TRUE)
  message(STATUS "FLTK ON")
endif()

# set substitutions list
set(current_date)
string(TIMESTAMP current_date "%m/%d/%Y %H:%M:%S")
set(include_General
  "std_lib_facilities.h"
)
set(include_Extra)
if(is_FLTK)
  list(APPEND include_Extra
    "Simple_window.h"
    "Graph.h"
  )
endif()
set(substitutions_list
  "name_File"   "${name_Example}"
  "project_Source_Dir_Include" "{PROJECT_SOURCE_DIR}/include"
  "date_Generate" "${current_date}"
  "author" "Andrei-KS"
  "task_Description" "${task_Description}"
)

if(include_General)
  set(str_Include_General)
  foreach(item IN LISTS include_General)
    string(APPEND str_Include_General "#include \"${item}\"\n")
  endforeach()
  string(REGEX REPLACE "\n$" "" str_Include_General "${str_Include_General}")

  list(APPEND substitutions_list
    "include_General" "${str_Include_General}"
  )
endif()

if(include_Extra)
  set(str_Include_Extra)
  foreach(item IN LISTS include_Extra)
    string(APPEND str_Include_Extra "#include \"${item}\"\n")
  endforeach()
  string(REGEX REPLACE "\n$" "" str_Include_Extra "${str_Include_Extra}")

  list(APPEND substitutions_list
    "include_Extra" "${str_Include_Extra}"
  )
endif()


set(parent_dir "Chapter_")
if(name_Example MATCHES "^CH([0-9]+)P")
  set(parent_dir "${parent_dir}${CMAKE_MATCH_1}")
else()
  set(parent_dir "${parent_dir}EmptyNumber")
endif()

set(dir_Example "${PROJECT_SOURCE_DIR}/${parent_dir}/Example/${name_Example}")
if(NOT EXISTS "${dir_Example}")

  make_directory(${dir_Example})
  if(SHOWE_STATUS_MESSAGE)
    message(STATUS "Directory is not found: ${dir_Example}\n\t\tThis directory will be created by generator from layouts")
  endif()

  set(src_dir_Example "${dir_Example}/src")
  set(include_dir_Example "${dir_Example}/include")
  make_directory(${src_dir_Example})
  make_directory(${include_dir_Example})
   
  # get the number of items on the list
  list(LENGTH substitutions_list length_substitutions_list)
  # get the max valid index of the list
  math(EXPR upper_number_substitutions_list "${length_substitutions_list} - 1" OUTPUT_FORMAT DECIMAL)

  foreach(index RANGE 0 ${upper_number_substitutions_list} 2)
    list(GET substitutions_list ${index} list_item)
    list(REMOVE_AT substitutions_list ${index})
    list(INSERT substitutions_list ${index} "[$][{]${list_item}[}]")
  endforeach()


  if(SHOWE_INFO_MESSAGE)
    message("length_substitutions_list:\t${length_substitutions_list}")
    message("upper_number_substitutions_list:\t${upper_number_substitutions_list}")
    foreach(index RANGE 0 ${upper_number_substitutions_list} 2)
      list(GET substitutions_list ${index} search_item)
      math(EXPR index_replace_item "${index} + 1" OUTPUT_FORMAT DECIMAL)
      list(GET substitutions_list ${index_replace_item} replace_item)
      message(${search_item}"\t<-\t"${replace_item})
    endforeach()
  endif()

  foreach(layout_file_name IN LISTS layout_file_names)

    # get content from the current layout file
    file(READ "${PROJECT_SOURCE_DIR}/include/${layout_file_name}" content_layout_file)
      
    if(SHOWE_INFO_MESSAGE)
      message("layout_file_name:\t${layout_file_name}")
      message("content_layout_file:\n${content_layout_file}")
    endif()
 
    foreach(index RANGE 0 ${upper_number_substitutions_list} 2)
      list(GET substitutions_list ${index} search_item)
      math(EXPR index_replace_item "${index} + 1" OUTPUT_FORMAT DECIMAL)
      list(GET substitutions_list ${index_replace_item} replace_item)

      string(REGEX REPLACE
        "${search_item}"
        "${replace_item}"
        content_layout_file
        "${content_layout_file}"
      )
    endforeach()
    
    string(REGEX REPLACE
      "[$]{[^}]+}[\n]?"
      ""
      content_layout_file
      "${content_layout_file}"
    )

    if(SHOWE_INFO_MESSAGE)   
      message("content_layout_file: ${content_layout_file}")
    endif()

    if(${layout_file_name} MATCHES "[_]h$")
      file(WRITE "${include_dir_Example}/${name_Example}RunExmple.h" "${content_layout_file}")
    elseif(${layout_file_name} MATCHES "[_]cpp$")
      file(WRITE "${src_dir_Example}/${name_Example}RunExmple.cpp" "${content_layout_file}")
    endif()

  endforeach()
endif()

# builder of Example lib
# set default setting
set(name_Lib "${name_Example}")
set(includes_Directories)
set(src_Directories)
set(src_Ignore_Names)
set(src_Extra_Files)
set(lib_Directories)
set(lib_Ignore_Names)
set(lib_Extra_Files)

set(prefixDirectory "${parent_dir}/Example/${name_Example}")
List(APPEND includes_Directories 
  "${PROJECT_SOURCE_DIR}/include"
  "${prefixDirectory}/include"
  "${PROJECT_SOURCE_DIR}/lib/Chrono/include"
  "${PROJECT_SOURCE_DIR}/lib/Utility/include"
)
List(APPEND src_Directories 
  "${prefixDirectory}/src"
  "${PROJECT_SOURCE_DIR}/lib/Chrono/src"
  "${PROJECT_SOURCE_DIR}/lib/Utility/src"
)

if(is_FLTK)
  #for VS2022 Community
  List(APPEND includes_Directories
    "${PROJECT_SOURCE_DIR}/lib/_fltk-1.3.8/x64/include"
    "${PROJECT_SOURCE_DIR}/lib/GUI/include"
    "${PROJECT_SOURCE_DIR}/lib/ExtantionGUI/include"
  )
  List(APPEND src_Directories 
    "${PROJECT_SOURCE_DIR}/lib/GUI/src"
    "${PROJECT_SOURCE_DIR}/lib/ExtantionGUI/src"
  )
  List(APPEND lib_Directories
    "${PROJECT_SOURCE_DIR}/lib/_fltk-1.3.8/x64/lib"
  )

  # Local Paths to additional libs of current lib
  set(paths_To_Lib)
  # Get all paths of files for source of packege
  create_paths_list_to(
    paths_To_Lib
    DIRECTORIES   ${lib_Directories}
    EXTENSION     "lib"
  )
  if(paths_To_Lib)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${paths_To_Lib})
  endif()

  if(EXISTS "${PROJECT_SOURCE_DIR}/lib/_fltk-1.3.8/x64/bin/fluid.exe")
    message("file fluid.exe exists")
    file(COPY "${PROJECT_SOURCE_DIR}/lib/_fltk-1.3.8/x64/bin/fluid.exe" DESTINATION ${PROJECT_BINARY_DIR})
  endif()
  if(EXISTS "${PROJECT_SOURCE_DIR}/lib/_fltk-1.3.8/x64/bin/fluidd.exe")
    message("file fluidd.exe exists")
    file(COPY "${PROJECT_SOURCE_DIR}/lib/_fltk-1.3.8/x64/bin/fluidd.exe" DESTINATION ${PROJECT_BINARY_DIR})
  endif()
endif()

creat_lib_from_files(
  SHOWE_INFO_MESSAGE
  NAME_LIB ${name_Lib}
  NAME_TARGET ${PROJECT_NAME}
  INCLUDES_DIRECTORIES ${includes_Directories}
  SRC_DIRECTORIES ${src_Directories}
  SRC_IGNORE_NAMES ${src_Ignored_Names}
  SRC_EXTRA_FILES ${src_Extra_Files}
  LIB_DIRECTORIES ${lib_Directories}
  LIB_IGNORE_NAMES ${lib_Ignore_Names}
  EXTRA_LIBS ${lib_Extra_Files}
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE "${PROJECT_BINARY_DIR}/${name_Example}.lib"
)

#if a data folder exists its contents will be copied to ${PROJECT_BINARY_DIR}
set(data_dir_Example "${dir_Example}/data")
if(EXISTS "${data_dir_Example}" AND IS_DIRECTORY "${data_dir_Example}")
  message(STATUS "data_dir_Example : ${data_dir_Example}")
  # Local Paths to data
  set(paths_To_Data)
  # Get all paths of files for source of packege
  create_paths_list_to(
    paths_To_Data
    DIRECTORIES   ${data_dir_Example}
    EXTENSION     "*"
  )
  file(COPY ${paths_To_Data} DESTINATION ${PROJECT_BINARY_DIR})
endif()