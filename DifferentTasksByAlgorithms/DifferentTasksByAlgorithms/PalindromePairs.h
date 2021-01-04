/*
input:      a list of unique words
output:     all the pairs of the distinct indices (i, j) in the given list, so that the concatenation of the two words words[i] + words[j] is a palindrome.
*/

#include <unordered_map>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
    struct NodeInt {
        unordered_map<int, NodeInt*> child = {};
    };

    class TrieInt {
        NodeInt* root;
    public:
        /** Initialization the data structure */
        TrieInt():root(new NodeInt){}

        /** Destroy the data structure */
        ~TrieInt();

        void clear();

        /** Insert new a sequence ints to data structure */
        void insert(vector<int>& seq);

        /** Get sequence ints from data structure */
        vector<vector<int>> getSequnces();
    };

	struct Node {
		int val = -1;
        unordered_map<char, Node*> child = {};
	};

    class WordDictionary {
        Node* root;
    public:
        /** Initialization the data structure */
        WordDictionary() :root(new Node()) {}

        /** Destroy the data structure */
        ~WordDictionary();

        void clear();

        /** Insert new a word to data structure */
        void insert(const string& word, int index);

        /** Search word */
        int searchWord(string word);

        bool searchPrefix(string prefix);

        void removeWord(string word);
    };

    bool isPalindrome(const string& str);

public:
    vector<vector<int>> palindromePairs(vector<string>& words);
};