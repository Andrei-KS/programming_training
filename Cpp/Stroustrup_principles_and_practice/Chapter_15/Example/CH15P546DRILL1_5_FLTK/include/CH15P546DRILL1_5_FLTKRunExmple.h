/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/19/2022 18:43:03
	author                                          : Andrei-KS
*/
#ifndef __CH15P546DRILL1_5_FLTK__
#define __CH15P546DRILL1_5_FLTK__

#include "RunCommandOfExample.h"

/*
* Function graphing drill:
* 1. Make an empty 600-by-600 Window labeled “Function graphs.”
* 2. Note that you’ll need to make a project with the properties specified in the
* “installation of FLTK” note from the course website.
* 3. You’ll need to move Graph.cpp and Window.cpp into your project.
* 4. Add an x axis and a y axis each of length 400, labeled “1 = = 20 pixels”
* and with a notch every 20 pixels. The axes should cross at (300,300).
* 5. Make both axes red.
*
* @author Andrei-KS
*/
class CH15P546DRILL1_5_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH15P546DRILL1_5_FLTK__