/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/21/2022 18:02:29
	author														: Andrei-KS
*/

#include "CH11P386TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P386TRYRunExmple();

namespace {
}

int CH11P386TRYRunExmple::excute()
{
	cout << 1234567.89 << '\n'
		<< fixed << 1234567.89 << '\n'
		<< scientific << 1234567.89 << '\n';
	return 0;
}