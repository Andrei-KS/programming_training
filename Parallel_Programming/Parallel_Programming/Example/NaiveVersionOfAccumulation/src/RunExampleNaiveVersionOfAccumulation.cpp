

#include "RunExampleNaiveVersionOfAccumulation.h"
#include <thread>
#include <numeric> // for std::accumulate
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new RunExampleNaiveVersionOfAccumulation();

template<typename Iterator, typename T>
struct AccumulateBlock
{
	void operator()(Iterator first, Iterator last, T& result)
	{
		result = std::accumulate(first, last, result);
		
		std::cout << result << std::endl;
	}
};

template<typename Iterator, typename T>
T parallelAccumulate(Iterator first, Iterator last, T init)
{
	size_t const length = std::distance(first, last);
	if (!length)
	{
		return init;
	}

	// This number is amount elements will be processed at one thread
	size_t const minPerThread = 25;
	size_t const maxThreads = (length + minPerThread - 1) / minPerThread;

	size_t const hardWareThreads = std::thread::hardware_concurrency();

	// Amount Thread will be used
	size_t const numThreads = std::min(hardWareThreads != 0 ? hardWareThreads : 2, maxThreads);

	std::cout << "numThreads:\t" << numThreads << std::endl;

	size_t const blockSize = length / numThreads;

	std::vector<T> results(numThreads);
	std::vector<std::thread> threads(numThreads - 1);
	Iterator blockStart = first;
	for (size_t i = 0; i < (numThreads - 1); i++)
	{
		Iterator blockEnd = blockStart;
		std::advance(blockEnd, blockSize);
		threads[i] = std::thread(AccumulateBlock<Iterator, T>(), blockStart, blockEnd, std::ref(results[i]));
		blockStart = blockEnd;
	}
	AccumulateBlock<Iterator,T>()(blockStart, last, results[numThreads - 1]);
	
	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	return std::accumulate(results.begin(), results.end(), init);
}

void RunExampleNaiveVersionOfAccumulation::excute()
{
	const size_t lengthVector = 1000;
	std::vector<int> onesVector(1000, 1);
	std::cout << parallelAccumulate<std::vector<int>::iterator,int>(onesVector.begin(), onesVector.end(), 0) << std::endl;
}
