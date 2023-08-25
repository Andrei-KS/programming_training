/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/23/2023 16:17:10
	author                                          : Andrei-KS
*/
#ifndef __CH20P755EXERC9__
#define __CH20P755EXERC9__

#include "RunCommandOfExample.h"

/*
* Define a program that counts the number of words in a Document. Provide
* two versions: one that defines word as “a whitespace-separated sequence of
* characters” and one that defines word as “a sequence of consecutive alpha-
* betic characters.” For example, with the former definition, alpha.numeric
* and as12b are both single words, whereas with the second definition they
* are both two words.
*
* @author Andrei-KS
*/
class CH20P755EXERC9RunExmple : public RunCommandOfExample
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

#endif // !__CH20P755EXERC9__