#include "SimpleSingleton.h"

SimpleSingleton* SimpleSingleton::theInstance = nullptr;

SimpleSingleton* SimpleSingleton::instance()
{
	if (theInstance == nullptr)
	{
		theInstance = new SimpleSingleton();
	}
	return theInstance;
}
