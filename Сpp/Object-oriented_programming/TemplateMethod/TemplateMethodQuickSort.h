/*
* Pattern of Template Method
* it determines base algorithm
* And his heirs are responsible for the details of the algorithm.
*/
#ifndef __TEMPLATE_METHOD_QUICKSORT__
#define __TEMPLATE_METHOD_QUICKSORT__

#include <vector>

class TemplateMethodQuickSort
{
protected:
	void dosort(int left, int right);
	virtual void swap(int indexElement1, int indexElement2) = 0;
	virtual bool boolFirstLessSecond(int indexElement1, int indexElement2) = 0;
};


class IntQuickSort : public TemplateMethodQuickSort
{
private:
	std::vector<int>* array;

public:
	void sort(std::vector<int>* arrayIn);

protected:
	void swap(int indexElement1, int indexElement2) override;
	virtual bool boolFirstLessSecond(int indexElement1, int indexElement2) override;
};


class DoubleQuickSort : public TemplateMethodQuickSort
{
private:
	std::vector<double>* array;

public:
	void sort(std::vector<double>* arrayIn);

protected:
	void swap(int indexElement1, int indexElement2) override;
	virtual bool boolFirstLessSecond(int indexElement1, int indexElement2) override;
};

#endif // __TEMPLATE_METHOD_QUICKSORT__