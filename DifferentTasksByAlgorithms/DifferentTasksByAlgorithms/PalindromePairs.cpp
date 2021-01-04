#include "PalindromePairs.h"
#include <iostream>

Solution::TrieInt::~TrieInt()
{
	clear();
	delete root;
	root = nullptr;
}

void Solution::TrieInt::clear()
{
	if (!root)
	{
		return;
	}
	vector<NodeInt*> level;
	for (auto it = root->child.begin(); it != root->child.end(); it++)
	{
		level.push_back(it->second);
	}
	while (!level.empty())
	{
		vector<NodeInt*> nextLevel;
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

void Solution::TrieInt::insert(vector<int>& seq)
{
	NodeInt* curNode = root;
	for (int index = 0; index < seq.size(); index++)
	{
		if (curNode->child.find(seq[index]) == curNode->child.end())
		{
			curNode->child[seq[index]] = new NodeInt;
		}
		curNode = curNode->child[seq[index]];
	}
}

vector<vector<int>> Solution::TrieInt::getSequnces()
{
	vector<vector<int>> ans;
	
	stack<pair<NodeInt*,vector<int>>> st;
	st.push({ root, vector<int>()});
	while (!st.empty())
	{
		NodeInt* cur = st.top().first;
		vector<int> v = st.top().second;
		st.pop();
		if (cur->child.empty() && cur != root) {
			ans.push_back(v);
		}
		else
		{
			for (auto it = cur->child.begin(); it != cur->child.end(); it++)
			{
				v.push_back(it->first);
				st.push({it->second,v});
				v.pop_back();
			}
		}
	}
	return ans;
}

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
	//vector<vector<int>> ans;
	TrieInt ti;

	WordDictionary wd;
	for (int index = 0; index < words.size(); index++)
	{
		wd.insert(words[index], index);
	}

	for (int index = 0; index < words.size(); index++)
	{
		/*
		left
		word: aabc
		0 aabc
		1 aab
		2 aa
		..
		lenght ""

		right
		word: aabc
		0 aabc
		1  abc
		2   bc
		..
		lenght ""
		*/
		string condidate = words[index];
		reverse(condidate.begin(), condidate.end());

		for (int j = 0; j <= words[index].size(); j++)
		{
			int secondIndex = -1;
			string rightStr = condidate.substr(j);
			if (isPalindrome(words[index] + rightStr))
			{
				secondIndex = wd.searchWord(rightStr);
				if (secondIndex != -1 && secondIndex != index)
				{
					ti.insert(vector<int>{ index,secondIndex });
					//ans.push_back({ index,secondIndex });
				}
			}
			//cout << "w+c :: "<< words[index] << "|" << rightStr <<  " [" << index << ", " << secondIndex << "]\n";

			secondIndex = -1;
			string leftStr = condidate.substr(0, j);
			if (isPalindrome(leftStr + words[index]))
			{
				secondIndex = wd.searchWord(leftStr);
				if (secondIndex != -1 && secondIndex != index)
				{
					ti.insert(vector<int>{ secondIndex, index });
					//ans.push_back({ secondIndex, index});
				}
			}
			//cout << "c+w :: " << leftStr << "|" << words[index] << " [" << secondIndex << ", " << index << "]\n";
		}
	}

	return ti.getSequnces();
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
