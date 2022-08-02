#ifndef __SCOPEDTHREAD_H__
#define __SCOPEDTHREAD_H__

#include <thread>
namespace ParallelUtilities
{
	/**
	* A class that implements RAII for a thread
	* When this object is creating it captures the thread.
	* When this object is destroyed it called join`s function of captured thread.
	* @see RAII
	*/
	class ScopedThread
	{
	public:
		/**
		* When this object is creating it captures the thread
		* @param t - reference thread will be captured
		*/
		explicit ScopedThread(std::thread t);

		/**
		* When this object is destroyed it called join`s function of captured thread
		*/
		~ScopedThread();

		ScopedThread(ScopedThread const&) = delete;
		ScopedThread& operator=(ScopedThread const&) = delete;

	private:
		/** captured thread */
		std::thread itsThread;
	};
}
#endif // !__SCOPEDTHREAD_H__