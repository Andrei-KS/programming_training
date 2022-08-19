/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/19/2022 13:15:22
	author                                          : Andrei-KS
*/
#ifndef __CH13P484EXERC4_FLTK__
#define __CH13P484EXERC4_FLTK__

#include "RunCommandOfExample.h"

/*
* Define functions n(), s(), e(), w(), center(), ne(), se(), sw(), and nw(). Each
* takes a Rectangle argument and returns a Point. These functions define
* “connection points” on and in the rectangle. For example, nw(r) is the
* northwest (top left) corner of a Rectangle called r.
*
* @author Andrei-KS
*/
class CH13P484EXERC4_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P484EXERC4_FLTK__