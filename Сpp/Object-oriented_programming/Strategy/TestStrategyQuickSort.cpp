#include "TestStrategyQuickSort.h"
#include <cassert>
#include "IntSortHandle.h"

void TestStrategyQuickSort::testQuickSortInts(std::vector<int>& array) throw(std::exception)
{
	StrategyQuickSort qs(&IntSortHandle());
	qs.sort(&array);

	bIsSorted = true;
	for (int i = 1; i < array.size(); i++)
	{
		if (array[i - 1] > array[i])
		{
			bIsSorted = false;
		}
	}

	assert(bIsSorted && "The array of integers is not sorted to ascending ");
}
