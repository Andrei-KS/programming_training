/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 11/06/2024 11:13:09
	author                                          : Andrei-KS
*/

#include "CH21P800EXERC8RunExmple.h"
#include "std_lib_facilities.h"
#include <map>

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P800EXERC8RunExmple();

namespace {
}

int CH21P800EXERC8RunExmple::excute()
{
  ifstream inputFile("test.txt");
  if (!inputFile.is_open())
  {
    error("error:: CH21P800EXERC8RunExmple::excute can't open text.txt");
  }

  map<string,int> words; // keep(word, frequency) pairs
  for (string s; inputFile >> s; )
  {
    ++words[s]; // note: words is subscripted by a string
  }

  inputFile.close();

  vector<pair<string, int>> wordFrequency;
  wordFrequency.reserve(words.size());
  for (const auto& kv : words)
  {
    wordFrequency.emplace(wordFrequency.end(), pair<string, int>(kv.first,kv.second));
  }
  sort(wordFrequency.begin(), wordFrequency.end(),
    [](pair<string, int> lh, pair<string, int>rh) {return lh.second > rh.second || lh.second == rh.second && lh.first < rh.first; });
  for (const auto& p : wordFrequency)
  {
    cout << setw(4) << p.second << "\t: " << p.first << '\n';
  }
	return 0;
}