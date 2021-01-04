#include "ReplaceWords.h"

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
    class Trie {
        struct TrieNode {
            bool isWord = false;
            unordered_map<char, TrieNode*> child;
        } *root;

    public:
        /** Initialize data structure here. */
        Trie() :root(new TrieNode()) {}

        /** Destroy Trie */
        ~Trie() {
            vector<TrieNode*> level;
            level.push_back(root);
            while (!level.empty()) {
                vector<TrieNode*> nextLevel;
                for (int i = 0; i < level.size(); i++) {
                    auto it = level[i]->child.begin();
                    while (it != level[i]->child.end()) {
                        nextLevel.push_back(it->second);
                        it++;
                    }
                    delete level[i];
                    level[i] = nullptr;
                }
                level = nextLevel;
            }
        }

        /** Inserts a word into the trie. */
        void insert(string word) {
            TrieNode* cur = root;
            for (int i = 0; i < word.size(); i++) {
                if (cur->child.find(word[i]) == cur->child.end()) {
                    cur->child[word[i]] = new TrieNode();
                }
                cur = cur->child[word[i]];
            }
            cur->isWord = true;
            //cout << word << "\n";
        }

        /** Returns root. */
        string searchFirstRoot(string word) {
            string ans = "";
            TrieNode* cur = root;
            for (int i = 0; i < word.size(); i++) {
                //cout << word << " -> " << ans << "\n";
                if (cur->child.find(word[i]) == cur->child.end()) {
                    return "";
                }
                ans += word[i];
                cur = cur->child[word[i]];
                if (cur->isWord) {
                    //cout << word << " |-> " << ans << "\n";
                    return ans;
                }
            }
            return ans;
        }
    };

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (int i = 0; i < dictionary.size(); i++) {
            trie.insert(dictionary[i]);
        }
        int startWord = 0;
        int curChar = 0;
        while (curChar < sentence.size()) {
            if (sentence[curChar] != ' ')
            {
                string word = "";
                while (sentence[curChar] != ' ' && sentence[curChar] != '\0') {
                    word += sentence[curChar++];
                }
                string root = trie.searchFirstRoot(word);
                //cout << "trie.searchFirstRoot(" << word << ") => " << root << "\n";
                if (root != "") {
                    for (int i = 0; i < root.size(); i++) {
                        sentence[startWord++] = root[i];
                    }
                }
                else {
                    for (int i = 0; i < word.size(); i++) {
                        sentence[startWord++] = word[i];
                    }
                }
                sentence[startWord++] = sentence[curChar];

            }
            curChar++;
        }
        sentence.resize(startWord-1);
        return sentence;
    }
};

void diffAnswer(pair<vector<string>, string>& exmp)
{
    Solution s;
    cout << exmp.second << "\n" << s.replaceWords(exmp.first, exmp.second) << "\n";
}

int main() {
    Solution s;
    diffAnswer(pair<vector<string>, string>{ {"cat","bat","rat"}, "the cattle was rattled by the battery" });
    diffAnswer(pair<vector<string>, string>{ {"a", "b", "c"}, "aadsfasf absbs bbab cadsfafs" });
    diffAnswer(pair<vector<string>, string>{ {"a", "b", "c"}, "aadsfasf absbs bbab cadsfafs" });
    diffAnswer(pair<vector<string>, string>{ {"a", "aa", "aaa", "aaaa"}, "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa" });
    diffAnswer(pair<vector<string>, string>{ {"catt", "cat", "bat", "rat"}, "the cattle was rattled by the battery" });
    diffAnswer(pair<vector<string>, string>{ {"ac", "ab"}, "it is abnormal that this solution is accepted" });
    diffAnswer(pair<vector<string>, string>{ {"a", "b", "c"}, "aadsfasf   absbs   bbab  cadsfafs" });
    return 0;
}