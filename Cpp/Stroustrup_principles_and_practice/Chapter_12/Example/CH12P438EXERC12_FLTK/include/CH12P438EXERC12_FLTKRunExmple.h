/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/15/2022 18:42:07
	author                                          : Andrei-KS
*/
#ifndef __CH12P438EXERC12_FLTK__
#define __CH12P438EXERC12_FLTK__

#include "RunCommandOfExample.h"

/*
* A superellipse is a two-dimensional shape defined by the equation
*     m     n
*  |x|   |y|
*  |-| + |-| = 1  m,n > 0.  
*  |a|   |b|
* Look up superellipse on the web to get a better idea of what such shapes
* look like. Write a program that draws “starlike” patterns by connecting
* points on a superellipse. Take a, b, m, n, and N as arguments. Select N
* points on the superellipse defined by a, b, m, and n. Make the points
* equally spaced for some definition of “equal.” Connect each of those N
* points to one or more other points (if you like you can make the number
* of points to which to connect a point another argument or just use N–1,
* i.e., all the other points).
*
* @author Andrei-KS
*/
class CH12P438EXERC12_FLTKRunExmple : public RunCommandOfExample
{
public:
  /*
  * The main function launch to run a example.
	* This function can use command line parameters
	* via self variables itsArgC, itsArgV
	*
	* @see RunCommandOfExample
	*/
  virtual int excute() override;
};

#endif // !__CH12P438EXERC12_FLTK__