/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/29/2022 17:06:33
	author														: Andrei-KS
*/

#include "CH11P408EXERC12RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC12RunExmple();

namespace {
}

int CH11P408EXERC12RunExmple::excute()
{
	cout << "Reverse the order of characters in a text file.\n"
		<< "Please, enter file name: ";
	string file_name;
	cin >> file_name;
	fstream file{ file_name,ios_base::in | ios_base::out };
	if (!file)
	{
		error("Cann't open file ", file_name);
	}

	file.seekg(0, ios_base::end);
	int file_size = file.tellg();
	int half_size = file_size / 2;

	for (int left = 0; left < half_size; left++)
	{
		int right = file_size - 1 - left;
		char left_ch,right_ch;

		file.seekg(left);
		file.get(left_ch);

		file.seekg(right);
		file.get(right_ch);

		file.seekp(left);
		file.put(right_ch);

		file.seekp(right);
		file.put(left_ch);
	}
	return 0;
}