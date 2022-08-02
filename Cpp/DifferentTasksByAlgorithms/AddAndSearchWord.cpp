#include "AddAndSearchWord.h"

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class WordDictionary {
    struct TrieNode {
        bool isWord = false;
        unordered_map<char, TrieNode*> child;
    } *root;

public:
    /** Initialize your data structure here. */
    WordDictionary() :root(new TrieNode) {}

    /** Destroy WordDictionary */
    ~WordDictionary(){
        vector<TrieNode*> level;
        level.push_back(root);
        while(!level.empty()){
            vector<TrieNode*> nextLevel;
            for(int i = 0; i < level.size(); i++){
                auto it = level[i]->child.begin();
                while(it != level[i]->child.end()){
                    nextLevel.push_back(it->second);
                    it++;
                }
                delete level[i];
                level[i] = nullptr;
            }
            level = nextLevel;
        }
    }

    /** Adds word to the data structure */
    void addWord(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i++) {
            if (cur->child.find(word[i]) == cur->child.end()) {
                cur->child[word[i]] = new TrieNode();
            }
            cur = cur->child[word[i]];
        }
        cur->isWord = true;
    }

    /** 
    Returns true if there is any string in the data structure
    that matches word or false otherwise.word may contain dots '.' where dots
    can be matched with any letter.
    */
    bool search(string word) {
        stack<pair<TrieNode*, int>> nextCur;
        nextCur.push({ root,0 });
        while (!nextCur.empty()) {
            TrieNode* cur = nextCur.top().first;
            int i = nextCur.top().second;
            nextCur.pop();
            if (i < word.size()) {
                if (word[i] == '.') {
                    auto it = cur->child.begin();
                    while (it != cur->child.end()) {
                        nextCur.push({ it->second,i + 1 });
                        it++;
                    }
                }
                else if (cur->child.find(word[i]) != cur->child.end()) {
                    nextCur.push({ cur->child[word[i]],i + 1 });
                }
            }
            else {
                if (cur->isWord) {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
* first vector<string> is command
* second vector<string> is data
*/
void test(pair<vector<string>, vector<string>>& exmp)
{
    if (exmp.first.size() != exmp.second.size()) {
        cout << "exmp is not valid, first.size()!=second.size()\n";
        return;
    }

    WordDictionary* wd = nullptr;
    for (int i = 0; i < exmp.first.size(); i++) {
        if (exmp.first[i] == "WordDictionary") {
            if (wd) {
                delete wd;
            }
            wd = new WordDictionary();
        }
        else if (exmp.first[i] == "addWord") {
            wd->addWord(exmp.second[i]);
        }
        else if (exmp.first[i] == "search") {
            cout << (wd->search(exmp.second[i]) ? "true" : "false") << "\n";
        }
        else {
            cout << "exmp is not valid, command - " << exmp.first[i] << " - is not valid\n";
            return;
        }
    }
}
int main() {
    test(pair<vector<string>, vector<string>>{ {"WordDictionary","addWord","addWord","addWord","search","search","search","search"},
         {"","bad","dad","mad","pad","bad",".ad","b.."} });
    test(pair<vector<string>, vector<string>>{ {"WordDictionary", "addWord", "addWord", "addWord", "search", "search", "search", "search"},
        { "","bad","dad","mad","pad","bad",".ad","..." } });
    return 0;
}


