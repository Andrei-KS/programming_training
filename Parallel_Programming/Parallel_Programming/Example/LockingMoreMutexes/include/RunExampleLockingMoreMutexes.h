#ifndef __RUNEXAMPLELOCKINGMOREMUTEXES_H__
#define __RUNEXAMPLELOCKINGMOREMUTEXES_H__

#include "RunCommandOfExample.h"

/**
* Implementation for running examples RunExampleLockingMoreMutexes
* @see std::lock, std::lock_guard
*/
class RunExampleLockingMoreMutexes : public RunCommandOfExample
{
public:
	/**
	* Example run command
	*/
	virtual void excute();
};

#endif // !__RUNEXAMPLELOCKINGMOREMUTEXES_H__