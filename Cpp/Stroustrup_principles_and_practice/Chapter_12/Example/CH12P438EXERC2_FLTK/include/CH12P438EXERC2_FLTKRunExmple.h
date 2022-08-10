/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/10/2022 14:22:31
	author                                          : Andrei-KS
*/
#ifndef __CH12P438EXERC2_FLTK__
#define __CH12P438EXERC2_FLTK__

#include "RunCommandOfExample.h"

/*
* Draw a 100-by-30 Rectangle and place the text “Howdy!” inside it.
*
* @author Andrei-KS
*/
class CH12P438EXERC2_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH12P438EXERC2_FLTK__