/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/13/2022 17:49:21
	author                                          : Andrei-KS
*/
#ifndef __CH14P516EXERC9_FLTK__
#define __CH14P516EXERC9_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a Group to be a container of Shapes with suitable operations
* applied to the various members of the Group. Hint: Vector_ref. Use a
* Group to define a checkers (draughts) board where pieces can be moved
* under program control.
*
* @author Andrei-KS
*/
class CH14P516EXERC9_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P516EXERC9_FLTK__