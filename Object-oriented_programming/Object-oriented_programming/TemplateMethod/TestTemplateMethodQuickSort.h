#ifndef __TEST_TEMPLATE_METHOD_QUICK_SORT__
#define __TEST_TEMPLATE_METHOD_QUICK_SORT__

#include "TemplateMethodQuickSort.h"
#include <vector>
#include <exception>

class TestTemplateMethodQuickSort
{
	bool bIsSorted = true;
public:
	void testQuickSortInts(std::vector<int>& array) throw(std::exception);
	void testQuickSortDoubles(std::vector<double>& array) throw(std::exception);
};

#endif