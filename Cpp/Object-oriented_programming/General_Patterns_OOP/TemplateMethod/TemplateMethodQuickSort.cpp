#include "TemplateMethodQuickSort.h"

void TemplateMethodQuickSort::dosort(int left, int right)
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
		if (boolFirstLessSecond(curRight, pivot))
		{
			swap(curRight, curLeft);
			curLeft++;
		}
		else
		{
			swap(curRight, pivot);
			pivot--;
		}
	}
	dosort(left, pivot);
	dosort(pivot + 1, right);
}

void IntQuickSort::sort(std::vector<int>* arrayIn)
{
	array = arrayIn;
	dosort(0,array->size());
}

void IntQuickSort::swap(int indexElement1, int indexElement2)
{
	int tmp = (*array)[indexElement1];
	(*array)[indexElement1] = (*array)[indexElement2];
	(*array)[indexElement2] = tmp;
}

bool IntQuickSort::boolFirstLessSecond(int indexElement1, int indexElement2)
{
	return (*array)[indexElement1] < (*array)[indexElement2];
}

void DoubleQuickSort::sort(std::vector<double>* arrayIn)
{
	array = arrayIn;
	dosort(0, array->size());
}

void DoubleQuickSort::swap(int indexElement1, int indexElement2)
{
	double tmp = (*array)[indexElement1];
	(*array)[indexElement1] = (*array)[indexElement2];
	(*array)[indexElement2] = tmp;
}

bool DoubleQuickSort::boolFirstLessSecond(int indexElement1, int indexElement2)
{
	return (*array)[indexElement1] < (*array)[indexElement2];
}
