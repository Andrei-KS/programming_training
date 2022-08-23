/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/23/2022 17:09:14
	author                                          : Andrei-KS
*/
#ifndef __CH13P485EXERC12_FLTK__
#define __CH13P485EXERC12_FLTK__

#include "RunCommandOfExample.h"

/*
* Draw a circle. Move a mark around on the circle (let it move a bit each
* time you hit the “Next” button).
*
* @author Andrei-KS
*/
class CH13P485EXERC12_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P485EXERC12_FLTK__