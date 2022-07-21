/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/21/2022 17:27:37
	author														: Andrei-KS
*/

#include "CH11P384TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P384TRYRunExmple();

namespace {
}

int CH11P384TRYRunExmple::excute()
{
	int a;
	int b;
	int c;
	int d;
	cin >> a >> hex >> b >> oct >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
	return 0;
}