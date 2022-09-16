/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/16/2022 13:13:56
	author                                          : Andrei-KS
*/
#ifndef __CH14P517EXERC14_FLTK__
#define __CH14P517EXERC14_FLTK__

#include "RunCommandOfExample.h"

/*
* Add an operation to Binary_tree that adds text to a node. You may have
* to modify the design of Binary_tree to implement this elegantly. Choose
* a way to identify a node for example, you might give a string "lrrlr" for
* navigating left, right, right, left, and right down a binary tree (the root
* node would match both an initial l and an initial r).
*
* @author Andrei-KS
*/
class CH14P517EXERC14_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P517EXERC14_FLTK__