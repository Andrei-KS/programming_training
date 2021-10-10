/*
Input:		Given an m x n board of charactersand a list of strings words.
Output:		return all words on the board.

Note:
Each word must be constructed from letters of sequentially adjacent cells,
where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once in a word.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <array>

using namespace std;

class Solution
{
    struct Node {
        bool isWord = false;
        string val = "";
        unordered_map<char, Node*> child = {};
    };

    class WordDictionary {
        Node* root;
    public:
        /** Initialization the data structure */
        WordDictionary():root(new Node()) {}

        /** Destroy the data structure */
        ~WordDictionary();

        void clear();

        /** Insert new a word to data structure */
        void insert(const string& word);

        /** Search word */
        bool searchWord(string word);

        bool searchPrefix(string prefix);

        void removeWord(string word);

        /** Get words from data structure */
        vector<string> getWords();

        
    };

    const array<int, 4> dx = { 1,-1,0,0 };
    const array<int, 4> dy = { 0,0,1,-1 };
    vector<bool> isValidPosition;
    WordDictionary wdAns;
    WordDictionary dict;

    void getWordFromBoard(vector<vector<char>>& board, int row, int col, string str = "");

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
};