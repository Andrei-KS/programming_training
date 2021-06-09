#ifndef __HIERARCHICALMUTEX_H__
#define __HIERARCHICALMUTEX_H__

#include <mutex>

namespace ParallelUtilities
{
	/**
	* HierarchicalMutex implements the idea of a fixed order of capture of mutexes.
	* throws an exception when trying to capture a mutex higher in the hierarchy than the one captured
	* @see mutex, std::lock, std::thread 
	*/
	class HierarchicalMutex
	{
	public:
		/**
		* a mutex with a given ordinal number is constructed.
		* @param value - defines the ordinal in the mutex hierarchy
		*/
		explicit HierarchicalMutex(unsigned long value);

		/**
		* If the number of the captured mutex is less, then it will be captured, otherwise an exception will be thrown.
		* When a new mutex is captured in this thread, it will change the value of thisThreadHierarchyValue
		* to the new value of the mutex, and write the old value to itsPreviousValue 
		*/
		void lock();

		/**
		* 
		*/
		void unlock();

		/**
		*/
		bool try_lock();

	private:
		/** Mutex to be captured  */
		std::mutex itsInternalMutex;
		/** Ordinal number in the mutex hierarchy  */
		unsigned long const itsHierarchyValue;
		/**  */
		unsigned itsPreviousValue;
		/**  */
		static thread_local unsigned long thisThreadHierarchyValue;

		/**
		*/
		void checkForHierarchyViolation();

		/**
		*/
		void updateHierarchyValue();
	};
}

#endif // !__HIERARCHICALMUTEX_H__