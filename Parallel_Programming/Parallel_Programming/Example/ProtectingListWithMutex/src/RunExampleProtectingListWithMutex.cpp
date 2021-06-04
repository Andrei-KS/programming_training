

#include "RunExampleProtectingListWithMutex.h"
#include <list>
#include <mutex>
#include <algorithm>

#include <iostream>
#include <vector>
#include <functional>

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new RunExampleProtectingListWithMutex();

namespace {
	std::list<int> someList;
	std::mutex someMutex;
	
	void add_to_list(int newValue)
	{
		std::lock_guard<std::mutex> guard(someMutex);
		someList.push_back(newValue);
#ifdef DEBUG_BUILD
		std::cout << "add_to_list( " << newValue << " )" << std::endl;
#endif
	}

	bool listContains(int valueToFind)
	{
		std::lock_guard<std::mutex> guard(someMutex);
#ifdef DEBUG_BUILD
		std::cout << "listContains( " << valueToFind << " )" << std::endl;
#endif
		return std::find(someList.begin(), someList.end(), valueToFind) != someList.end();
	}

	void show_result(int valueToFind)
	{
		if (listContains(valueToFind))
		{
			std::cout << valueToFind << " is found "<< std::endl;
		}
		else
		{
			std::cout << valueToFind << " is not found " << std::endl;
		}
	}
}




void RunExampleProtectingListWithMutex::excute()
{
	const size_t numThreads = 100;
	std::vector<std::thread> threads(numThreads - 1);
	for (size_t i = 0; i < (numThreads - 1); i++)
	{
		if (i % 2)
		{
			threads[i] = std::thread(add_to_list,i);
		}
		else
		{
			threads[i] = std::thread(show_result,(i-1));
		}
	}
	show_result((numThreads - 1) - 1);
	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
	std::cout << " --- End --- " << std::endl;
}
