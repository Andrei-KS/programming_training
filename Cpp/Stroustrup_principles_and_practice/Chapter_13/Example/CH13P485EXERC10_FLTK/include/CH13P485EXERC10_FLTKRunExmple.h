/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/23/2022 16:17:03
	author                                          : Andrei-KS
*/
#ifndef __CH13P485EXERC10_FLTK__
#define __CH13P485EXERC10_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a class Regular_polygon. Use the center, the number of sides (>2),
* and the distance from the center to a corner as constructor arguments.
*
* @author Andrei-KS
*/
class CH13P485EXERC10_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P485EXERC10_FLTK__