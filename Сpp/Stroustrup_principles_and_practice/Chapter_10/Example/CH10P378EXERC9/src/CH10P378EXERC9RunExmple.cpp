/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/14/2022 13:16:55
	author														: Andrei-KS
*/

#include "CH10P378EXERC9RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH10P378EXERC9RunExmple();

namespace {
	bool write_to_buffer(pair<bool, string>& buffer, istream& ist)
	{
		if (!buffer.first)
		{
			ist >> buffer.second;
			if (!ist)
			{
				if (ist.eof())
				{
					return false;
				}
				error("can't read string variable from file");
			}
			buffer.first = true;
		}
		return true;
	}

	void write_from_buffer(pair<bool, string>& buffer, ostream& ost)
	{
		ost << buffer.second << " ";
		if (!ost)
		{
			error("can't write string variable");
		}
		buffer.first = false;
	}

	void write_remaining_words_from(pair<bool, string>& buffer, istream& ist, ostream& ost)
	{
		while (ist)
		{
			if (write_to_buffer(buffer, ist))
			{
				write_from_buffer(buffer, ost);
			}
		}
	}
}

int CH10P378EXERC9RunExmple::excute()
{
	cout << "Takes two files containing sorted whitespace-separated words and merges them, preserving order." << "\n";
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

	pair<bool, string> buffer_f = { false,string() };
	pair<bool, string> buffer_s = { false,string() };
	while (first_file && second_file)
	{
		if (!write_to_buffer(buffer_f, first_file) || !write_to_buffer(buffer_s, second_file))
		{
			break;
		}

		if (buffer_f.second < buffer_s.second)
		{
			write_from_buffer(buffer_f, output_file);
		}
		else
		{
			write_from_buffer(buffer_s, output_file);
		}
	}

	if (first_file)
	{
		write_remaining_words_from(buffer_f, first_file, output_file);
	}
	else
	{
		write_remaining_words_from(buffer_s, second_file, output_file);
	}
	return 0;
}