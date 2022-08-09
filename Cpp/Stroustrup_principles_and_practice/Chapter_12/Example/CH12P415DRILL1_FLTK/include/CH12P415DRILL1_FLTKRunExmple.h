/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/09/2022 13:17:35
	author                                          : Andrei-KS
*/
#ifndef __CH12P415DRILL1_FLTK__
#define __CH12P415DRILL1_FLTK__

#include "RunCommandOfExample.h"

/*
* Get an empty Simple_window with the size 600 by 400 and a label My
* window compiled, linked, and run. 
*
* @author Andrei-KS
*/
class CH12P415DRILL1_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH12P415DRILL1_FLTK__