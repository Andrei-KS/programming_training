/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/28/2022 17:18:28
	author														: Andrei-KS
*/

#include "CH11P408EXERC9RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC9RunExmple();

namespace {
	const string CONVERT_TO_BINARY_COMMAND = "!bin";
	const string CONVERT_TO_TEXT_COMMAND	= "!text";
	const string EXIT_COMMAND					= "!exit";
	const string BACK_COMMAND					= "!back";

	void promo()
	{
		cout << "Options:\n"
			<< "1. " << left << setw(10) << CONVERT_TO_BINARY_COMMAND << right << " - open converter from the ordinary text file into binary;\n"
			<< "2. " << left << setw(10) << CONVERT_TO_TEXT_COMMAND << right << " - open converter from the binary file into text;\n"
			<< "3. " << left << setw(10) << EXIT_COMMAND << right << " - exit.\n"
			<< ">";
	}

	void promo_subprogram()
	{
		cout << "Please, enter the input text file or enter " << BACK_COMMAND << " to go back the main menu.\n"
			<< ">";
	}

	void text_to_bin(ifstream& infile, ofstream& outfile);
	void bin_to_text(ifstream& infile, ofstream& outfile);

	void subprogram(void (*work_function)(ifstream&, ofstream&))
	{
		promo_subprogram();
		string str;
		while (getline(cin, str))
		{
			if (str.compare(0, BACK_COMMAND.size(), BACK_COMMAND) == 0)
			{
				break;
			}
			ios::openmode in_mode = ios_base::in | (work_function == bin_to_text ? 0 : ios::binary);
			ifstream infile{ str, in_mode };
			if (!infile)
			{
				cout << "Can't open input file " << str << "\n";
			}
			else
			{
				cout << "Please, enter output file name\n"
					<< ">";

				string output_file_name;
				if (!getline(cin, output_file_name))
				{
					cout << "Something went wrong when entering input_file_name\n";
					continue;
				}
				ios::openmode out_mod = ios_base::out | (work_function == text_to_bin ? 0 : ios::binary);
				ofstream outfile{ output_file_name, out_mod };
				if (!outfile)
				{
					cout << "Can't open input file " << output_file_name << "\n";
				}
				else
				{
					work_function(infile, outfile);
				}
			}
			promo_subprogram();
		}
	}

	void text_to_bin(ifstream& infile, ofstream& outfile)
	{
		cout << "conversion of text to binary file was start\n";

		if (!(infile && outfile))
		{
			error("Something wrong with input or output files");
		}

		for (char ch; infile.get(ch);)
		{
			if (!outfile.write(as_bytes(ch), sizeof(char)))
			{
				break;
			}
		}

		cout << "conversion of text to binary file finished\n";
	}

	void bin_to_text(ifstream& infile, ofstream& outfile)
	{
		cout << "conversion of binary to text file was start\n";

		if (!(infile && outfile))
		{
			error("Something wrong with input or output files");
		}

		for (char ch; infile.read(as_bytes(ch), sizeof(char));)
		{
			if (!outfile.put(ch))
			{
				break;
			}
		}

		cout << "conversion of binary to text file finished\n";
	}
}

int CH11P408EXERC9RunExmple::excute()
{
	promo();
	string str;
	while (getline(cin,str))
	{
		if (str.compare(0, EXIT_COMMAND.size(), EXIT_COMMAND) == 0)
		{
			break;
		}
		else if (str.compare(0, CONVERT_TO_BINARY_COMMAND.size(), CONVERT_TO_BINARY_COMMAND) == 0)
		{
			subprogram(text_to_bin);
		}
		else if (str.compare(0, CONVERT_TO_TEXT_COMMAND.size(), CONVERT_TO_TEXT_COMMAND) == 0)
		{
			subprogram(bin_to_text);
		}
		else
		{
			cout << "Wrong entering. Please, try again";
		}
		promo();
	}
	return 0;
}