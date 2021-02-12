

#include "TestSleepCommand.h"
#include "SleepCommand.h"
#include <cassert>
#include <ctime>

#include <iostream>

TestSleepCommand::TestSleepCommand()
	: commandExecuted(false)
{
}

void TestSleepCommand::testSleep()
{
	ActiveObjectEngine e;
	CommandWeakup cw(this);
	SleepCommand sc(1000, &e, &cw);

	e.addCommand(&sc);
	long start = clock();
	e.run();
	long stop = clock();
	long sleepTime = (stop - start);

	std::cout << "TestSleepCommand::testSleep() sleepTime = " <<  sleepTime << "\n";

	assert(sleepTime >= 1000);
	assert(sleepTime < 1100);
	assert(commandExecuted && "Command Executed");
}

void CommandWeakup::execute()
{
	std::cout << "CommandWeakup::execute()\n";
	test->commandExecuted = true;
}

CommandWeakup::CommandWeakup(TestSleepCommand* e)
	: test(e) 
{
#ifdef __PRINT_DEBUG_MASSENG__
	std::cout << "CommandWeakup(TestSleepCommand* e)\n";
#endif // __PRINT_DEBUG_MASSENG__
}
