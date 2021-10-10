

#include "RunExampleLockingMoreMutexes.h"
#include <mutex>
#include <iostream>
#include <thread>
#include "ScopedThread.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new RunExampleLockingMoreMutexes();

namespace
{
	std::mutex stdOut;
	class X
	{
	private:
		int itsObject;
		std::mutex itsMutex;
	public:
		X(int const& o) :itsObject(o) {}
		friend void swap(X& lhs, X& rhs)
		{
			if (&lhs == &rhs)
			{
				return;
			}
			std::lock(lhs.itsMutex, rhs.itsMutex);
			std::lock_guard<std::mutex> lock_l(lhs.itsMutex, std::adopt_lock);
			std::lock_guard<std::mutex> lock_r(rhs.itsMutex, std::adopt_lock);
			std::swap(lhs.itsObject, rhs.itsObject);
		}
		void printObject()
		{
			std::lock_guard<std::mutex> lg(itsMutex);
			std::cout << "object is " << itsObject;
		}
	};

	void swapingFn(X& lhs, X& rhs, size_t numberSwap)
	{
		for (size_t i = 0; i < numberSwap; i++)
		{
			swap(lhs, rhs);
		}
	}
	void printFn(X& lhs, X& rhs, size_t numberPrint, std::string const& name)
	{
		for (size_t i = 0; i < numberPrint; i++)
		{
			std::lock_guard<std::mutex> lg(stdOut);
			std::cout << name << "\t";
			lhs.printObject();
			std::cout << "\t";
			rhs.printObject();
			std::cout << std::endl;
		}
	}
}

void RunExampleLockingMoreMutexes::excute()
{
	X x1(1), x2(2), x3(3), x4(4);
	ParallelUtilities::ScopedThread print12(std::thread(printFn, std::ref(x1), std::ref(x2), 1000, "print12:"));
	ParallelUtilities::ScopedThread swap12(std::thread(swapingFn, std::ref(x1), std::ref(x2), 99));
	ParallelUtilities::ScopedThread swap13(std::thread(swapingFn, std::ref(x1), std::ref(x3), 99));
	ParallelUtilities::ScopedThread swap14(std::thread(swapingFn, std::ref(x1), std::ref(x4), 99));
	ParallelUtilities::ScopedThread swap23(std::thread(swapingFn, std::ref(x2), std::ref(x3), 99));
	ParallelUtilities::ScopedThread print34(std::thread(printFn, std::ref(x3), std::ref(x4), 1000, "print34:"));
	ParallelUtilities::ScopedThread swap24(std::thread(swapingFn, std::ref(x2), std::ref(x4), 99));
	ParallelUtilities::ScopedThread swap34(std::thread(swapingFn, std::ref(x3), std::ref(x4), 99));
}
