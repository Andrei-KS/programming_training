/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/25/2022 14:47:47
	author                                          : Andrei-KS
*/
#ifndef __CH14P516EXERC1_FLTK__
#define __CH14P516EXERC1_FLTK__

#include "RunCommandOfExample.h"

/*
* Define two classes Smiley and Frowny, which are both derived from class
* Circle and have two eyes and a mouth. Next, derive classes from Smiley
* and Frowny which add an appropriate hat to each
*
* @author Andrei-KS
*/
class CH14P516EXERC1_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH14P516EXERC1_FLTK__