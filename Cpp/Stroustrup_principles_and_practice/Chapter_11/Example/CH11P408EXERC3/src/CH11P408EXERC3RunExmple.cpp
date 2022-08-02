/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/26/2022 13:41:04
	author														: Andrei-KS
*/

#include "CH11P408EXERC3RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC3RunExmple();

namespace {
	const string vowels{ "aeiouy" };
}

int CH11P408EXERC3RunExmple::excute()
{
	cout << "The program that removes all vowels from a file\n"
		<< "Please, enter file name: ";
	
	string file_name;
	cin >> file_name;

	fstream file{ file_name, ios_base::in | ios_base::out };
	if (!file)
	{
		error("Can't open file ", file_name);
	}

	int index_in = 0;
	int index_out = 0;

	char current_symbol;
	bool put_flag = true;
	while (file.get(current_symbol))
	{
		index_in++;
		put_flag = true;
		for (const char& vowel : vowels)
		{
			if (current_symbol == vowel || current_symbol == toupper(vowel))
			{
				put_flag = false;
				break;
			}
		}
		if (put_flag)
		{
			file.seekp(index_out,ios_base::beg);
			file.put(current_symbol);
			index_out++;
		}
		file.seekg(index_in, ios_base::beg);
	}

	// When all vowels have vanished, we should delete redundant places from the file
	file.clear();

	int size_buffer = index_out;
	char* buffer = new char[size_buffer];
	file.seekg(0);
	file.read(buffer, size_buffer);
	file.close();

	file.open(file_name, ios_base::out);
	if (!file)
	{
		error("Can't open file ", file_name);
	}
	file.write(buffer, size_buffer);

	delete [] buffer;
	return 0;
}