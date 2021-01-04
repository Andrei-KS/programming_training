#include "MaxXORofTwoNumbersInArray.h"

#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

class Solution 
{
    class BinaryTrie {
        struct TrieNode
        {
            array<TrieNode*, 2> child = {};
        } *root;

        int maxHeight;

    public:
        /** Initialize data structure here. */
        BinaryTrie():root(new TrieNode()), maxHeight(sizeof(int)*8-1){}

        /** Destroy BinaryTrie */
        ~BinaryTrie() {
            vector<TrieNode*> level;
            level.push_back(root);
            while (!level.empty()) {
                vector<TrieNode*> nextLevel;
                for (int i = 0; i < level.size(); i++) {
                    auto it = level[i]->child.begin();
                    while (it != level[i]->child.end()) {
                        if(*it)nextLevel.push_back(*it);
                        it++;
                    }
                    delete level[i];
                    level[i] = nullptr;
                }
                level = nextLevel;
            }
        }

        /** Inserts a val into the BinaryTrie. */
        void insertTrieNode(int val)
        {
            TrieNode* cur = root;
            for(int i = maxHeight; i >= 0; i--)
            {
                int bit = (val >> i) & 1;
                if (!cur->child[bit])
                {
                    cur->child[bit] = new TrieNode();
                }
                cur = cur->child[bit];
            }
        }

        /**  */
        int findMaxXOR(int val)
        {
            TrieNode* cur = root;
            int ans = 0;
            for (int i = maxHeight; i >= 0; i--)
            {
                int bit = (val >> i) & 1;
                if (cur->child[!bit])
                {
                    ans |= (1 << i);
                    cur = cur->child[!bit];
                }
                else {
                    cur = cur->child[bit];
                }
            }
            return ans;
        }
    };

public:


    int findMaximumXOR(vector<int>& nums) 
    {
        BinaryTrie bt;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            bt.insertTrieNode(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            ans = max(ans, bt.findMaxXOR(nums[i]));
        }
        return ans;
    }
};


int main()
{
    vector<int> v = { 3,10,5,25,2,8 };
    Solution ob;
    cout << (ob.findMaximumXOR(v));
	return 0;
}