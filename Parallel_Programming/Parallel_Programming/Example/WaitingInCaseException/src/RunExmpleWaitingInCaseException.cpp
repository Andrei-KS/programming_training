

#include "RunExmpleWaitingInCaseException.h"
#include <thread>
#include <random>
#include <iostream>

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new RunExmpleWaitingInCaseException();

namespace
{
	/**
	* a test structure that serves to demonstrate an example
	*/
	struct func
	{
		int& i;
		func(int& i_):i(i_){}
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

void RunExmpleWaitingInCaseException::excute()
{
	int someLocalState = 0;
	func myFunc(someLocalState);
	std::thread t(myFunc);
	try
	{
		doSomeThingInCurrentThread();
	}
	catch(...)
	{
		t.join();
		std::cout << "throw" << std::endl;
		throw;
	}
	t.join();
	std::cout << "not throw" << std::endl;
}
