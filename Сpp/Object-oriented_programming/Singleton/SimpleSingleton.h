#ifndef __SIMPLE_SINGLETON__
#define __SIMPLE_SINGLETON__

#include <memory>

class SimpleSingleton
{
	static SimpleSingleton* theInstance;
	SimpleSingleton() {};
public:
	static SimpleSingleton* instance();
};

#endif // __SIMPLE_SINGLETON__