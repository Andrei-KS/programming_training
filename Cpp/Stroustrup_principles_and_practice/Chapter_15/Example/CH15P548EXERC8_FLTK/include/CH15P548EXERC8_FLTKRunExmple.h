/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/01/2022 20:07:11
	author                                          : Andrei-KS
*/
#ifndef __CH15P548EXERC8_FLTK__
#define __CH15P548EXERC8_FLTK__

#include "RunCommandOfExample.h"

/*
* Here is a collection of heights in centimeters together with the number
* of people in a group of that height (rounded to the nearest 5cm): (170,7),
* (175,9), (180,23), (185,17), (190,6), (195,1). How would you graph that
* data? If you can’t think of anything better, do a bar graph. Remember to
* provide axes and labels. Place the data in a file and read it from that file.
*
* @author Andrei-KS
*/
class CH15P548EXERC8_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH15P548EXERC8_FLTK__