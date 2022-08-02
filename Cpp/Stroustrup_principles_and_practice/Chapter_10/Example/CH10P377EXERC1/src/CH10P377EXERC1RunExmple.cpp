/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/07/2022 18:40:57
	author														: Andrei-KS
*/

#include "CH10P377EXERC1RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH10P377EXERC1RunExmple();

namespace {
	void get_sum_all_integer_from_stream(istream& ist, int& result)
	{
		result = 0;

		for (int current_value; ist >> current_value;)
		{
			result += current_value;

		}

		if (ist.eof())
		{
			return;
		}

		result = 0;
		if (ist.bad())
		{
			error("ist is bad");
		}

		if (ist.fail())
		{
			error("ist is fail");
		}
	}
}

int CH10P377EXERC1RunExmple::excute()
{
	std::cout << "Please enter input file name: ";
	string iname;
	std::cin >> iname;
	ifstream ist{ iname };
	if (!ist)
	{
		error("can't open input file ", iname);
	}
	int result = 0;
	get_sum_all_integer_from_stream(ist, result);

	ist.close();
	std::cout << "Sum is " << result << "\n";

	return 0;
}