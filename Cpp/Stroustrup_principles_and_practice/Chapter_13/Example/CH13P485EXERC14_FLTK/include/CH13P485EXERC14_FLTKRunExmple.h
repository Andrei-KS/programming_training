/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/23/2022 18:26:42
	author                                          : Andrei-KS
*/
#ifndef __CH13P485EXERC14_FLTK__
#define __CH13P485EXERC14_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a right triangle class. Make an octagonal shape out of eight right
* triangles of different colors.
*
* @author Andrei-KS
*/
class CH13P485EXERC14_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH13P485EXERC14_FLTK__