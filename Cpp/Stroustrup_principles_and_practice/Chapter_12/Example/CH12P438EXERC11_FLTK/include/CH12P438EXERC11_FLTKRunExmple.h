/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/12/2022 15:44:22
	author                                          : Andrei-KS
*/
#ifndef __CH12P438EXERC11_FLTK__
#define __CH12P438EXERC11_FLTK__

#include "RunCommandOfExample.h"

/*
* Draw a series of regular polygons, one inside the other. The innermost
* should be an equilateral triangle, enclosed by a square, enclosed by a
* pentagon, etc. For the mathematically adept only: let all the points of
* each N-polygon touch sides of the (N+1)-polygon. Hint: The trigonometric
* functions are found in <cmath> 
*
* @author Andrei-KS
*/
class CH12P438EXERC11_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH12P438EXERC11_FLTK__