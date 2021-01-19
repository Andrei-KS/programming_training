/*
input:		the root of a binary tree
output:		return all duplicate subtrees

Note:
For each kind of duplicate subtrees, you only need to return the root node of any one of them.
Two trees are duplicate if they have the same structure with the same node values.

*/

#include <string>
#include <unordered_map>
#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    std::string travel(std::unordered_map<std::string, std::vector<TreeNode*>>& mp, TreeNode* root);

public:
    std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);
};