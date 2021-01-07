/*
Implement the Simpel Binary Search Tree(BST) class for int:
	-SimpelBST() Initializes the object.
	-Node* insert(key) Adds new Node to the data structure, it can be matched later. Return pointer to root
	-Node* search(key) Returns Node if there is node with the key or nullptr if is not key
	-Node* erase(key) Delete node if there is node with the this key. Return pointer to root
*/
#include <algorithm>


struct Node {
	int val;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(int value) :val(value), left(nullptr), right(nullptr) {}
	Node(int value, Node* left, Node* right) :val(value), left(left), right(right) {}
};

class SimpelBST
{
	Node* _root;

protected:
	Node* search_Implemetation(Node* root, int val);

	Node* insert_Implimentation(Node* root, int val);

	Node* erase_Implemenattion(Node* root, int key);
	
public:
	SimpelBST() :_root(nullptr) {}

	Node* insert(int key)
	{
		return insert_Implimentation(_root, key);
	}

	Node* search(int key)
	{
		return search_Implemetation(_root, key);
	}

	Node* erase(int key)
	{
		return erase_Implemenattion(_root, key);
	}
};