/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/28/2022 12:45:24
	author														: Andrei-KS
*/

#include "CH11P408EXERC6RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC6RunExmple();

namespace {
	string punct_symbols{ ";:,.?!(){}<>/&$@#%^*|~'" };
}

int CH11P408EXERC6RunExmple::excute()
{
	cout << "The program that replaces punctuation with whitespace,\n"
		<< "but it don’t modify characters within a pair of double quotes(\").\n"
		<< "Please, enter string: ";
	string str;
	getline(cin, str);
	for (int index = 0; index < str.size(); index++)
	{
		if (str[index] == '\"')
		{
			// try to find the second " from the pair
			bool is_second_found = false;
			for (int search_index = index+1; search_index < str.size(); search_index++)
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
		for (const char& ch : punct_symbols)
		{
			if (str[index] == ch)
			{
				str[index] = ' ';
				break;
			}
		}
	}
	cout << str;
	return 0;
}