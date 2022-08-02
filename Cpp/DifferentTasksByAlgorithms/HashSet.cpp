#include "HashSet.h"
#include <iostream>

#include <vector>
#include <string>

MyHashSet::MyHashSet()
{
	arr.fill(nullptr);
}

MyHashSet::~MyHashSet()
{
	for (auto el : arr)
	{
		Node* cur = el;
		while (cur)
		{
			Node* next = cur->next;
			delete cur;
			cur = next;
		}
	}
}

void MyHashSet::add(int key)
{
	Node* cur = arr[hashFunction(key)];
	if (cur)
	{
		Node* prev = nullptr;
		while (cur)
		{
			if (cur->val == key)
				return;
			prev = cur;
			cur = cur->next;
		}
		prev->next = new Node(key);
	}
	else
	{
		arr[hashFunction(key)] = new Node(key);
	}
}

void MyHashSet::remove(int key)
{
	Node* cur = arr[hashFunction(key)];
	Node* prev = nullptr;
	while (cur)
	{
		if (cur->val == key)
		{
			if (prev)
			{
				prev->next = cur->next;
			}
			else
			{
				arr[hashFunction(key)] = cur->next;
			}
			delete cur;
			break;
		}
		prev = cur;
		cur = cur->next;
	}
}

bool MyHashSet::contains(int key)
{
	Node* cur = arr[hashFunction(key)];
	while (cur)
	{
		if (cur->val == key)
			return true;
		cur = cur->next;
	}
	return false;
}

void test(std::vector<std::pair<std::string, int>>& inputs)
{
	using std::cout;

	MyHashSet* mhs = new MyHashSet();
	for (auto input : inputs)
	{
		if (input.first == "add")
		{
			mhs->add(input.second);
		}
		else if (input.first == "contains")
		{
			cout << mhs->contains(input.second) << "\n";
		}
		else if (input.first == "remove")
		{
			mhs->remove(input.second);
		}
		else
		{
			cout << input.first << " is not valid command\n";
		}
	}
	cout << "\n";
	delete mhs;
}

int main()
{
	test(std::vector<std::pair<std::string, int>>({ {"contains",1},{"add",1},{"add",1},{"contains",1},{"remove",1},{"contains",1} }));
	test(std::vector<std::pair<std::string, int>>({ {"contains",1},{"add",1},{"contains",1},{"remove",1},{"contains",1}}));
	test(std::vector<std::pair<std::string, int>>({ {"contains",1},{"add",1},{"add",2} ,{"contains",1},{"contains",2} ,{"remove",1},{"contains",1},{"contains",2} }));
	test(std::vector<std::pair<std::string, int>>({ {"contains",1},{"add",1},{"add",1} ,{"contains",1},{"contains",2} ,{"remove",1},{"contains",1},{"contains",2} }));
	test(std::vector<std::pair<std::string, int>>({ {"contains",1},{"add",1},{"add",1} ,{"contains",1},{"contains",2} ,{"remove",1},{"remove",1} ,{"contains",1},{"contains",2} }));
	return 0;
}


