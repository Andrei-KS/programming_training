/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/29/2022 16:22:50
	author														: Andrei-KS
*/

#include "CH11P408EXERC11RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC11RunExmple();

namespace {
	bool is_in_set(const char symbol ,const string& set_str)
	{
		for (const char ch : set_str)
		{
			if (symbol == ch)
			{
				return true;
			}
		}
		return false;
	}

	/*
	* @param init_str - will be splitted
	* @param whitespace_separated - set of whitespace-separated
	* @return a vector of whitespace-separated substrings from the argument init_str,
	* otherwise empty vector
	*/
	vector<string> split(const string& init_str, const string& whitespace_separated = "")
	{
		vector<string> result{ string() };
		for (char ch : init_str)
		{
			if (ch == ' ' || is_in_set(ch, whitespace_separated))
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

	void print_vector(const string& init_str, const string& whitespace_separated = string())
	{
		cout << "init string: \"" << init_str << "\"\n";
		if (whitespace_separated.size() > 0)
		{
			cout << "set of whitespace-separated: \"" << whitespace_separated << "\"\n";
		}
		cout << "output vector<string>:\n";
		int index = 0;
		for (const string& str : split(init_str, whitespace_separated))
		{
			cout << index << ".\"" << str << "\"\n";
			index++;
		}
		cout << "\n";
	}
}

int CH11P408EXERC11RunExmple::excute()
{
	print_vector("");
	print_vector("as");
	print_vector("av ");
	print_vector("asc f");
	print_vector(" asc f");
	print_vector(" a  s      c f");
	print_vector(" a  v,s      c f");
	print_vector(" a  v,s      c f", ",");
	print_vector(",,,,", ",.");
	print_vector(",a,,,", ",.");
	print_vector(",a..b,,", ",.");

	return 0;
}