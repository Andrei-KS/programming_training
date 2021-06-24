

#include "RunExampleUsingThreadsafeQueue.h"

#include <string>
#include <vector>
#include <iostream>
#include <random>

#include "ThreadsafeQueue.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new RunExampleUsingThreadsafeQueue();

namespace
{
	struct Data
	{
		int id = -1;
		std::string name = std::string();
		float FloatNumber = -1;
	};

	// helper functions for the example 
	std::vector<std::pair<std::string, float>> GlobalDate;
	int index = 0;
	void createGlobalDate(int numberDates)
	{
		std::random_device rd;
		const int lengthName = 10;
		const int deltaLetter = 'z' - 'a';

		while (numberDates > 0)
		{
			std::string tempName(lengthName, 'a');
			for (int i = 0; i < lengthName; i++)
			{
				tempName[i] = 'a' + static_cast<int>(static_cast<float>(rd()) / rd.max() * deltaLetter);
			}
			GlobalDate.push_back({ tempName,static_cast<float>(rd()) / rd.max() });
			numberDates--;
		}
		index = GlobalDate.size() - 1;
	}
	void clearGlobalDate()
	{
		GlobalDate.clear();
	}

	bool moreDataToPrepare()
	{
		return index >= 0;
	}

	Data prepareData()
	{
		Data ret({ index, GlobalDate[index].first, GlobalDate[index].second });
		index--;
		return ret;
	}

	bool is_last(const Data& data)
	{
		return data.id == 0;
	}
	void process(Data& data)
	{
		std::cout << "id:\t" << data.id << "\nname:\t" << data.name << "\nnumber:\t" << data.FloatNumber << "\n" << std::endl;
	}

	// basic functions for example
	ParallelUtilities::ThreadsafeQueue<Data> queueData;

	void dataPreparationThread()
	{
		while (moreDataToPrepare())
		{
			Data data = prepareData();
			queueData.push(data);
		}
	}

	void dataProcessingThread()
	{
		while (true)
		{
			Data data;
			queueData.wait_and_pop(data);
			process(data);
			if (is_last(data))
			{
				break;
			}
		}
	}
}

void RunExampleUsingThreadsafeQueue::excute()
{
	createGlobalDate(20);

	std::thread t1(dataPreparationThread);
	std::thread t2(dataProcessingThread);
	t1.join();
	t2.join();

	clearGlobalDate();
}

