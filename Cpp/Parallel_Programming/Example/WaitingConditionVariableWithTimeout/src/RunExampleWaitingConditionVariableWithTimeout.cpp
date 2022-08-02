

#include "RunExampleWaitingConditionVariableWithTimeout.h"
#include <iostream>
#include <chrono>
#include <iomanip>
RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new RunExampleWaitingConditionVariableWithTimeout();

namespace
{

}


void RunExampleWaitingConditionVariableWithTimeout::excute()
{
	std::cout << "Start example..." << std::endl;
	auto start = std::chrono::high_resolution_clock::now();

	// main part of the program

	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "the execution process took " << std::setw(9) << (std::chrono::duration<double>(end - start).count()) << "ms" << std::endl;
	std::cout << "End example." << std::endl;
}
