/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/08/2023 13:02:38
	author                                          : Andrei-KS
*/
#ifndef __CH21P774TRY__
#define __CH21P774TRY__

#include "RunCommandOfExample.h"

/*
* Define a vector<Record>, initialize it with four records of your choice, and
* compute their total price using the functions above.
*
* @author Andrei-KS
*/
class CH21P774TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH21P774TRY__