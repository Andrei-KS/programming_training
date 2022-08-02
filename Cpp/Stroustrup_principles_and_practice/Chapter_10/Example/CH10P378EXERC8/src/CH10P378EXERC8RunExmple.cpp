/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/13/2022 18:40:57
	author														: Andrei-KS
*/

#include "CH10P378EXERC8RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH10P378EXERC8RunExmple();

namespace {

	const int size_buffer = 2;
	char buffer[size_buffer];

	void write_from_read(ifstream& ist, ofstream& ost)
	{
		ist.seekg(0, std::ios_base::end);
		// Since the last symbol in the file is eof, it will not be considered
		int size_file = static_cast<int>(ist.tellg()) - 1;
		ist.seekg(0, std::ios_base::beg);
		int amount_blocks = size_file / size_buffer;

		for(int index_block = 0; index_block < amount_blocks; index_block++)
		{
			ist.read(buffer, size_buffer);
			ost.write(buffer, size_buffer);
		}

		int remaining_bytes = size_file - amount_blocks * size_buffer;
		if (remaining_bytes > 0)
		{
			ist.read(buffer, remaining_bytes);
			ost.write(buffer, remaining_bytes);
		}
	}
}

int CH10P378EXERC8RunExmple::excute()
{
	cout << "The program concatenates the two files." << "\n";
	string first_file_name;
	string second_file_name;
	string output_file_name;

	cout << "Please enter first file name: ";
	cin >> first_file_name;
	ifstream first_file{ first_file_name };
	if (!first_file)
	{
		error("can't open input file ", first_file_name);
	}

	cout << "Please enter second file name: ";
	cin >> second_file_name;
	ifstream second_file{ second_file_name };
	if (!second_file)
	{
		error("can't open input file ", second_file_name);
	}

	cout << "Please enter output file name: ";
	cin >> output_file_name;
	ofstream output_file{ output_file_name };
	if (!output_file)
	{
		error("can't open output file ", output_file_name);
	}
	
	write_from_read(first_file, output_file);
	write_from_read(second_file, output_file);

	return 0;
}