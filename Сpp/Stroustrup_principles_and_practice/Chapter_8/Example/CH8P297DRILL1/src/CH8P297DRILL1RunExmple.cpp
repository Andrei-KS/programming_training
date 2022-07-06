/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 12/20/2021 10:12:24
	author														: Andrei-KS
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