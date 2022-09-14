/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/14/2022 12:43:04
	author                                          : Andrei-KS
*/
#ifndef __CH14P517EXERC10_FLTK__
#define __CH14P517EXERC10_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a class Pseudo_window that looks as much like a Window as you
* can make it without heroic efforts. It should have rounded corners,
* a label, and control icons. Maybe you could add some fake “contents,” such
* as an image. It need not actually do anything. It is acceptable (and indeed
* recommended) to have it appear within a Simple_window.
*
* @author Andrei-KS
*/
class CH14P517EXERC10_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P517EXERC10_FLTK__