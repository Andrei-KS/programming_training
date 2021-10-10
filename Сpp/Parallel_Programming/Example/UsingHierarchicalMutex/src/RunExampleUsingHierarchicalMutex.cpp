

#include "RunExampleUsingHierarchicalMutex.h"
#include "HierarchicalMutex.h"
#include "ScopedThread.h"
#include <iostream>

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new RunExampleUsingHierarchicalMutex();

namespace
{
	ParallelUtilities::HierarchicalMutex highLevelMutex(100);
	ParallelUtilities::HierarchicalMutex lowLevelMutex(50);
	
	int doLowLevelStuff()
	{
		int ret = 5;
		for (size_t i = 0; i < 10; i++)
		{
			ret += ret;
		}
		return ret;
	}

	int lowLevelFunc()
	{
		std::lock_guard<ParallelUtilities::HierarchicalMutex> lk(lowLevelMutex);
		return doLowLevelStuff();
	}

	void highLevelStuff(int initParam)
	{
		int ret = initParam;
		for (size_t i = 0; i < 10; i++)
		{
			ret += 5;
		}
	}

	void highLevelFunc()
	{
		std::lock_guard<ParallelUtilities::HierarchicalMutex> lk(highLevelMutex);
		highLevelStuff(lowLevelFunc());
	}

	void threadA()
	{
		highLevelFunc();
	}

	ParallelUtilities::HierarchicalMutex otherMutex(1);

	void doOtherStuff()
	{
		int ret = 5;
		for (size_t i = 0; i < 10; i++)
		{
			ret += ret;
		}
	}

	void otherStuff()
	{
		highLevelFunc();
		doOtherStuff();
	}

	void threadB()
	{
		try
		{
			std::lock_guard<ParallelUtilities::HierarchicalMutex> lk(otherMutex);
			otherStuff();
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void RunExampleUsingHierarchicalMutex::excute()
{
	ParallelUtilities::ScopedThread(std::thread(threadA));
	ParallelUtilities::ScopedThread(std::thread(threadB));
}