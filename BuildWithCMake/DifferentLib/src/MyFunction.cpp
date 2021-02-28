#include "MyFunction.h"
#include <iostream>

void MyFunction::print()
{
	std::cout << "Hello, "<< TEXT(__LIBSTRING__) << std::endl;
}