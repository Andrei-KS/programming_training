#ifndef __RUNEXAMPLEWAITINGCONDITIONVARIABLEWITHTIMEOUT_H__
#define __RUNEXAMPLEWAITINGCONDITIONVARIABLEWITHTIMEOUT_H__

#include "RunCommandOfExample.h"

/**
* Implementation for running examples: Waiting for a conditional variable with a timeout 
* @see 
*/
class RunExampleWaitingConditionVariableWithTimeout : public RunCommandOfExample
{
public:
	/**
	 * Example run command
	 */
	virtual void excute() override;
};

#endif // !__RUNEXAMPLEWAITINGCONDITIONVARIABLEWITHTIMEOUT_H__