/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 08/01/2022 14:13:47
	author														: Andrei-KS
*/

#include "CH11P408EXERC14RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC14RunExmple();

namespace {
	const vector<string> classification_str = {
		"Is c whitespace (' ', '\\t', '\\n', etc.)?",
		"Is c a letter ('a'.. 'z', 'A'.. 'Z') (note: not '_')?",
		"Is c a decimal digit ('0'.. '9')?",
		"Is c a hexadecimal digit (decimal digit or 'a'.. 'f' or 'A'.. 'F')?",
		"Is c an uppercase letter?",
		"Is c a lowercase letter?",
		"Is c a letter or a decimal digit?",
		"Is c a control character (ASCII 0..31 and 127)?",
		"Is c not a letter, digit, whitespace, or invisible control character?",
		"Is c printable (ASCII ' '.. '~')?",
		"Is isalpha(c) or isdigit(c) or ispunct(c) (note: not space)?"
	};

	
	const vector<int (*)(int)> classification_func = {
		isspace,
		isalpha,
		isdigit,
		isxdigit,
		isupper,
		islower,
		isalnum,
		iscntrl,
		ispunct,
		isprint,
		isgraph,
	};
}

int CH11P408EXERC14RunExmple::excute()
{
	if (classification_str.size() != classification_func.size())
	{
		error("classification_str.size() != classification_func.size(). Please check them!");
	}

	cout << "a program that reads a text file and writes out how many characters\n"
		<< "of each character classification.\n"
		<< "Please enter file name: ";
	string file_name;
	cin >> file_name;
	ifstream file{ file_name };
	if(!file)
	{
		error("Can't open file ", file_name);
	}

	vector<int> classification_counters(classification_str.size(),0);
	for (char ch; file.get(ch);)
	{
		for ( int index = 0; index < classification_func.size(); index++)
		{
			classification_counters[index] += (classification_func[index](ch) ? 1 : 0);
		}
	}

	for (int index = 0; index < classification_counters.size(); index++)
	{
		cout << setw(5) << classification_counters[index] << "  " << classification_str[index] << "\n";
	}

	return 0;
}