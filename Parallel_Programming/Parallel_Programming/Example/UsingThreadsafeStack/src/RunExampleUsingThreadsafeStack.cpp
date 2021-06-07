

#include "RunExampleUsingThreadsafeStack.h"
#include "ThreadsafeStack.h"
#include <vector>
#include <iostream>
#include "ScopedThread.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new RunExampleUsingThreadsafeStack();

namespace
{
	std::mutex stdOut;
	template<typename T>
	void pushFn(ParallelUtilities::ThreadsafeStack<T>& tss, const T& element, size_t countOfPushCall)
	{
		for (size_t i = 0; i < countOfPushCall; i++)
		{
			tss.push(element);
			std::lock_guard<std::mutex> lg(stdOut);
			std::cout << "push : " << element << std::endl;
		}
	}

	template<typename T>
	void popFn(ParallelUtilities::ThreadsafeStack<T>& tss, size_t countOfPopCall)
	{
		for (size_t i = 0; i < countOfPopCall; i++)
		{
			int element = 0;
			tss.pop(element);
			std::lock_guard<std::mutex> lg(stdOut);
			std::cout << "Pop : " << element << std::endl;
		}
	}
}

void RunExampleUsingThreadsafeStack::excute()
{
	callPopForEmptyStack();
	workOfMultipleThreads(5);
}

void RunExampleUsingThreadsafeStack::callPopForEmptyStack()
{
	ParallelUtilities::ThreadsafeStack<int> tss;
	try
	{
		tss.pop();
	}
	catch (std::exception& e)
	{
		std::cout << "Catch :\t" << e.what() << std::endl;
	}
}

void RunExampleUsingThreadsafeStack::workOfMultipleThreads(size_t numberThread)
{
	ParallelUtilities::ThreadsafeStack<int> tss;
	
	for (size_t i = 0; i < numberThread; i++)
	{
		ParallelUtilities::ScopedThread st(std::thread(pushFn<int>, std::ref(tss), i, 100));
	}
	for (size_t i = 0; i < numberThread; i++)
	{
		ParallelUtilities::ScopedThread st(std::thread(popFn<int>, std::ref(tss), 100));
	}
}