

#include "ThreadGuard.h"

ParallelUtilities::ThreadGuard::ThreadGuard(std::thread& t)
	: itsThread(t)
{
}

ParallelUtilities::ThreadGuard::~ThreadGuard()
{
	if (itsThread.joinable())
	{
		itsThread.join();
	}
}