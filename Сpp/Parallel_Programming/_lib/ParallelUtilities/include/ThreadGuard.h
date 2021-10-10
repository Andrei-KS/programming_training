#ifndef __THREADGUARD_H__
#define __THREADGUARD_H__

#include <thread>
namespace ParallelUtilities
{
	/**
	* A class that implements RAII for a thread
	* When this object is creating it captures the reference of thread.
	* When this object is destroyed it called join`s function of captured thread.
	* @see RAII
	*/
	class ThreadGuard
	{
	public:
		/**
		* When this object is creating it captures the reference of thread
		* @param t - reference thread will be captured
		*/
		explicit ThreadGuard(std::thread& t);

		/**
		* When this object is destroyed it called join`s function of captured thread
		*/
		~ThreadGuard();

		ThreadGuard(ThreadGuard const&) = delete;
		ThreadGuard& operator=(ThreadGuard const&) = delete;

	private:
		/** captured reference of thread */
		std::thread& itsThread;

	};
}


#endif // !__THREADGUARD_H__