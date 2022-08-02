/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/29/2022 12:53:18
	author														: Andrei-KS
*/

#include "CH11P408EXERC10RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC10RunExmple();

namespace {
	/*
	* @param init_str - will be splitted
	* @return a vector of whitespace-separated substrings from the argument init_str,
	* otherwise empty vector
	*/
	vector<string> split(const string& init_str)
	{
		vector<string> result{ string() };
		for (char ch : init_str)
		{
			if (ch == ' ')
			{
				if (result.rbegin()->size() != 0)
				{
					result.push_back(string());
				}
			}
			else
			{
				result.rbegin()->push_back(ch);
			}
		}
		if (result.rbegin()->size() == 0)
		{
			result.pop_back();
		}
		return std::move(result);
	}

	void print_vector(const string& init_str)
	{
		cout << "init string: \"" << init_str << "\"\n"
			<< "output vector<string>:\n";
		int index = 0;
		for (const string& str : split(init_str))
		{
			cout << index << ".\"" << str << "\"\n";
			index++;
		}
		cout << "\n";
	}
}

int CH11P408EXERC10RunExmple::excute()
{
	print_vector("");
	print_vector("as");
	print_vector("av ");
	print_vector("asc f");
	print_vector(" asc f");
	print_vector(" a  s      c f");

	return 0;
}