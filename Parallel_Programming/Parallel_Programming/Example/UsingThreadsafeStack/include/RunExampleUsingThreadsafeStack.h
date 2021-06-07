#ifndef __RUNEXAMPLEUSINGTHREADSAFESTACK_H__
#define __RUNEXAMPLEUSINGTHREADSAFESTACK_H__

#include "RunCommandOfExample.h"

/**
* Implementation for running examples RunExampleUsingThreadsafeStack
* @see stack, mutex
*/
class RunExampleUsingThreadsafeStack : public RunCommandOfExample
{
public:
	/**
	* Example run command
	*/
	virtual void excute() override;

protected:
	/**
	*/
	void callPopForEmptyStack();

	/**
	*/
	void workOfMultipleThreads(size_t numberThread);
};

#endif // !__RUNEXAMPLEUSINGTHREADSAFESTACK_H__