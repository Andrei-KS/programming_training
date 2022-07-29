/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/29/2022 18:24:10
	author														: Andrei-KS
*/

#include "CH11P408EXERC13RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC13RunExmple();

namespace {
}

int CH11P408EXERC13RunExmple::excute()
{
	cout << "Reverse the order of words (defined as whitespace-separated strings) in a file.\n"
		<< "Please, enter file name: ";
	string file_name;
	cin >> file_name;

	ifstream ifile{ file_name };
	if (!ifile)
	{
		error("Cann't open input file ", file_name);
	}

	vector<string> input_str{string()};
	while (ifile >> *input_str.rbegin())
	{
		input_str.push_back(string());
	}

	ifile.close();

	ofstream ofile{ file_name };
	if (!ofile)
	{
		error("Cann't open output file ", file_name);
	}

	for (vector<string>::reverse_iterator it = input_str.rbegin(); it != input_str.rend(); it++)
	{
		ofile << *it << (!it->size()? "" : " ");
	}

	ofile.close();

	return 0;
}