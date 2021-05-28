#ifndef __RUNCOMMANDOFEXAMPLE_H__
#define __RUNCOMMANDOFEXAMPLE_H__

/**
* Interface for running examples 
*/
class RunCommandOfExample
{
public:
	/**
	* Example run command 
	*/
	virtual void excute() = 0;
	
	/** An example pointer to be associated with this example run command  */
	static RunCommandOfExample* runCommandOfExample;
	
	/** Number of input arguments */
	int itsArgC = 0;

	/** The value of the input arguments */
	char** itsArgV = nullptr;
};
#endif // !__RUNCOMMANDOFEXAMPLE_H__