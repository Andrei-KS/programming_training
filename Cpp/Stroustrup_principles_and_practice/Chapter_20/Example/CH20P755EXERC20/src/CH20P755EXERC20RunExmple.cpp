/*
  This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
  date generate                                   : 09/06/2023 09:17:46
  author                                          : Andrei-KS
*/

#include <chrono>
#include "CH20P755EXERC20RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P755EXERC20RunExmple();

namespace {
  template<typename Func>
  long long GetTimeOfTaskRunning(Func func)
  {
    auto startTime = chrono::system_clock::now();
    func();
    auto endTime = chrono::system_clock::now();
    long long time = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
    return time;
  }
}

int CH20P755EXERC20RunExmple::excute()
{
  cout << "time of do nothing : " << GetTimeOfTaskRunning([]() {}) << "\n";

  {
    cout << "\ntest :: list and vector\n";
    list<int> testlist(0);
    vector<int> testvecotr(0);

    long long timeForList = 0;
    long long timeForVector = 0;
    // timeForList will more than 5
    // timeForVector will more than 1
    // if use step = 25000
    long long step = 25000;
    for (long long n = 1; n < 10000000; n += step)
    {
      timeForList = GetTimeOfTaskRunning([&testlist, step]()
        {
          for (int index = 0; index < step; ++index)
          {
            testlist.push_back(1);
          }
        }
      );
      timeForVector = GetTimeOfTaskRunning([&testvecotr, step]()
        {
          for (int index = 0; index < step; ++index)
          {
            testvecotr.push_back(1);
          }
        }
      );
      cout << "\nn : " << n
        << "\ntimeForList : " << timeForList
        << "\ntimeForVector : " << timeForVector
        << "\n";
      if (timeForList > timeForVector) break;
    }
  }

  {
    cout << "\ntest :: sort list and vector\n";
    list<int> testlist(0);
    vector<int> testvecotr(0);

    long long timeForList = 0;
    long long timeForVector = 0;
    long long step = 100;
    random_device rd;
    
    for (long long n = 0; n < 100000; n += step)
    {
      unsigned int seed = rd();
      timeForList = GetTimeOfTaskRunning([&testlist, seed, step]()
        {
          srand(seed);
          for (int index = 0; index < step; ++index)
          {
            int value = rand();
            auto it = upper_bound(testlist.begin(), testlist.end(), value);
            testlist.insert(it,value);
          }
        }
      );
      timeForVector = GetTimeOfTaskRunning([&testvecotr, seed, step]()
        {
          srand(seed);
          for (int index = 0; index < step; ++index)
          {
            int value = rand();
            auto it = upper_bound(testvecotr.begin(), testvecotr.end(), value);
            testvecotr.insert(it, value);
          }
        }
      );
      cout << "\nn : " << n
        << "\ntimeForList : " << timeForList
        << "\ntimeForVector : " << timeForVector
        << "\n";
      if (timeForList > timeForVector + 5) break;
    }
  }

	return 0;
}