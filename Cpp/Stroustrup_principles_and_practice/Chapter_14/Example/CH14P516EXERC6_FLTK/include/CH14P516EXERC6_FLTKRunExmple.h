/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/26/2022 15:09:48
	author                                          : Andrei-KS
*/
#ifndef __CH14P516EXERC6_FLTK__
#define __CH14P516EXERC6_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a Striped_circle using the technique from Striped_rectangle
*
* @author Andrei-KS
*/
class CH14P516EXERC6_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P516EXERC6_FLTK__