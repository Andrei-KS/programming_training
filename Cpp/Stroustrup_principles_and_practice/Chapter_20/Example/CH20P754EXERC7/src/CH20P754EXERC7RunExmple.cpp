/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/23/2023 15:47:42
	author                                          : Andrei-KS
*/

#include "CH20P754EXERC7RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P754EXERC7RunExmple();

namespace {
  vector<string>::iterator findLastString(vector<string>& strings)
  {
    if (!strings.size())
    {
      return strings.end();
    }

    vector<string>::iterator lastStringIter = strings.begin();
    vector<string>::iterator currIter = strings.begin();
    while (currIter != strings.end())
    {
      if (*currIter > *lastStringIter)
      {
        lastStringIter = currIter;
      }
      ++currIter;
    }

    return lastStringIter;
  }
}

int CH20P754EXERC7RunExmple::excute()
{
  vector<string> probs = {
    "aaa",
    "ewr",
    "zdr",
    "a",
    "aaaa",
    "zvv",
    "bbbb",
  };

  vector<string>::iterator foundLastStringIter = findLastString(probs);
  if (foundLastStringIter != probs.end())
  {
    cout << "Found last string : " << *findLastString(probs) << "\n";
  }
  else
  {
    cout << "Probs is empty\n";
  }

	return 0;
}