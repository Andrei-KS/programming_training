/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/19/2022 19:17:25
	author                                          : Andrei-KS
*/
#ifndef __CH15P546DRILL1_9_FLTK__
#define __CH15P546DRILL1_9_FLTK__

#include "RunCommandOfExample.h"

/*
* In the following, use a separate Shape for each function to be graphed:
* 1. Graph the function double one(double x) { return 1 } in the range [–10,11]
* with (0,0) at (300,300) using 400 points and no scaling (in the window).
* 2. Change it to use x scale 20 and y scale 20.
* 3. From now on use that range, scale, etc. for all graphs.
* 4. Add double slope(double x) { return x/2 } to the window.
* 5. Label the slope with a Text "x/2" at a point just above its bottom left end
* point.
* 6. Add double square(double x) { return x*x } to the window.
* 7. Add a cosine to the window (don’t write a new function).
* 8. Make the cosine blue.
*  9. Write a function sloping_cos() that adds a cosine to slope() (as defined
* above) and add it to the window.
*
* @author Andrei-KS
*/
class CH15P546DRILL1_9_FLTKRunExmple : public RunCommandOfExample
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

#endif // !__CH15P546DRILL1_9_FLTK__