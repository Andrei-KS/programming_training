#ifndef __RUNEXAMPLEUSINGSCOPEDTHREAD_H__
#define __RUNEXAMPLEUSINGSCOPEDTHREAD_H__

#include "RunCommandOfExample.h"

/**
* Implementation for running examples UsingScopedThread
* @see ScopedThread
*/
class RunExampleUsingScopedThread : public RunCommandOfExample
{
	/**
	* Example run command
	*/
	virtual void excute();
};

#endif // !__RUNEXAMPLEUSINGSCOPEDTHREAD_H__