/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/28/2022 14:52:21
	author														: Andrei-KS
*/

#include "CH11P408EXERC7RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC7RunExmple();

namespace {
	const string str_not{ "n't" };
}

int CH11P408EXERC7RunExmple::excute()
{
	cout << "The program that replaces punctuation with whitespace,\n"
		<< "but it don’t modify characters within a pair of double quotes(\").\n"
		<< "Please, enter string: ";

	string str;
	getline(cin, str);

	{
		str.push_back(' ');
		string outstr{""};
		char left_char = ' ';
		for (int index = 0; index < str.size(); index++)
		{
			if (str[index] == '-' && !(isalnum(left_char) && isalnum(str[index + 1])))
			{
				outstr += ' ';
				left_char = '-';
				continue;
			}

			if (str[index] == 'n' && isalpha(left_char))
			{
				bool is_found = true;
				for (int substr_index = 0; substr_index < str_not.size() && substr_index + index < str.size(); substr_index++)
				{
					if (str[substr_index + index] != str_not[substr_index])
					{
						is_found = false;
						break;
					}
				}
				if (is_found)
				{
					outstr += " not";
					index += str_not.size() - 1;
					left_char = str_not[str_not.size() - 1];
					continue;
				}
			}

			left_char = str[index];
			outstr += tolower(str[index]);
		}
		str = std::move(outstr);
	}

	for (int index = 0; index < str.size(); index++)
	{
		if (str[index] == '\"')
		{
			// try to find the second " from the pair
			bool is_second_found = false;
			for (int search_index = index + 1; search_index < str.size(); search_index++)
			{
				if (str[search_index] == '\"')
				{
					is_second_found = true;
					index = search_index;
					break;
				}
			}
			if (!is_second_found)
			{
				str[index] = ' ';
			}
			continue;
		}

		if (str[index] != '-' && iswpunct(str[index]))
		{
			str[index] = ' ';
		}
	}
	cout << str;

	return 0;
}