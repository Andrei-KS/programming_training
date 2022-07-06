/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/17/2021 18:13:19
	author														: Andrei-KS
*/

#include "CH4P165TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P165TRYRunExmple();

namespace {
}

int CH4P165TRYRunExmple::excute()
{
	vector<string> words;
	vector<string> blockList = { "Broccoli" };
	for (string temp; cin >> temp;)
	{
		words.push_back(temp);
	}
	cout << "Words number: " << words.size() << "\n";

	sort(words);
	for (int i = 0; i < words.size(); ++i)
	{
		if (i == 0 || words[i - 1] != words[i])
		{
			bool isDisply = true;
			for (const string blockWord : blockList)
			{
				if (words[i] == blockWord)
				{
					isDisply = false;
					break;
				}
			}
			if(isDisply) cout << words[i] << "\n";
		}
	}
	return 0;
}