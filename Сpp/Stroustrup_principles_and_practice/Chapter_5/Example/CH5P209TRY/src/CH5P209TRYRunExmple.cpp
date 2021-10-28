/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/29/2021 00:32:26
	author                                       : Andrei-KS
*/

#include "CH5P209TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH5P209TRYRunExmple();

namespace {
	int area(int length, int width)
	{
		if (length <= 0 || width <= 0)
			error("area() pre-condition");
		int a = length * width;
		if (a <= 0)
			error("area() post-condition");
		return a;
	}
}

int CH5P209TRYRunExmple::excute()
{
	area(10000000000, 100);
	return 0;
}