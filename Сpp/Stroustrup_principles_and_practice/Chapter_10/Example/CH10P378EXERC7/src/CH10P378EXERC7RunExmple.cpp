/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/12/2022 17:04:52
	author														: Andrei-KS
*/

/*
	Simple Roman calculator
	This program implements a basic expression calculator.
	Input from cin; output to cout.
	The grammar for input is:

	//TODO

*/
#include "CH10P378EXERC7RunExmple.h"
#include "std_lib_facilities.h"
#include "Roman_int.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH10P378EXERC7RunExmple();

namespace {
}

int CH10P378EXERC7RunExmple::excute()
{
	cout << "Please enter Roman_int: ";
	Roman_int r;
	cin >> r;
	cout << "Roman_int as int: " << r.as_int() << "\n";
	cout << "int as Roman_int: " << r << "\n";
	cout << "Roman " << r << " equals " << r.as_int() << '\n';
	cout << Roman_int::is_valid(r.as_int()) << "\n";
	cout << Roman_int(3) << " + " << Roman_int(5) << " = " << Roman_int(3) + Roman_int(5) << "\n";
	cout << Roman_int(3) << " * " << Roman_int(5) << " = " << Roman_int(3) * Roman_int(5) << "\n";
	cout << Roman_int(10) << " / " << Roman_int(3) << " = " << Roman_int(10) / Roman_int(3) << "\n";
	cout << Roman_int(10) << " % " << Roman_int(3) << " = " << Roman_int(10) % Roman_int(3) << "\n";
	cout << Roman_int(Roman_int(10)) << " % " << Roman_int(3) << " = " << Roman_int(10) % Roman_int(3) << "\n";
	return 0;
}