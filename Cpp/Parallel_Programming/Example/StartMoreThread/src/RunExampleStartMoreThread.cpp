

#include "RunExampleStartMoreThread.h"
#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new RunExampleStartMoreThread();

namespace
{
	/**
	* a Test function that serves to demonstrate an example
	* @param id - id of the running thread 
	*/
	void doWork(int id)
	{
		std::cout << "thread is " << id << std::endl;
	}
}

void RunExampleStartMoreThread::excute()
{
	std::vector<std::thread> threads;
	for (size_t i = 0; i < 20; i++)
	{
		threads.push_back(std::thread(doWork, i));
	}
	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}
