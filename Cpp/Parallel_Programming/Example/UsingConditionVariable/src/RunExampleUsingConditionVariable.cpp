
#include "RunExampleUsingConditionVariable.h"
#include <mutex>
#include <condition_variable>
#include <queue>
#include <string>
#include <random>
#include <iostream>

#include <thread>

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new RunExampleUsingConditionVariable();

namespace
{
	struct Data
	{
		int id;
		std::string name;
		float FloatNumber;
	};

	std::mutex globalMutex;
	std::queue<Data> dataQueue;
	std::condition_variable dataCondition;

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
	void dataPreparationThread()
	{
		while (moreDataToPrepare())
		{
			Data const data = prepareData();
			std::lock_guard<std::mutex> lk(globalMutex);
			dataQueue.push(data);
			dataCondition.notify_one();
		}
	}

	void dataProcessingThread()
	{
		while (true)
		{
			std::unique_lock<std::mutex> lk(globalMutex);
			dataCondition.wait(lk, [] {return !dataQueue.empty(); });
			Data data = dataQueue.front();
			dataQueue.pop();
			lk.unlock();
			process(data);
			if (is_last(data))
			{
				break;
			}
		}
	}
}

void RunExampleUsingConditionVariable::excute()
{
	createGlobalDate(100);
	std::thread t1(dataPreparationThread);
	std::thread t2(dataProcessingThread);
	t1.join();
	t2.join();
	clearGlobalDate();
}

