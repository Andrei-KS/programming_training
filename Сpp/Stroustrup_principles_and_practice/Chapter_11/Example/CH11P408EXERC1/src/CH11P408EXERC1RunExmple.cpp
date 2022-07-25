/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/25/2022 18:21:30
	author														: Andrei-KS
*/

#include "CH11P408EXERC1RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC1RunExmple();

namespace {
}

int CH11P408EXERC1RunExmple::excute()
{
	cout << "This program produce new file that contains lowercase letters from file that name will be entered by you.\n"
		<< "Please, enter file name: ";
	string file_name;
	cin >> file_name;
	ifstream file_in{ file_name };
	if (!file_in)
	{
		error("can't open ", file_name);
	}

	string file_out_name{ file_name + "_out" };
	ofstream file_out{ file_out_name };
	if (!file_out)
	{
		error("can't open ", file_out_name);
	}

	string buffer;
	while (getline(file_in, buffer))
	{
		for (char& ch : buffer)
		{
			file_out << static_cast<char>(tolower(ch));
		}
		if (!file_in.eof())
		{
			file_out << "\n";
		}
	}

	cout << "Result was written to " << file_out_name;
	return 0;
}