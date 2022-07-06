/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/17/2021 14:56:37
	author														: Andrei-KS
*/

#include "CH4P149TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P149TRYRunExmple();

namespace {
}

int CH4P149TRYRunExmple::excute()
{
	constexpr double UAD_per_USD = 100.0 / 3.8;
	constexpr double CNY_per_USD = 100.0 / 15.54;
	constexpr double RUB_per_USD = 100.0 / 1.41;
	constexpr double EUR_per_USD = 100.0 / 115.95;
	constexpr double GBP_per_USD = 100.0 / 137.58;
	double value = 0;
	string unit = "";
	cout << "Please, entry value and unit (UAD, CNY, EUR, GBP or RUB): \n";
	cin >> value >> unit;
	switch (unit[0])
	{
	case 'U':
		cout << value << " UAD == " << value / UAD_per_USD << " USD";
		break;
	case 'C':
		cout << value << " CNY == " << value / CNY_per_USD << " USD";
		break;
	case 'E':
		cout << value << " GBP == " << value / EUR_per_USD << " USD";
		break;
	case 'G':
		cout << value << " GBP == " << value / GBP_per_USD << " USD";
		break;
	case 'R':
		cout << value << " RUB == " << value / RUB_per_USD << " USD";
		break;
	default:
		cout << "Sorry, i don't know what is '" << unit << "'\n";
	}
	return 0;
}