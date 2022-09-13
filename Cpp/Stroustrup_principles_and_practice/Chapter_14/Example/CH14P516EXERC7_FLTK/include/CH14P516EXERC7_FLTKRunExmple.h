/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/12/2022 12:11:26
	author                                          : Andrei-KS
*/
#ifndef __CH14P516EXERC7_FLTK__
#define __CH14P516EXERC7_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a Striped_closed_polyline using the technique from Striped_
* rectangle (this requires some algorithmic inventiveness).
*
* @author Andrei-KS
*/
class CH14P516EXERC7_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P516EXERC7_FLTK__