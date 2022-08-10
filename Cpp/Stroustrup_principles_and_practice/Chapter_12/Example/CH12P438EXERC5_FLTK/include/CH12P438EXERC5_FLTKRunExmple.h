/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/10/2022 17:02:25
	author                                          : Andrei-KS
*/
#ifndef __CH12P438EXERC5_FLTK__
#define __CH12P438EXERC5_FLTK__

#include "RunCommandOfExample.h"

/*
* Draw a red ¼-inch frame around a rectangle that is three-quarters the
* height of your screen and two-thirds the width. 
*
* @author Andrei-KS
*/
class CH12P438EXERC5_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH12P438EXERC5_FLTK__