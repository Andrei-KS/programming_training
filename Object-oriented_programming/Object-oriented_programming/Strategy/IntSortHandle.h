#ifndef __INT_SORT_HANDLE__
#define __INT_SORT_HANDLE__

#include "SortHandle.h"
#include <vector>

class IntSortHandle : public SortHandle
{
private:
	std::vector<int>* array;
public:
	void swap(int indexElement1, int indexElement2) override;
	bool boolFirstLessSecond(int indexElement1, int indexElement2) const override;
	void setArray(void* array) override;
	int length() override;
};

#endif // __INT_SORT_HANDLE__