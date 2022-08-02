/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/14/2021 02:59:10
	author														: Andrei-KS
*/

#include "CH3P106TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH3P106TRYRunExmple();

namespace {
}

int CH3P106TRYRunExmple::excute()
{
	cout << "Please, entry your name and age\n";
	string first_name = "???";
	double age = -1;
	cin >> first_name >> age;
	age = age * 12;
	cout << "Hi " << first_name << " ( age: " << age << ")\n";
	return 0;
}