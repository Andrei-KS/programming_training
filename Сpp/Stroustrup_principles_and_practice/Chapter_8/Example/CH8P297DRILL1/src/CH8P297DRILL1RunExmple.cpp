/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 12/20/2021 10:12:24
	author                                       : Andrei-KS
*/

#include "CH8P297DRILL1RunExmple.h"
#include "my.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH8P297DRILL1RunExmple();

int foo;

namespace {
}

int CH8P297DRILL1RunExmple::excute()
{
	foo = 7;
	print_foo();
	print(99);
	return 0;
}