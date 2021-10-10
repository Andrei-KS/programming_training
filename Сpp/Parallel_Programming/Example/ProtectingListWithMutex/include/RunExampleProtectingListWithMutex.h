#ifndef __RUNEXAMPLEPROTECTINGLISTWITHMUTEX_H__
#define __RUNEXAMPLEPROTECTINGLISTWITHMUTEX_H__

#include "RunCommandOfExample.h"

/**
* Implementation for running examples RunExampleProtectingListWithMutex
* @see list, mutex
*/
class RunExampleProtectingListWithMutex : public RunCommandOfExample
{
public:
	/**
	* Example run command
	*/
	virtual void excute() override;
};

#endif // !__RUNEXAMPLEPROTECTINGLISTWITHMUTEX_H__