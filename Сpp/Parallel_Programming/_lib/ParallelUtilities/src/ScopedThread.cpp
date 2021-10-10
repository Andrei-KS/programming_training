

#include "ScopedThread.h"

ParallelUtilities::ScopedThread::ScopedThread(std::thread t)
	: itsThread(std::move(t))
{
	if (!itsThread.joinable())
	{
		throw std::logic_error("No thread");
	}
}

ParallelUtilities::ScopedThread::~ScopedThread()
{
	itsThread.join();
}
