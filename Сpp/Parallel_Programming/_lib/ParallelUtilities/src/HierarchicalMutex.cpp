

#include "HierarchicalMutex.h"

thread_local unsigned long ParallelUtilities::HierarchicalMutex::thisThreadHierarchyValue(ULLONG_MAX);

ParallelUtilities::HierarchicalMutex::HierarchicalMutex(unsigned long value)
	: itsHierarchyValue(value)
	, itsPreviousValue(0)
{
}

void ParallelUtilities::HierarchicalMutex::lock()
{
	checkForHierarchyViolation();
	itsInternalMutex.lock();
	updateHierarchyValue();
}

void ParallelUtilities::HierarchicalMutex::unlock()
{
	thisThreadHierarchyValue = itsPreviousValue;
	itsInternalMutex.unlock();
}

bool ParallelUtilities::HierarchicalMutex::try_lock()
{
	checkForHierarchyViolation();
	if (!itsInternalMutex.try_lock())
	{
		return false;
	}
	updateHierarchyValue();
	return true;
}

void ParallelUtilities::HierarchicalMutex::checkForHierarchyViolation()
{
	if (thisThreadHierarchyValue <= itsHierarchyValue)
	{
		throw std::logic_error("mutex hierarchy violated");
	}
}

void ParallelUtilities::HierarchicalMutex::updateHierarchyValue()
{
	itsPreviousValue = thisThreadHierarchyValue;
	thisThreadHierarchyValue = itsHierarchyValue;
}