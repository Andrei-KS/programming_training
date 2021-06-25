

#include "RunExamplePassingCommandsBetweenThreads.h"

#include <deque>
#include <mutex>
#include <future>
#include <thread>
#include <utility>

#include <iostream>

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new RunExamplePassingCommandsBetweenThreads();

namespace
{
	std::mutex globalMutex;
	std::deque<std::packaged_task<void()>> tasks;

	bool bIsGUIShotdown = false;
	bool gui_shutdown_message_received()
	{
		return bIsGUIShotdown;
	}

	void get_and_process_gui_message()
	{
		std::cout << "GUI do somethings" << std::endl;
	}

	void gui_thread()
	{
		while (!gui_shutdown_message_received())
		{
			get_and_process_gui_message();
			std::packaged_task<void()> task;
			{
				std::lock_guard<std::mutex> lk(globalMutex);
				if (tasks.empty())
				{
					continue;
				}
				task = std::move(tasks.front());
				tasks.pop_front();
			}
			task();
		}
	}

	std::thread gui_bg_thread(gui_thread);

	template<typename Func>
	std::future<void> post_task_for_gui_thread(Func f)
	{
		std::packaged_task<void()> task(f);
		std::future<void> res = task.get_future();
		std::lock_guard<std::mutex> lk(globalMutex);
		tasks.push_back(std::move(task));
		return res;
	}
 
}

void RunExamplePassingCommandsBetweenThreads::excute()
{
	const int amountOfPostingMessageToGUI = 5;
	const int amountTic = 1000000;
	for (int i = 0; i < amountOfPostingMessageToGUI; i++)
	{
		post_task_for_gui_thread([i,amountTic,amountOfPostingMessageToGUI]()
		{
			double res = 0;
			for (int tic = 0; tic < amountTic; tic++)
			{
				// To do somethings
				res = tic * 0.5 + tic / 0.8 + res;
			}
			std::cout << "number post:\t" << i << std::endl;
			if (i == amountOfPostingMessageToGUI - 1)
			{
				bIsGUIShotdown = true;
			}
		});
	}
	gui_bg_thread.join();
}
