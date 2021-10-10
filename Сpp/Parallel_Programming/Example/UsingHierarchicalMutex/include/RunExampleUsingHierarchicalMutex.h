#ifndef __RUNEXAMPLEUSINGHIERARCHICALMUTEX_H__
#define __RUNEXAMPLEUSINGHIERARCHICALMUTEX_H__

#include "RunCommandOfExample.h"

/**
* Implementation for running examples RunExampleUsingHierarchicalMutex
*/
class RunExampleUsingHierarchicalMutex : public RunCommandOfExample
{
public:
	/**
	* Example run command
	*/
	virtual void excute() override;
};

#endif // !__RUNEXAMPLEUSINGHIERARCHICALMUTEX_H__