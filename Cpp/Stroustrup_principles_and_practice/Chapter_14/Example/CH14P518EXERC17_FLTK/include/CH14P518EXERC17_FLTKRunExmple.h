/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/19/2022 12:27:45
	author                                          : Andrei-KS
*/
#ifndef __CH14P518EXERC17_FLTK__
#define __CH14P518EXERC17_FLTK__

#include "RunCommandOfExample.h"

/*
* The exceptions defined in the C++ standard library, such as exception,
* runtime_error, and out_of_range (§5.6.3), are organized into a class
* hierarchy (with a useful virtual function what() returning a string supposedly
* explaining what went wrong). Search your information sources for the
* C++ standard exception class hierarchy and draw a class hierarchy diagram of it.
*
* @author Andrei-KS
*/
class CH14P518EXERC17_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P518EXERC17_FLTK__