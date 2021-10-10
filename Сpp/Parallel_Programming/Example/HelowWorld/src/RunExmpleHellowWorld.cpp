

#include "RunExmpleHellowWorld.h"
#include <iostream>
#include <thread>

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new RunExmpleHellowWorld();

namespace {
	void hello()
	{
		std::cout << "Hellow parallel world!\n" << std::endl;
	}
}

void RunExmpleHellowWorld::excute()
{
	std::thread t(hello);
	t.join();
}
