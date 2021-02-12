

#include "TestTemplateMethodQuickSort.h"
#include <cassert>

void TestTemplateMethodQuickSort::testQuickSortInts(std::vector<int>& array)
{
	IntQuickSort qs;
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

void TestTemplateMethodQuickSort::testQuickSortDoubles(std::vector<double>& array) throw(std::exception)
{
	DoubleQuickSort qs;
	qs.sort(&array);

	bIsSorted = true;
	for (int i = 1; i < array.size(); i++)
	{
		if (array[i - 1] > array[i])
		{
			bIsSorted = false;
		}
	}

	assert(bIsSorted && "The array of doubles is not sorted to ascending ");
}
