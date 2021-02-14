#ifndef __TEST_STRATEGY_QUICK_SORT__
#define __TEST_STRATEGY_QUICK_SORT__

#include <vector>
#include "StrategyQuickSort.h"

class TestStrategyQuickSort
{
	bool bIsSorted = true;
public:
	void testQuickSortInts(std::vector<int>& array) throw(std::exception);
};

#endif // __TEST_STRATEGY_QUICK_SORT__