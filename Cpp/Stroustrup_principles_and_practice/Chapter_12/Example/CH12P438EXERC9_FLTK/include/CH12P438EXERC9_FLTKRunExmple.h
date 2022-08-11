/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/11/2022 15:14:51
	author                                          : Andrei-KS
*/
#ifndef __CH12P438EXERC9_FLTK__
#define __CH12P438EXERC9_FLTK__

#include "RunCommandOfExample.h"

/*
* Display an image on the screen, e.g., a photo of a friend. Label the image
* both with a title on the window and with a caption in the window.
*
* @author Andrei-KS
*/
class CH12P438EXERC9_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH12P438EXERC9_FLTK__