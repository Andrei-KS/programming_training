#include "IntSortHandle.h"

void IntSortHandle::swap(int indexElement1, int indexElement2)
{
	int tmp = (*array)[indexElement1];
	(*array)[indexElement1] = (*array)[indexElement2];
	(*array)[indexElement2] = tmp;
}

bool IntSortHandle::boolFirstLessSecond(int indexElement1, int indexElement2) const
{
	return (*array)[indexElement1] < (*array)[indexElement2];
}

void IntSortHandle::setArray(void* arrayIn)
{
	array = static_cast<std::vector<int>*>(arrayIn);
}

int IntSortHandle::length()
{
	return (*array).size();
}
