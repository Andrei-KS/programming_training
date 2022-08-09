/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/09/2022 16:00:17
	author                                          : Andrei-KS
*/
#ifndef __CH12P415DRILL2_FLTK__
#define __CH12P415DRILL2_FLTK__

#include "RunCommandOfExample.h"

/*
* Now add the examples from §12.7 one by one, testing between each
* added subsection example.
*
* @author Andrei-KS
*/
class CH12P415DRILL2_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH12P415DRILL2_FLTK__