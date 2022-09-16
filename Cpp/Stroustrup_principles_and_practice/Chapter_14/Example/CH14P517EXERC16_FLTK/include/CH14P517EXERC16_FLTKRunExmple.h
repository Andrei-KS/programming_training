/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/16/2022 17:34:49
	author                                          : Andrei-KS
*/
#ifndef __CH14P517EXERC16_FLTK__
#define __CH14P517EXERC16_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a class Controller with four virtual functions on(), off(), set_level(int),
* and show(). Derive at least two classes from Controller. One should be a
* simple test class where show() prints out whether the class is set to on or
* off and what is the current level. The second derived class should somehow
* control the line color of a Shape the exact meaning of “level” is up
* to you. Try to find a third “thing” to control with such a Controller class.
*
* @author Andrei-KS
*/
class CH14P517EXERC16_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P517EXERC16_FLTK__