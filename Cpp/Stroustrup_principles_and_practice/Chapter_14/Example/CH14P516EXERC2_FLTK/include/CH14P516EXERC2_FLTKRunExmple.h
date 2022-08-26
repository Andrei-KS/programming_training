/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/26/2022 12:18:58
	author                                          : Andrei-KS
*/
#ifndef __CH14P516EXERC2_FLTK__
#define __CH14P516EXERC2_FLTK__

#include "RunCommandOfExample.h"

/*
* Try to copy a Shape. What happens?
*
* @author Andrei-KS
*/
class CH14P516EXERC2_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P516EXERC2_FLTK__