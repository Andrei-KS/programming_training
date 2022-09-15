/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/14/2022 16:45:36
	author                                          : Andrei-KS
*/
#ifndef __CH14P517EXERC11_FLTK__
#define __CH14P517EXERC11_FLTK__

#include "RunCommandOfExample.h"

/*
* Define a Binary_tree class derived from Shape. Give the number of levels
* as a parameter (levels==0 means no nodes, levels==1 means one node,
* levels==2 means one top node with two sub-nodes, levels==3 means one
* top node with two sub-nodes each with two sub-nodes, etc.). Let a node
* be represented by a small circle. Connect the nodes by lines (as is
* conventional). P.S. In computer science, trees grow downward from a top node
* (amusingly, but logically, often called the root).
*
* @author Andrei-KS
*/
class CH14P517EXERC11_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P517EXERC11_FLTK__