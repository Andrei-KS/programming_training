#ifndef __RUNEXAMPLEUSINGTHREADGUARD_H__
#define __RUNEXAMPLEUSINGTHREADGUARD_H__

#include "RunCommandOfExample.h"

/**
*/
class RunExampleUsingThreadGuard : public RunCommandOfExample
{
public:
	/**
	* Example run command
	*/
	virtual void excute() override;
};

#endif // !__RUNEXAMPLEUSINGTHREADGUARD_H__