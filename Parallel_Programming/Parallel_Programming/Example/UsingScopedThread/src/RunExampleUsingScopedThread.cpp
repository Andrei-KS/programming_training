

#include "RunExampleUsingScopedThread.h"
#include <random>
#include "ScopedThread.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new RunExampleUsingScopedThread();

namespace
{
	/**
	* a test structure that serves to demonstrate an example
	*/
	struct func
	{
		int& i;
		func(int& i_) :i(i_) {}
		void operator()()
		{
			for (unsigned j = 0; j < 1000000; j++)
			{
				i = i % 100 + 1;
			}
		}
	};

	/**
	* a test function that serves to demonstrate an example
	*/
	void doSomeThingInCurrentThread()
	{
		std::random_device rd;

		int i = 0;
		for (unsigned j = 0; j < 1000000; j++)
		{
			i = i % 100 + 1;
		}
		if (!(rd() % 4))
		{
			throw("error exit");
		}
	}
}

void RunExampleUsingScopedThread::excute()
{
	int someLocalState = 0;
	ParallelUtilities::ScopedThread st(std::thread((func(someLocalState))));
	doSomeThingInCurrentThread();
}
