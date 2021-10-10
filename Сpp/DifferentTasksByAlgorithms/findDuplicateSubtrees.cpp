#include "findDuplicateSubtrees.h"

#include <stack>
#include <sstream>
#include <iostream>
std::string Solution::travel(std::unordered_map<std::string, std::vector<TreeNode*>>& mp, TreeNode* root)
{
	if (!root)
		return "";
	//string strL = "l" + travel(mp,root->left);
	//string strR = "r" + travel(mp,root->right);
	std::string ans = std::to_string(root->val) + "l" + travel(mp, root->left) + "r" + travel(mp, root->right);
	mp[ans].push_back(root);
	return ans;
}

std::vector<TreeNode*> Solution::findDuplicateSubtrees(TreeNode* root)
{
	std::unordered_map<std::string, std::vector<TreeNode*>> mpDublicate;
	//cout << travel(mpDublicate, root);
	travel(mpDublicate, root);
	std::vector<TreeNode*> ans;
	auto it = mpDublicate.begin();
	while (it != mpDublicate.end())
	{
		if (it->second.size() > 1)
			ans.push_back(it->second[0]);
		it++;
	}
	return ans;
}

std::string serialize(TreeNode* root) {
	std::string out = "";
	std::vector<TreeNode*> level({ root });
	std::vector<TreeNode*> nextLevel;
	while (level.size()) {
		for (int i = 0; i < level.size(); i++) {
			out += (level[i] ? std::to_string(level[i]->val) : "null") + " ";
			if (level[i]) nextLevel.push_back(level[i]->left);
			if (level[i]) nextLevel.push_back(level[i]->right);
		}
		level.clear();
		if (nextLevel.size()) {
			level = nextLevel;
			nextLevel.clear();
		}
	}
	return out;
}

TreeNode* deserialize(std::string data) {
	std::stringstream ss(data);
	std::string str;
	ss >> str;
	if (str == "null") return nullptr;
	TreeNode* head = new TreeNode(stoi(str));
	std::vector<TreeNode*> level({ head });
	std::vector<TreeNode*> nextLevel;
	while (level.size()) {
		for (int i = 0; i < level.size(); i++) {
			ss >> str;
			if (str != "null") {
				level[i]->left = new TreeNode(stoi(str));
				nextLevel.push_back(level[i]->left);
			}
			ss >> str;
			if (str != "null") {
				level[i]->right = new TreeNode(stoi(str));
				nextLevel.push_back(level[i]->right);
			}
		}
		level.clear();
		if (nextLevel.size()) {
			level = nextLevel;
			nextLevel.clear();
		}
	}
	return head;
}

void test(TreeNode* root)
{
	using std::cout;
	Solution s;
	std::vector<TreeNode*> ans = s.findDuplicateSubtrees(root);
	for (TreeNode* nood : ans)
	{
		std::cout << "[" << serialize(nood) << "]\n";
	}
	std::cout << "\n";
}



int main()
{
	test(deserialize("1 null"));
	test(deserialize("1 2 3 null null 4 5 null"));
	test(deserialize("1 2 3 4 null 2 4 null null 4 null"));
	test(deserialize("2 1 1 null"));
	test(deserialize("2 2 2 3 null 3 null"));
	test(deserialize("1 2 3 4 null 2 4 1 null 4 null 1 null null null 1 null"));
	test(deserialize("1 1 1 1 null null 1 null null null 1 null"));
	return 0;
}