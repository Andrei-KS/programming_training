#include "SleepCommand.h"
#include <memory>
#include <ctime>

#ifdef __PRINT_DEBUG_MASSENG__
#include <iostream>
#endif // __PRINT_DEBUG_MASSENG__

SleepCommand::SleepCommand(long millisecond, ActiveObjectEngine* e, Command* wakeupCommandIn)
	: wakeupCommand(wakeupCommandIn),
	engine(e),
	sleepTime(millisecond),
	startTime(0),
	started(false)
{
#ifdef __PRINT_DEBUG_MASSENG__
	std::cout << "SleepCommand::SleepCommand(long millisecond, ActiveObjectEngine * e, Command * wakeupCommandIn)\n";
#endif // __PRINT_DEBUG_MASSENG__
}

void SleepCommand::execute() throw(std::exception)
{
	long currentTime = clock();

#ifdef __PRINT_DEBUG_MASSENG__
	std::cout << "SleepCommand::execute() throw(std::exception) currentTime = " <<  currentTime << "\n"
		<< "SleepCommand::execute() throw(std::exception) started = " << started << "\n";
#endif // __PRINT_DEBUG_MASSENG__

	if (!started)
	{
		started = true;
		startTime = currentTime;
		engine->addCommand(this);
	}
	else if ((currentTime - startTime) < sleepTime)
	{
		engine->addCommand(this);
	}
	else
	{
		engine->addCommand(wakeupCommand);
	}
}


