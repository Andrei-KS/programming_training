/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 03/09/2023 08:26:49
	author                                          : Andrei-KS
*/
#ifdef _WIN32
  #include <windows.h>
  #include <sysinfoapi.h>
#else
  #include <unistd.h>
  #include <sys/time.h>
#endif

namespace {
  constexpr int secondInMinut = 60;
  constexpr int secondInHour = 60 * secondInMinut;
  constexpr int secondInDay = 24 * secondInHour;

  void wait(int inSecond)
  {
#ifdef _WIN32
    Sleep(inSecond * 1000);
#else
    sleep(inSecond);
#endif
  }

  struct MyTimeStruct {
    int hour = -1;
    int minut = -1;
    int second = -1;
  };

  MyTimeStruct getSystemTime()
  {
    MyTimeStruct currentTime;
#ifdef _WIN32
    SYSTEMTIME st;
    GetSystemTime(&st);
    currentTime.hour = st.wHour;
    currentTime.minut = st.wMinute;
    currentTime.second = st.wSecond;
#else
    timeval tv;
    timezone tz;
    if (!gettimeofday(&tv, &tz))
    {
      currentTime.second = tv.tv_sec % secondInMinut;
      tv.tv_sec -= currentTime.second;
      currentTime.minut = tv.tv_sec % secondInHour / secondInMinut;
      tv.tv_sec -= currentTime.minut;
      currentTime.hour = tv.tv_sec % secondInDay / secondInHour;
    };
#endif
    return currentTime;
  }
}

#include "CH16P579EXERC6_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "My_window.h"
#include "Vector2D.h"
#include "Regular_polygon.h"
#include "Arrow.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH16P579EXERC6_FLTKRunExmple();

namespace {
  class SimpleWatch : Graph_lib::My_window {
  public:
    /*
    */
    SimpleWatch(Graph_lib::Point xy, int width, int height, const string& title)
      : My_window(xy, width, height, title)
      , mTitle(title)
      , mRemainingTimeToSystemRequest(0)
      , mSecondArrow(nullptr)
    {
      const int radius = 40;
      const int lengthToCorner = 10;
      const double angleRotate = 360.0 / 12.0;
      double angle = 45;
      Utility_lib::Vector2D endPoint{ radius, 0 };
      for (int index = 0; index < 12; ++index)
      {
        Graph_lib::Regular_polygon* markHour = new Graph_lib::Regular_polygon(Graph_lib::Point{ static_cast<int>(endPoint.x + radius + lengthToCorner), static_cast<int>(endPoint.y + radius + lengthToCorner) }, lengthToCorner, 4, angle);
        markHour->set_fill_color(Graph_lib::Color::black);
        pushShape(markHour);
        endPoint.rotate(angleRotate);
        angle += angleRotate;
      }

      const int startPointcoord = radius + lengthToCorner;
      mSecondArrow = new Graph_lib::Arrow({ startPointcoord, startPointcoord }, { radius + lengthToCorner,lengthToCorner }, 15, 2);
      mSecondArrow->set_fill_color(Graph_lib::Color::black);
      mSecondArrow->set_color(Graph_lib::Color::black);
      attach(*mSecondArrow);

      mMinutArrow = new Graph_lib::Arrow({ startPointcoord, startPointcoord }, { radius + lengthToCorner,lengthToCorner + 5}, 10, 4);
      mMinutArrow->set_fill_color(Graph_lib::Color::black);
      mMinutArrow->set_color(Graph_lib::Color::black);
      attach(*mMinutArrow);

      mHourArrow = new Graph_lib::Arrow({ startPointcoord, startPointcoord }, { radius + lengthToCorner,lengthToCorner + 10}, 5, 6);
      mHourArrow->set_fill_color(Graph_lib::Color::black);
      mHourArrow->set_color(Graph_lib::Color::black);
      attach(*mHourArrow);

      redraw();
    }

    ~SimpleWatch()
    {
      detach(*mSecondArrow);
      delete mSecondArrow;
      detach(*mMinutArrow);
      delete mMinutArrow;
      detach(*mHourArrow);
      delete mHourArrow;
    }

    void update()
    {
      if (mRemainingTimeToSystemRequest != 0)
      {
        --mRemainingTimeToSystemRequest;
        if (mSTime.second < 59)
        {
          ++mSTime.second;
        }
        else
        {
          if (mSTime.minut < 59)
          {
            ++mSTime.minut;
          }
          else
          {
            mSTime.minut = 0;
            if (mSTime.hour < 11)
            {
              ++mSTime.hour;
            }
            else
            {
              mSTime.hour = 0;
            }
            mSTime.minut = 0;
            mHourArrow->setDirection(-6.0 * mSTime.hour + 90.0);
          }
          mSTime.second = 0;
          mMinutArrow->setDirection(-6.0 * mSTime.minut + 90.0);
        }
        mSecondArrow->setDirection(-6.0 * mSTime.second + 90.0);
      }
      else
      {
        mRemainingTimeToSystemRequest = secondInHour;
        mSTime = getSystemTime();
        mSecondArrow->setDirection(-6.0 * mSTime.second + 90.0);
        mMinutArrow->setDirection(-6.0 * mSTime.minut + 90.0);
        mHourArrow->setDirection(-6.0 * mSTime.hour + 90.0);

      }

      cout << mTitle << " " << mSTime.hour << ":" << mSTime.minut << ":" << mSTime.second << "\n";
      redraw();
    }

    virtual void next()
    {
    }

  protected:
    void pushShape(Graph_lib::Shape* shape_ptr)
    {
      if (shape_ptr)
      {
        mShapes.push_back(shape_ptr);
        attach(*shape_ptr);
        redraw();
      }
    }

  private:
    /**/
    Graph_lib::Vector_ref<Graph_lib::Shape> mShapes;
    
    /**/
    Graph_lib::Arrow* mSecondArrow;

    /**/
    Graph_lib::Arrow* mMinutArrow;

    /**/
    Graph_lib::Arrow* mHourArrow;

    /**/
    string mTitle;

    /**/
    MyTimeStruct mSTime;

    /**/
    int mRemainingTimeToSystemRequest;
  };

  class TimeScheduler {
  public:
    static TimeScheduler* getTimeScheduler()
    {
      if (ts == nullptr)
      {
        ts = new TimeScheduler();
      }
      return ts;
    }

    static void UpdateListener(void*)
    {
      if (getTimeScheduler())
      {
        vector<SimpleWatch*>& simpleWatchs = getTimeScheduler()->mSimpleWatchs;
        for (SimpleWatch* sw : simpleWatchs)
        {
          sw->update();
        }
      }
      Fl::add_timeout(1.0, UpdateListener);
    }
    
    void add(SimpleWatch& sw)
    {
      mSimpleWatchs.push_back(&sw);
    }

  private:
    static TimeScheduler* ts;
    TimeScheduler() { Fl::add_timeout(0.0, UpdateListener); };
    vector<SimpleWatch*> mSimpleWatchs;
  };

  TimeScheduler* TimeScheduler::ts = nullptr;
}

int CH16P579EXERC6_FLTKRunExmple::excute()
{
  SimpleWatch myWindow({ 100,100 }, 600, 400, "CH16P579EXERC5_FLTKRunExmple");
  TimeScheduler::getTimeScheduler()->add(myWindow);
  return Graph_lib::gui_main();
}