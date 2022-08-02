/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/15/2022 12:15:38
	author														: Andrei-KS
*/

#include "CH10P378EXERC11RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH10P378EXERC11RunExmple();

namespace {
}

int CH10P378EXERC11RunExmple::excute()
{
	cout << "This program produced the sum of all the the whitespace-separated integers in a text file.\n"
		<< "Please enter name file:";
	string name_file;
	cin >> name_file;
	ifstream ifs{ name_file };
	if (!ifs.is_open())
	{
		error("can't open input file ", name_file);
	}

	int result = 0;
	char previous_symbol = '\n';
	while (ifs)
	{
		char current_symbol;
		if (ifs >> noskipws >> current_symbol  && isdigit(current_symbol) && (previous_symbol == '\n' || previous_symbol == ' '))
		{
				ifs.putback(current_symbol);
				int number;
				ifs >> number;
				if (ifs >> noskipws >> current_symbol && (current_symbol == '\n' || current_symbol == ' ') || ifs.eof())
				{
					result += number;
				}
		}
		previous_symbol = current_symbol;
	}

	cout << result;
	return 0;
}