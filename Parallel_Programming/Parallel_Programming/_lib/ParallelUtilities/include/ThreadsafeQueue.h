#ifndef __THREADSAFEQUEUE_H__
#define __THREADSAFEQUEUE_H__

#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>

namespace ParallelUtilities
{
	/**
	 * A wrapper class that allows you to safely use the queue in a multithreaded programs
	 * @see queue
	 */
	template<typename T>
	class ThreadsafeQueue
	{
	public:
		/**
		 * 
		 */
		ThreadsafeQueue()
		{}
		
		/**
		 * 
		 */
		ThreadsafeQueue(const ThreadsafeQueue& otherQueue)
		{
			std::lock_guard<std::mutex> lk(itsMutex);
			itsQueue = otherQueue.itsQueue;
		}
		
		/**
		 * 
		 */
		ThreadsafeQueue& operator=(const ThreadsafeQueue&) = delete;

		/**
		 * push a new value at the end of the queue
		 * @param newValue - this value will be placed at the end of the queue
		 */
		void push(T newValue)
		{
			std::lock_guard<std::mutex> lk(itsMutex);
			itsQueue.push(newValue);
			itsCondition.notify_one();
		}
		
		/**
		 * Tries to retrieve a value from the queue, but immediately resumes control (indicating an error) if there was nothing in the queue
		 * @param value - The retrieved value will be written to this variable
		 */
		bool try_pop(T& value)
		{
			std::lock_guard<std::mutex> lk(itsMutex);
			if (itsQueue.empty())
			{
				return false;
			}
			value = itsQueue.front();
			itsQueue.pop();
			return true;
		}
		
		/**
		 * Tries to retrieve a value from the queue, but immediately resumes control (indicating an error) if there was nothing in the queue
		 * @return pointer to value retrieving from the queue 
		 */
		std::shared_ptr<T> try_pop()
		{
			std::lock_guard<std::mutex> lk(itsMutex);
			if (itsQueue.empty())
			{
				return std::shared_ptr<T>();
			}
			std::shared_ptr<T> res(std::make_shared<T>(itsQueue.front()));
			itsQueue.pop();
			return res;
		}

		/**
		 * Waits until new data appears. Then it fetches from the queue
		 * @param value - The retrieved value will be written to this variable
		 */
		void wait_and_pop(T& value)
		{
			std::unique_lock<std::mutex> lk(itsMutex);
			itsCondition.wait(lk, [this] {return !itsQueue.empty(); });
			value = itsQueue.front();
			itsQueue.pop();
		}
		
		/**
		 * Waits until new data appears. Then it fetches from the queue
		 * @return pointer to value retrieving from the queue
		 */
		std::shared_ptr<T> wait_and_pop()
		{
			std::unique_lock<std::mutex> lk(itsMutex);
			itsCondition.wait(lk, [this] {return !itsQueue.empty(); });
			std::shared_ptr<T> res(std::make_shared<T>(itsQueue.front()));
			itsQueue.pop();
			return res;
		}

		/**
		 * checks if the queue is empty or not
		 * @return true if queue is empty, false if otherwise
		 */
		bool empty() const
		{
			std::lock_guard<std::mutex> lk(itsMutex);
			return itsQueue.empty();
		}

	private:
		/**  */
		mutable std::mutex itsMutex;

		/**  */
		std::queue<T> itsQueue;

		/**  */
		std::condition_variable itsCondition;
	};
}
#endif // !__THREADSAFEQUEUE_H__