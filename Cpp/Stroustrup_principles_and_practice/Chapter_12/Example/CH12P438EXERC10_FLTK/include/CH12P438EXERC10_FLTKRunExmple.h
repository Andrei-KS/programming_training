/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/11/2022 16:04:03
	author                                          : Andrei-KS
*/
#ifndef __CH12P438EXERC10_FLTK__
#define __CH12P438EXERC10_FLTK__

#include "RunCommandOfExample.h"

/*
* Draw the file diagram from §12.8.
*
* @author Andrei-KS
*/
class CH12P438EXERC10_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH12P438EXERC10_FLTK__