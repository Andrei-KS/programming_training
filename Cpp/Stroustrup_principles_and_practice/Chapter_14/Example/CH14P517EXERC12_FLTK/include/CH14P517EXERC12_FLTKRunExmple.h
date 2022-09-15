/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/15/2022 16:48:59
	author                                          : Andrei-KS
*/
#ifndef __CH14P517EXERC12_FLTK__
#define __CH14P517EXERC12_FLTK__

#include "RunCommandOfExample.h"

/*
* Modify Binary_tree to draw its nodes using a virtual function. Then,
* derive a new class from Binary_tree that overrides that virtual function to
* use a different representation for a node (e.g., a triangle).
*
* @author Andrei-KS
*/
class CH14P517EXERC12_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P517EXERC12_FLTK__