/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/25/2022 18:00:17
	author														: Andrei-KS
*/

#include "CH11P407DRILL1_2RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P407DRILL1_2RunExmple();

namespace {
}

int CH11P407DRILL1_2RunExmple::excute()
{
	int birth_year = 1992;
	cout << "Birth year\n"
		<< "In decimal:\t" << dec << birth_year << "\n"
		<< "In hexadecimal:\t" << hex << birth_year << "\n"
		<< "In octal:\t" << oct << birth_year;
	return 0;
}