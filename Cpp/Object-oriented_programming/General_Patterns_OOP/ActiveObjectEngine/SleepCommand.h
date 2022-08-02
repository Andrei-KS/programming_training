

#pragma once

#include "ActiveObjectEngine.h"
#include <memory>

class SleepCommand : public Command
{
private:
	Command* wakeupCommand;
	ActiveObjectEngine* engine = nullptr;
	long sleepTime = 0;
	long startTime = 0;
	bool started = false;

public:
	SleepCommand(long millisecond, ActiveObjectEngine* e, Command* wakeupCommandIn);
	virtual void execute() throw (std::exception) override;
};