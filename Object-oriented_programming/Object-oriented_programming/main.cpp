#include "ConfigurationFile.h"

#ifdef __EXAMPLE_COMMAND_PRINT__
#include "Command/CommandPrint.h"
#endif // __COMMAND_PRINT__

#ifdef __EXAMPLE_ACTIVE_OBJECT_SLEEPCOMMAND__
#include "ActiveObjectEngine/TestSleepCommand.h"
#endif // __ACTIVE_OBJECT_SLEEPCOMMAND__

#ifdef __EXAMPLE_TEMPLATE_METHOD_QUICK_SORT__
#include "TemplateMethod/TestTemplateMethodQuickSort.h"
#include <vector>
#endif

int main()
{
#ifdef __EXAMPLE_COMMAND_PRINT__
	InterfacePrint* printHello = new PrintStringToCommandLine("Hellow OOP\n");
	printHello->print();
#endif // __COMMAND_PRINT_

#ifdef __EXAMPLE_ACTIVE_OBJECT_SLEEPCOMMAND__
	TestSleepCommand tsc;
	tsc.testSleep();
#endif // __ACTIVE_OBJECT_SLEEPCOMMAND__

#ifdef __EXAMPLE_TEMPLATE_METHOD_QUICK_SORT__
	TestTemplateMethodQuickSort ttmqs;
	ttmqs.testQuickSortInts(std::vector<int>{ 1,3,4,2,3,1,4 });
	ttmqs.testQuickSortInts(std::vector<int>{});
	ttmqs.testQuickSortInts(std::vector<int>{ 1});
	ttmqs.testQuickSortInts(std::vector<int>{ 1, 1});
	ttmqs.testQuickSortInts(std::vector<int>{ 2, 1});

	ttmqs.testQuickSortDoubles(std::vector<double>{ 1, 3, 4, 2, 3, 1, 4 });
	ttmqs.testQuickSortDoubles(std::vector<double>{});
	ttmqs.testQuickSortDoubles(std::vector<double>{ 1});
	ttmqs.testQuickSortDoubles(std::vector<double>{ 1, 1});
	ttmqs.testQuickSortDoubles(std::vector<double>{ 2, 1});
#endif

	return 0;
}