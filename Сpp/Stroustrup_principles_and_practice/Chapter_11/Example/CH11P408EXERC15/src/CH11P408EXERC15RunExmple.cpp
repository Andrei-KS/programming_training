/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 08/01/2022 16:34:18
	author														: Andrei-KS
*/

#include "CH11P408EXERC15RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC15RunExmple();

namespace {
	constexpr int AMOUNT_OF_NUMBERS_IN_LINE = 4;
}

int CH11P408EXERC15RunExmple::excute()
{
	cout << "The program that reads a file of whitespace-separated numbers and\n"
		<< "outputs a file of numbers using scientific formatand precision 8 in four\n"
		<< "fields of 20 characters per line.\n"
		<< "Please enter input file name: ";
	string input_file_name;
	cin >> input_file_name;
	ifstream infile{ input_file_name };
	if (!infile)
	{
		error("Can't open input file ", input_file_name);
	}

	cout << "Please enter an output file name: ";
	string output_file_name;
	cin >> output_file_name;
	ofstream outfile{ output_file_name };
	if (!outfile)
	{
		error("Can't open output file ", output_file_name);
	}

	double number;
	int number_index = 0;
	while (infile >> number)
	{
		outfile << setw(20) << scientific << setprecision(8) << number;
		if (number_index == AMOUNT_OF_NUMBERS_IN_LINE)
		{
			outfile << "\n";
			number_index = 0;
		}
		else
		{
			outfile << " ";
			number_index++;
		}
	}

	return 0;
}