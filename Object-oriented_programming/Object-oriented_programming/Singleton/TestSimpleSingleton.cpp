#include "TestSimpleSingleton.h"
#include <cassert>

void TestSimpleSingleton::TestCreatSimpleSingleton() throw(std::exception)
{
	SimpleSingleton* s1 = SimpleSingleton::instance();
	SimpleSingleton* s2 = SimpleSingleton::instance();
	assert(s1 == s2);
}
