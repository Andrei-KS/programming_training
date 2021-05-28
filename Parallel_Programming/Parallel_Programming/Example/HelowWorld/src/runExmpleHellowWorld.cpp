

#include "runExmpleHellowWorld.h"
#include <iostream>
#include <thread>

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new runExmpleHellowWorld();

namespace {
	void hello()
	{
		std::cout << "Hellow parallel world!\n" << std::endl;
	}
}

void runExmpleHellowWorld::excute()
{
	std::thread t(hello);
	t.join();
}
