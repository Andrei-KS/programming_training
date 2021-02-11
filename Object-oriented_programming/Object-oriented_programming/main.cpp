#include "ConfigurationFile.h"

#ifdef __COMMAND_PRINT_
#include "Command/CommandPrint.h"
#endif // __COMMAND_PRINT__

#ifdef __ACTIVE_OBJECT_SLEEPCOMMAND__
#include "ActiveObjectEngine/TestSleepCommand.h"
#endif // __ACTIVE_OBJECT_SLEEPCOMMAND__


int main()
{
#ifdef __COMMAND_PRINT_
	InterfacePrint* printHello = new PrintStringToCommandLine("Hellow OOP\n");
	printHello->print();
#endif // __COMMAND_PRINT_

#ifdef __ACTIVE_OBJECT_SLEEPCOMMAND__
	TestSleepCommand tsc;
	tsc.testSleep();
#endif // __ACTIVE_OBJECT_SLEEPCOMMAND__


	return 0;
}