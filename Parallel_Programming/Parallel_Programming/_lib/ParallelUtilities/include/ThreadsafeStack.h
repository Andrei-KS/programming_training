#ifndef __THREADSAFESTACK_H__
#define __THREADSAFESTACK_H__

#include <exception>
#include <memory>
#include <mutex>
#include <stack>

namespace ParallelUtilities
{
	/**
	* When the stack is empty and you need to get an element from it,
	* an exception(Empty_Stack) will be thrown
	*/
	struct Empty_Stack : std::exception
	{
		const char* what() const throw();
	};

	/**
	* A wrapper class that allows you to safely use the stack in a multithreaded programs
	* @see stack
	*/
	template<typename T>
	class ThreadsafeStack
	{
	public:
		/**
		*
		*/
		ThreadsafeStack() {}

		/**
		*
		*/
		ThreadsafeStack(const ThreadsafeStack& other)
		{
			std::lock_guard<std::mutex> lock(other.itsMutex);
			itsData = other.itsData;
		}

		/**
		*
		*/
		ThreadsafeStack& operator=(const ThreadsafeStack&) = delete;

		/**
		* Add a new item to the top of the stack
		* @param newValue - this item will be pushed to the top of the stack
		*/
		void push(T newValue)
		{
			std::lock_guard<std::mutex> lock(itsMutex);
			itsData.push(newValue);
		}

		/**
		* Returns the top value and pops it off the stack.
		* 1. Checks if the stack is empty before popping the value. If the stack is empty, throws an exception(Empty_Stack)
		* 2. Before modifying the stack, allocates memory for the return value
		* @return a pointer to the top value
		*/
		std::shared_ptr<T> pop()
		{
			std::lock_guard<std::mutex> lock(itsMutex);
			if (itsData.empty())
			{
				throw Empty_Stack();
			}
			std::shared_ptr<T> const res(std::make_shared<T>(itsData.top()));
			itsData.pop();
			return res;
		}

		/**
		* Returns the top value and pops it off the stack.
		* 1. Checks if the stack is empty before popping the value. If the stack is empty, throws an exception(Empty_Stack)
		* 2. Before modifying the stack, writes the top value to the passed reference
		* @param value - the top value will be written here
		*/
		void pop(T& value)
		{
			std::lock_guard<std::mutex> lock(itsMutex);
			if (itsData.empty())
			{
				throw Empty_Stack();
			}
			value = itsData.top();
			itsData.pop();
		}

		/**
		* Checks the stack is empty
		* @return true if stack is empty, false if otherwise
		*/
		bool empty() const
		{
			std::lock_guard<std::mutex> lock(itsMutex);
			return itsData.empty();
		}

	private:
		/**  */
		std::stack<T> itsData;
		/**  */
		mutable std::mutex itsMutex;
	};
}

#endif // !__THREADSAFESTACK_H__