#include "SimpleBST.h"
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::pair;
using std::cout;

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