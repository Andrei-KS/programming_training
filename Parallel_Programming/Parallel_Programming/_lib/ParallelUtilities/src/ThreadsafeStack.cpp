

#include "ThreadsafeStack.h"

const char* ParallelUtilities::Empty_Stack::what() const throw()
{
	return "Error:\tStack is empty\n";
}
