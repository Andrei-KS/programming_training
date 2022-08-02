#ifndef __STRATEGY_QUICK_SORT__
#define __STRATEGY_QUICK_SORT__

#include "SortHandle.h"

class StrategyQuickSort
{
private:
	SortHandle* itsSortHandle = nullptr;
protected:
	void dosort(int left, int right);
public:
	StrategyQuickSort(SortHandle* handle);
	void sort(void* array);
};

#endif