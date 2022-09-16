/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/16/2022 17:34:49
	author                                          : Andrei-KS
*/

#include "CH14P517EXERC16_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH14P517EXERC16_FLTKRunExmple();

namespace {
  /*
  */
  class Controller {
  public:
    /*
    */
    Controller() { }
    
    /*
    */
    virtual ~Controller() { }

    /*
    */
    virtual void on() = 0;

    /*
    */
    virtual void off() = 0;

    /*
    */
    virtual void set_level(int value) = 0;

    /*
    */
    virtual void show() = 0;
  };

  /*
  */
  class Test_Controller : public Controller {
  public:
    /*
    */
    Test_Controller()
      : mIsOn(false)
      , mLevel(0)
    {}

    /*
    */
    void on() override
    {
      mIsOn = true;
    }

    /*
    */
    void off() override
    {
      mIsOn = false;
    }

    /*
    */
    void set_level(int value) override
    {
      mLevel = value;
    }

    /*
    */
    void show() override
    {
      cout << "Test_Controller info :\n"
        << "Controller is " << (mIsOn ? "on" : "off") << "\n"
        << "Level equal " << mLevel << "\n";
    }

  private:
    /**/
    bool mIsOn;

    /**/
    int mLevel;
  };

  class Line_Color_Controller : public Controller
  {
  public:
    /*
    */
    Line_Color_Controller(Graph_lib::Shape& shape)
      : mShape(&shape)
      , mIsOn(false)
    {
    }

    /*
    */
    void on() override
    {
      mIsOn = true;
    }

    /*
    */
    void off() override
    {
      mIsOn = false;
    }

    virtual void set_level(int value)
    {
      if (mIsOn)
      {
        mShape->set_color(value);
      }
    }

    /*
    */
    void show() override
    {
      cout << "Line_Color_Controller info :\n"
        << "Controller is " << (mIsOn ? "on" : "off") << "\n"
        << "Level equal " << mShape->color().as_int() << "\n";
    }

  private:
    /**/
    bool mIsOn;

    /**/
    Graph_lib::Shape* mShape;
  };

  class Line_Width_Controller : public Controller
  {
  public:
    /*
    */
    Line_Width_Controller(Graph_lib::Shape& shape)
      : mShape(&shape)
      , mIsOn(false)
    {
    }

    /*
    */
    void on() override
    {
      mIsOn = true;
    }

    /*
    */
    void off() override
    {
      mIsOn = false;
    }

    virtual void set_level(int value)
    {
      if (mIsOn)
      {
        value = value > 0 ? value : 0;
        Graph_lib::Line_style ls = mShape->style();
        mShape->set_style(Graph_lib::Line_style{ static_cast<Graph_lib::Line_style::Line_style_type>(ls.style()), value});
      }
    }

    /*
    */
    void show() override
    {
      cout << "Line_Width_Controller info :\n"
        << "Controller is " << (mIsOn ? "on" : "off") << "\n"
        << "Level equal " << mShape->style().width() << "\n";
    }

  private:
    /**/
    bool mIsOn;

    /**/
    Graph_lib::Shape* mShape;
  };
}

int CH14P517EXERC16_FLTKRunExmple::excute()
{
  Test_Controller testController;
  testController.show();

  testController.on();
  testController.set_level(5);
  testController.show();

  Graph_lib::Line line{ Graph_lib::Point{10,10},Graph_lib::Point{20,20} };
  Line_Color_Controller lcController{ line };
  Line_Width_Controller lwController{ line };
  lcController.show();

  line.set_color(1);
  lcController.show();

  lcController.set_level(2);
  lcController.show();

  lcController.on();
  lcController.set_level(2);
  lwController.on();
  lwController.set_level(2);

  lcController.show();
  lwController.show();


	return 0;
}