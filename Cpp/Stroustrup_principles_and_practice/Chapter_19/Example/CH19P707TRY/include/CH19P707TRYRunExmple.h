/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 05/02/2023 11:08:46
	author                                          : Andrei-KS
*/
#ifndef __CH19P707TRY__
#define __CH19P707TRY__

#include "RunCommandOfExample.h"

/*
* Modify reserve to use unique_ptr. Remember to release before returning.
* Compare that solution to the vector_base one. Consider which is easier to
* write and which is easier to get correct.
*
* @author Andrei-KS
*/
class CH19P707TRYRunExmple : public RunCommandOfExample
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

#endif // !__CH19P707TRY__