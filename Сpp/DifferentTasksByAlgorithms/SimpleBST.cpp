#include "SimpleBST.h"
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::pair;
using std::cout;

Node* SimpelBST::search_Implemetation(Node* root, int val)
{
	if (!root || root->val == val)
	{
		return root;
	}
	else if (root->val > val)
	{
		return search_Implemetation(root->left, val);
	}
	else
	{
		return search_Implemetation(root->right, val);
	}
}

Node* SimpelBST::insert_Implimentation(Node* root, int val)
{
	Node* newNode = new Node(val);
	if (!root)
	{
		_root = newNode;
		return newNode;
	}

	Node* curNode = root;
	while (true) {
		if (val < curNode->val)
		{
			if (curNode->left == NULL)
			{
				curNode->left = newNode;
				break;
			}
			else
			{
				curNode = curNode->left;
			}
		}
		else
		{
			if (curNode->right == NULL)
			{
				curNode->right = newNode;
				break;
			}
			else
			{
				curNode = curNode->right;
			}
		}
	}

	return root;
}

Node* SimpelBST::erase_Implemenattion(Node* root, int key)
{
	if (!root)
	{
		return nullptr;
	}

	if (root->val == key)
	{
		if (!root->right)
		{
			Node* left = root->left;
			delete root;
			return left;
		}
		else
		{
			Node* right = root->right;
			while (right->left)
			{
				right = right->left;
			}
			std::swap(root->val, right->val);
		}
	}
	root->left = erase_Implemenattion(root->left, key);
	root->right = erase_Implemenattion(root->right, key);
	return root;
}

void Test(vector<pair<string,int>> inputs)
{
	SimpelBST sBST;
	for (auto input : inputs)
	{
		if (input.first == "insert")
		{
			cout << sBST.insert(input.second) << "\n";
		}
		else if (input.first == "search")
		{
			cout << sBST.search(input.second) << "\n";
		}
		else if (input.first == "erase")
		{
			cout << sBST.erase(input.second) << "\n";
		}
		else
		{
			cout << input.first << " is not valid command\n";
		}
	}
	cout << "\n";
}

int main()
{
	Test(vector<pair<string, int>>({ {"insert",1},{"insert",-1},{"insert",2},{"search",-1},{"erase",2}, {"search",2},{"search",-2} }));
	Test(vector<pair<string, int>>({ {"insert",1},{"insert",1},{"insert",2},{"search",-1},{"erase",1}, {"search",2},{"search",-2} }));
	return 0;
}