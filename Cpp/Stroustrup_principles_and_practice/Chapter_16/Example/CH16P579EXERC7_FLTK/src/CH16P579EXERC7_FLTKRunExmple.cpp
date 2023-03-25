/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 03/21/2023 08:03:58
	author                                          : Andrei-KS
*/

#include "CH16P579EXERC7_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "My_window.h"
#include "Vector2D.h"
#include "Utility_lib_Constatnt.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH16P579EXERC7_FLTKRunExmple();

namespace {
  constexpr int CONST_RADIUS = 100;
  constexpr int CONST_SHIFT = 70;
  constexpr double RATE_UPDATE = 0.1;
  const Utility_lib::Vector2D DIRECT_TO_UP = { 0.0, 1.0 };
  constexpr double DEGREE_TO_RADIAN = Utility_lib::PI / 180.0;
  constexpr double DEFAULT_VELOCITY = CONST_RADIUS / 10;

  vector<string> imageNames = {
    "right",
    "right-down",
    "down",
    "left-down",
    "left",
    "left-up",
    "up",
    "right-up",
  };

  class ActionsWindow : Graph_lib::My_window {
  public:
    /*
    */
    ActionsWindow(Graph_lib::Point xy, int width, int height, const string& title)
      : My_window(xy, width, height, title)
      , mStartButton(Graph_lib::Point{ 0, 0 }, 50, 20, "Start", cb_start)
      , mStopButton(Graph_lib::Point{ 0, 0 }, 50, 20, "Stop", cb_stop)
    {
      attach(mStartButton);
      attach(mStopButton);

      for (int indexImage = 0; indexImage < imageNames.size(); ++indexImage)
      {
        mImages.push_back(new Graph_lib::Image( Graph_lib::Point{ CONST_RADIUS+CONST_SHIFT,CONST_SHIFT },"airplane-" + imageNames[indexImage] + ".jpg" ));
        
      }

      mIndexCurrentImage = 0;
      if (mImages.size())
      {
        attach(*mImages[mIndexCurrentImage]);
      }
      else
      {
        error("Not images");
      }

      double angleInRadian =  22.5 * DEGREE_TO_RADIAN;
      mRemainingPath = CONST_RADIUS * sin(angleInRadian);
      mPathPieceLength = 2 * mRemainingPath;
      mVelocity = DEFAULT_VELOCITY;
      mCurrentDirect = { 1,0 };

      mStartButton.show();
      mStopButton.hide();

      redraw();
    }

    /*
    */
    ~ActionsWindow()
    {
      for (int indexImage = 0; indexImage < imageNames.size(); ++indexImage)
      {
        delete mImages[indexImage];
      }
    }

    /*
    */
    static void cb_start(Graph_lib::Address, Graph_lib::Address pw)
    {
      Graph_lib::reference_to<ActionsWindow>(pw).start();
    }

    /*
    */
    void start()
    {
      mStartButton.hide();
      mStopButton.show();
      bNeedUpdate = true;
    }

    /*
    */
    static void cb_stop(Graph_lib::Address, Graph_lib::Address pw)
    {
      Graph_lib::reference_to<ActionsWindow>(pw).stop();
    }

    /*
    */
    void stop()
    {
      mStartButton.show();
      mStopButton.hide();
      bNeedUpdate = false;
    }

    /*
    */
    void update()
    {
      if (bNeedUpdate && bIsUpdate)
      {
        bIsUpdate = false;
        cout << "debug::update()\n";
        double currentRemainingPath = mRemainingPath - mVelocity;
        if (currentRemainingPath > 0)
        {
          moveImages(mCurrentDirect.x * mVelocity, mCurrentDirect.y * mVelocity);
          redraw();
        }
        else
        {
          double needMoveTo = mVelocity - currentRemainingPath;
          moveImages(mCurrentDirect.x * needMoveTo, mCurrentDirect.y * needMoveTo);
          redraw();

          chengeToNextImage();
          mCurrentDirect.rotate(-45);
          redraw();

          needMoveTo = currentRemainingPath;
          moveImages(mCurrentDirect.x * needMoveTo, mCurrentDirect.y * needMoveTo);
          redraw();

          currentRemainingPath = mPathPieceLength - currentRemainingPath;
        }
        mRemainingPath = currentRemainingPath;
        cout << "debug::update() currentRemainingPath" << currentRemainingPath << "\n";
        bIsUpdate = true;
      }
    }

  private:
    /*
    */
    void moveImages(int dx, int dy)
    {
      for (Graph_lib::Image* img : mImages)
      {
        img->move(dx, dy);
      }
    }

    /*
    */
    void chengeToNextImage()
    {
      detach(*mImages[mIndexCurrentImage]);
      int next = ++mIndexCurrentImage;
      mIndexCurrentImage = next >= mImages.size() ? 0 : next;
      attach(*mImages[mIndexCurrentImage]);
    }

    /**/
    Graph_lib::Button mStartButton;

    /**/
    Graph_lib::Button mStopButton;

    /**/
    double mPathPieceLength = 0;

    /**/
    double mRemainingPath = 0;
    /**/
    double mVelocity = 0;

    /**/
    Utility_lib::Vector2D mCurrentDirect{ 1,0 };

    /**/
    bool bNeedUpdate = false;

    /**/
    bool bIsUpdate = true;

    /**/
    int mIndexCurrentImage = 0;

    /**/
    vector<Graph_lib::Image*> mImages;
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
        vector<ActionsWindow*>& actionsWindows = getTimeScheduler()->mSimpleWatchs;
        for (ActionsWindow* aw : actionsWindows)
        {
          aw->update();
        }
      }
      Fl::add_timeout(RATE_UPDATE, UpdateListener);
    }

    void add(ActionsWindow& aw)
    {
      mSimpleWatchs.push_back(&aw);
    }

  private:
    static TimeScheduler* ts;
    TimeScheduler() { Fl::add_timeout(0.0, UpdateListener); };
    vector<ActionsWindow*> mSimpleWatchs;
  };

  TimeScheduler* TimeScheduler::ts = nullptr;
}

int CH16P579EXERC7_FLTKRunExmple::excute()
{
  ActionsWindow myWindow({ 100,100 }, 600, 400, "CH16P579EXERC7_FLTKRunExmple");
  TimeScheduler::getTimeScheduler()->add(myWindow);
  return Graph_lib::gui_main();
}