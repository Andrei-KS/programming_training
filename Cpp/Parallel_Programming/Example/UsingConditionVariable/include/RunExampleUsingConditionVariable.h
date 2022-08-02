#ifndef __RUNEXAMPLEUSINGCONDITIONVARIABLE_H__
#define __RUNEXAMPLEUSINGCONDITIONVARIABLE_H__

#include "RunCommandOfExample.h"

/**
* Implementation for running examples UsingConditionVariable
*/
class RunExampleUsingConditionVariable:public RunCommandOfExample
{
public:
	/**
	* Example run command
	*/
	virtual void excute() override;
};

#endif // !__RUNEXAMPLEUSINGCONDITIONVARIABLE_H__