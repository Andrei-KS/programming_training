/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/21/2022 13:39:08
	author														: Andrei-KS
*/

#include "CH11P382TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P382TRYRunExmple();

namespace {
}

int CH11P382TRYRunExmple::excute()
{
	cout << "Joined GitHub\n";
	cout << "Decimal:\t" << dec << 11 << '/' << 17 << '/' << 2020 << '\n'
		<< "Hexadecimal:\t" << hex << 11 << '/' << 17 << '/' << 2020 << '\n'
		<< "Octal:\t\t" << oct << 11 << '/' << 17 << '/' << 2020 << '\n';
	return 0;
}