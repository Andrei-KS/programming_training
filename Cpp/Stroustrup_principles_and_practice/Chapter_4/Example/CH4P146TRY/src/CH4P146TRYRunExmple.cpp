/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/17/2021 14:35:56
	author														: Andrei-KS
*/

#include "CH4P146TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P146TRYRunExmple();

namespace {
}

int CH4P146TRYRunExmple::excute()
{
	constexpr double UAD_per_USD = 100.0 / 3.8;
	constexpr double CNY_per_USD = 100.0 / 15.54;
	constexpr double RUB_per_USD = 100.0 / 1.41;
	double value = 0;
	string unit = "";
	cout << "Please, entry value and unit (UAD, CNY or RUB): \n";
	cin >> value >> unit;
	if (unit == "UAD")
	{
		cout << value << " UAD == " << value / UAD_per_USD << " USD";
	}
	else if (unit == "CNY")
	{
		cout << value << " CNY == " << value / CNY_per_USD << " USD";
	}
	else if (unit == "RUB")
	{
		cout << value << " RUB == " << value / RUB_per_USD << " USD";
	}
	else
	{
		cout << "Sorry, i don't know what is '" << unit << "'\n";
	}

	return 0;
}