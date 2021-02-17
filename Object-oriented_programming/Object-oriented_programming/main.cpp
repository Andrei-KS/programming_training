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
#endif // __EXAMPLE_TEMPLATE_METHOD_QUICK_SORT__

#ifdef __EXAMPLE_STRATEGY_QUICK_SORT__
#include "Strategy/TestStrategyQuickSort.h"
#endif // __EXAMPLE_STRATEGY_QUICK_SORT__

#ifdef __EXAMPLE_SIMPEL_SINGLETON__
#include "Singleton/TestSimpleSingleton.h"
#endif // __EXAMPLE_SIMPEL_SINGLETON__

#ifdef __EXAMPLE_MONOSTATE_TURNSTILE__
#include "Monostate/TestTurnstile.h"
#endif // __EXAMPLE_MONOSTATE_TURNSTILE__

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
#endif // __EXAMPLE_TEMPLATE_METHOD_QUICK_SORT__

#ifdef __EXAMPLE_STRATEGY_QUICK_SORT__
	TestStrategyQuickSort ttmqs;
	ttmqs.testQuickSortInts(std::vector<int>{ 1, 3, 4, 2, 3, 1, 4 });
	ttmqs.testQuickSortInts(std::vector<int>{});
	ttmqs.testQuickSortInts(std::vector<int>{ 1});
	ttmqs.testQuickSortInts(std::vector<int>{ 1, 1});
	ttmqs.testQuickSortInts(std::vector<int>{ 2, 1});
	ttmqs.testQuickSortInts(std::vector<int>{ 0, 1,5,9,23,4,1,356,768,4,24,898,2,2435,8,0});
#endif // __EXAMPLE_STRATEGY_QUICK_SORT__

#ifdef __EXAMPLE_SIMPEL_SINGLETON__
	TestSimpleSingleton tss;
	tss.TestCreatSimpleSingleton();
#endif // __EXAMPLE_SIMPEL_SINGLETON__

#ifdef __EXAMPLE_MONOSTATE_TURNSTILE__
	TestTurnstile* t = nullptr;
	t = &TestTurnstile_Init();
	t->test();
	t = &TestTurnstile_Coin();
	t->test();
	t = &TestTurnstile_CoinAndPass();
	t->test();
	t = &TestTurnstile_TwoCoins();
	t->test();
	t = &TestTurnstile_Pass();
	t->test();
	t = &TestTurnstile_CancelAlarm();
	t->test();
	t = &TestTurnstile_TwoOperations();
	t->test();
#endif // __EXAMPLE_MONOSTATE_TURNSTILE__

	return 0;
}