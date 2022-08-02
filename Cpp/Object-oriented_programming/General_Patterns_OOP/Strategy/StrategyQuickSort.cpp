#include "StrategyQuickSort.h"

StrategyQuickSort::StrategyQuickSort(SortHandle* handle)
{
	itsSortHandle = handle;
}

void StrategyQuickSort::dosort(int left, int right)
{
	if (left == right)
	{
		return;
	}

	int pivot = right - 1;
	int curLeft = left;
	while (curLeft < pivot)
	{
		int curRight = pivot - 1;
		if (itsSortHandle->boolFirstLessSecond(curRight, pivot))
		{
			itsSortHandle->swap(curRight, curLeft);
			curLeft++;
		}
		else
		{
			itsSortHandle->swap(curRight, pivot);
			pivot--;
		}
	}
	dosort(left, pivot);
	dosort(pivot + 1, right);
}


void StrategyQuickSort::sort(void* array)
{
	itsSortHandle->setArray(array);
	dosort(0, itsSortHandle->length());

}
