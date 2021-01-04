#include "WordSearch_v2.h"

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

void Solution::WordDictionary::insert(const string& word)
{
	Node* curNode = this->root;
	for (int indexLetter = 0; indexLetter < word.size(); indexLetter++)
	{
		if (curNode->child.find(word[indexLetter]) == curNode->child.end())
		{
			curNode->child[word[indexLetter]] = new Node;
			curNode->child[word[indexLetter]]->val = curNode->val + word[indexLetter];
		}
		curNode = curNode->child[word[indexLetter]];
	}
	curNode->isWord = true;
}

bool Solution::WordDictionary::searchWord(string word)
{
	Node* curNode = this->root;
	for (int indexLetter = 0; indexLetter < word.size(); indexLetter++)
	{
		if (curNode->child.find(word[indexLetter]) == curNode->child.end())
		{
			return false;
		}
		curNode = curNode->child[word[indexLetter]];
	}
	return curNode->isWord;
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
	stack<Node*> st;
	st.push(root);
	for (int indexLetter = 0; indexLetter < word.size(); indexLetter++)
	{
		if (st.top()->child.find(word[indexLetter]) == st.top()->child.end())
		{
			return;
		}
		st.push(st.top()->child[word[indexLetter]]);
	}

	if (st.top()->isWord)
	{
		st.top()->isWord = false;
		while (st.top()->child.empty() && !st.top()->isWord && st.top() != root)
		{
			char simbol = st.top()->val[st.top()->val.size() - 1];
			delete st.top();
			st.pop();
			st.top()->child.erase(simbol);
		}
	}
}

vector<string> Solution::WordDictionary::getWords()
{
	vector<string> ans;
	stack<Node*> st;
	st.push(this->root);
	while (!st.empty())
	{
		Node* cur = st.top();
		st.pop();
		if (cur->isWord)
		{
			ans.push_back(cur->val);
		}
		for (auto it = cur->child.begin(); it != cur->child.end(); it++)
		{
			st.push(it->second);
		}
	}
	return ans;
}

void Solution::getWordFromBoard(vector<vector<char>>& board, int row, int col, string str)
{
	if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || !isValidPosition[row * board[0].size() + col])
	{
		return;
	}
	str += board[row][col];
	if (dict.searchPrefix(str))
	{
		if (dict.searchWord(str))
		{
			dict.removeWord(str);
			wdAns.insert(str);
		}
		isValidPosition[row * board[0].size() + col] = false;
		for (int i = 0; i < dx.size(); i++)
		{
			getWordFromBoard(board, row + dx[i], col + dy[i], str);
		}
		isValidPosition[row * board[0].size() + col] = true;
	}
}

vector<string> Solution::findWords(vector<vector<char>>& board, vector<string>& words)
{
	isValidPosition = vector<bool>(board.size() * board[0].size(), true);
	dict.clear();
	for (string word : words) {
		dict.insert(word);
	}

	wdAns.clear();
	for (int row = 0; row < board.size(); row++)
	{
		for (int col = 0; col < board[0].size(); col++)
		{
			getWordFromBoard(board, row, col);
		}
	}

	return wdAns.getWords();
}


void test(vector<vector<char>>& board, vector<string>& words)
{
	Solution s;
	vector<string> ans = s.findWords(board, words);
	for (string word : ans)
	{
		cout << word << " ";
	}
	cout << "\n";

}

int main()
{
	test(vector<vector<char>>{ {'o', 'a', 'a', 'n'}, { 'e', 't', 'a', 'e' }, { 'i', 'h', 'k', 'r' }, { 'i', 'f', 'l', 'v' } },
		vector<string>{ "oath", "pea", "eat", "rain" });
	return 0;
}

