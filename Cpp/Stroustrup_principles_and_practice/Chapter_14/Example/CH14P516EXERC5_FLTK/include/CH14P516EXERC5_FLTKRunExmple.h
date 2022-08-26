/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/26/2022 13:36:03
	author                                          : Andrei-KS
*/
#ifndef __CH14P516EXERC5_FLTK__
#define __CH14P516EXERC5_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a Striped_rectangle where instead of fill, the rectangle is “filled”
* by drawing one-pixel-wide horizontal lines across the inside of the rectangle
* (say, draw every second line like that). You may have to play with the
* width of lines and the line spacing to get a pattern you like.
*
* @author Andrei-KS
*/
class CH14P516EXERC5_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P516EXERC5_FLTK__