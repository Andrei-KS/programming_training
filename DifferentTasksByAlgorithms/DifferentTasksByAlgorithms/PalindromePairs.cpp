#include "PalindromePairs.h"
#include <iostream>
#include <algorithm>

Solution::WordDictionary::~WordDictionary()
{
	clear();
	delete root;
	root = nullptr;
}

void Solution::WordDictionary::clear()
{
	if (!root)
	{
		return;
	}
	vector<Node*> level;
	for (auto it = root->child.begin(); it != root->child.end(); it++)
	{
		level.push_back(it->second);
	}
	while (!level.empty())
	{
		vector<Node*> nextLevel;
		for (int i = 0; i < level.size(); i++)
		{
			auto it = level[i]->child.begin();
			while (it != level[i]->child.end())
			{
				nextLevel.push_back(it->second);
				it++;
			}
			delete level[i];
			level[i] = nullptr;
		}
		level = nextLevel;
	}
}

void Solution::WordDictionary::insert(const string& word, int index)
{
	Node* curNode = this->root;
	for (int indexLetter = 0; indexLetter < word.size(); indexLetter++)
	{
		if (curNode->child.find(word[indexLetter]) == curNode->child.end())
		{
			curNode->child[word[indexLetter]] = new Node;
		}
		curNode = curNode->child[word[indexLetter]];
	}
	curNode->val = index;
}

int Solution::WordDictionary::searchWord(string word)
{
	Node* curNode = this->root;
	for (int indexLetter = 0; indexLetter < word.size(); indexLetter++)
	{
		if (curNode->child.find(word[indexLetter]) == curNode->child.end())
		{
			return -1;
		}
		curNode = curNode->child[word[indexLetter]];
	}
	return curNode->val;
}

bool Solution::WordDictionary::searchPrefix(string prefix)
{
	Node* curNode = this->root;
	for (int indexLetter = 0; indexLetter < prefix.size(); indexLetter++)
	{
		if (curNode->child.find(prefix[indexLetter]) == curNode->child.end())
		{
			return false;
		}
		curNode = curNode->child[prefix[indexLetter]];
	}
	return true;
}

void Solution::WordDictionary::removeWord(string word)
{
	stack<pair<char, Node*>> st;
	st.push({ '\0',root });
	for (int indexLetter = 0; indexLetter < word.size(); indexLetter++)
	{
		if (st.top().second->child.find(word[indexLetter]) == st.top().second->child.end())
		{
			return;
		}
		st.push({ word[indexLetter],st.top().second->child[word[indexLetter]] });
	}

	if (st.top().second->val != -1)
	{
		st.top().second->val = -1;
		while (st.top().second->child.empty() && st.top().second->val == -1 && st.top().second != root)
		{
			char simbol = st.top().first;
			delete st.top().second;
			st.pop();
			st.top().second->child.erase(simbol);
		}
	}
}


bool Solution::isPalindrome(const string& str)
{
	for (int i = 0; i < str.size() / 2; i++)
	{
		if (str[i] != str[str.size() - 1 - i])
		{
			return false;
		}
	}
	return true;
}

vector<vector<int>> Solution::palindromePairs(vector<string>& words)
{
	vector<vector<int>> ans;

	WordDictionary reverseWordDictionary;
	for (int index = 0; index < words.size(); index++)
	{
		string reversWord = words[index];
		reverse(reversWord.begin(), reversWord.end());
		reverseWordDictionary.insert(reversWord, index);
	}

	for (int index = 0; index < words.size(); index++)
	{
		//cout << "current word : " << words[index] << "\n";
		for (int j = 0; j <= words[index].size(); j++)
		{
			/*
					word
			   left-^----right
					word
				   --^---
				...
					word
				   ----^--

				if left part is polindrom, need find right path in Dictionary
				we get such a palindrome: right + left + right

				if right part is polindrom, need find left path in Dictionary
				we get such a palindrome: left + right + left
			*/
			if (j && isPalindrome(words[index].substr(0, j)))
			{
				//cout << " left -> " << words[index].substr(0, j) << "\n";
				int secondIndex = reverseWordDictionary.searchWord(words[index].substr(j, words[index].size() - j));
				if (secondIndex != -1 && secondIndex != index)
				{
					ans.push_back({ secondIndex, index });
				}
			}
			//cout << " " << words[index].substr(j, words[index].size() - j) << words[index] << "\n";
			
			if (isPalindrome(words[index].substr(j, words[index].size() - j)))
			{
				//cout << " right -> " << words[index].substr(0, words[index].size() - j) << "\n";
				int secondIndex = reverseWordDictionary.searchWord(words[index].substr(0, j));
				if (secondIndex != -1 && secondIndex != index)
				{
					ans.push_back({ index, secondIndex });
				}
			}
		}
	}

	return ans;
}

void test(vector<string>& words)
{
	Solution s;
	vector<vector<int>> ans = s.palindromePairs(words);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "], ";
	}
	cout << "\n\n";
}

int main()
{
	test(vector<string>{"abcd","dcba","lls","s","sssll"});
	test(vector<string>{"aabc"});
	test(vector<string>{"abcd", "lls", "s", "sssll", "dcba"});
	test(vector<string>{"a", ""});
	return 0;
}
