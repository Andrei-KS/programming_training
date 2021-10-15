#ifndef __SORT_HANDLE__
#define __SORT_HANDLE__

class SortHandle //Interface
{
public:
	virtual void swap(int indexElement1, int indexElement2) = 0;
	virtual bool boolFirstLessSecond(int indexElement1, int indexElement2) const = 0;
	virtual void setArray(void* array) = 0;
	virtual int length() = 0;
};

#endif // __SORT_HANDLE__