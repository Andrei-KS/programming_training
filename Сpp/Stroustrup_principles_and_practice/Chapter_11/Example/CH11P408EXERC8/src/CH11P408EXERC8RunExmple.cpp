/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 08/01/2022 13:05:14
	author														: Andrei-KS
*/

#include "CH11P408EXERC8RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC8RunExmple();

namespace {
	const string str_not{ "n't" };

	string strings_processing(const string& init_str)
	{
		string result = init_str;
		{
			result.push_back(' ');
			string outstr{ "" };
			char left_char = ' ';
			for (int index = 0; index < result.size(); index++)
			{
				if (result[index] == '-' && !(isalnum(left_char) && isalnum(result[index + 1])))
				{
					outstr += ' ';
					left_char = '-';
					continue;
				}

				if (result[index] == 'n' && isalpha(left_char))
				{
					bool is_found = true;
					for (int substr_index = 0; substr_index < str_not.size() && substr_index + index < result.size(); substr_index++)
					{
						if (result[substr_index + index] != str_not[substr_index])
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

				left_char = result[index];
				outstr += tolower(result[index]);
			}
			result = std::move(outstr);
		}

		for (int index = 0; index < result.size(); index++)
		{
			if (result[index] == '\"')
			{
				// try to find the second " from the pair
				bool is_second_found = false;
				for (int search_index = index + 1; search_index < result.size(); search_index++)
				{
					if (result[search_index] == '\"')
					{
						is_second_found = true;
						index = search_index;
						break;
					}
				}
				if (!is_second_found)
				{
					result[index] = ' ';
				}
				continue;
			}

			if (result[index] != '-' && iswpunct(result[index]))
			{
				result[index] = ' ';
			}
		}

		return std::move(result);
	}
}

int CH11P408EXERC8RunExmple::excute()
{
	cout << "The program makes a dictionary from the text in the file.\n"
		<< "Please, enter file name: ";
	string file_name;
	cin >> file_name;

	ifstream file{ file_name };
	if (!file)
	{
		error("Can't open file ", file_name);
	}

	string str;
	vector<string> vs;
	while(getline(file, str))
	{
		istringstream iss{strings_processing(str)};
		for (string word; iss >> word; )
		{
			vs.push_back(word);
		}
	}

	sort(vs.begin(), vs.end());

	for (int i = 0; i < vs.size(); ++i)
	{
		if (i == 0 || vs[i] != vs[i-1])
		{
			vs[i][0] = toupper(vs[i][0]);
			cout << vs[i] << '\n';
		}
	}

	return 0;
}