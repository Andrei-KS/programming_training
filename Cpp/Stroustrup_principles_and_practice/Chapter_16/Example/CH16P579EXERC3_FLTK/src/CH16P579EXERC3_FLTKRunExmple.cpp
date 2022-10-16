/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/12/2022 10:47:57
	author                                          : Andrei-KS
*/

#include "CH16P579EXERC3_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "My_window.h"
#include <random>

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH16P579EXERC3_FLTKRunExmple();

namespace {
  /*
  */
  struct Image_on_buttom_window : Graph_lib::My_window {

    inline int rand_int(int min, int max)
    {
      static default_random_engine ran;
      return uniform_int_distribution<>{min, max}(ran);
    }

    /*
    */
    Image_on_buttom_window(Graph_lib::Point xy, int width, int height, const string& title)
      : My_window(xy, width, height, title)
      , mButtonOfImage{nullptr}
      , mImage{Graph_lib::Point{ 0,0 }, "Image.jpg"}
    {
      int buttonWidth = 100;
      int buttonHieght = 100;
      mImage.set_mask({ 0,0 }, buttonWidth, buttonHieght);
      attach(mImage);
      mButtonOfImage = new Graph_lib::Button{ Graph_lib::Point{0,0},buttonWidth,buttonHieght,"Image Button",cd_pushed_Image_button };
      attach(*mButtonOfImage);
      mMaxValue = x_max() - 200;
    }

    /*
    */
    ~Image_on_buttom_window()
    {
      delete mButtonOfImage;
    }

    /*
    */
    void next() override
    {
      int x_new_location = -mImage.point(0).x;
      mImage.move(x_new_location, 0);
      mButtonOfImage->move(x_new_location, 0);
      My_window::next();
    }

  private:
    /**/
    int mMaxValue;
    /**/
    Graph_lib::Button* mButtonOfImage;

    /**/
    Graph_lib::Image mImage;

    /*
    */
    static void cd_pushed_Image_button(Graph_lib::Address pWidget, Graph_lib::Address pWindow)
    {
      Graph_lib::reference_to<Image_on_buttom_window>(pWindow).pushed_Image_button();
    }

    /*
    */
    void pushed_Image_button()
    {
      int x_new_location = -mImage.point(0).x + rand_int(0, mMaxValue);
      mImage.move(x_new_location, 0);
      mButtonOfImage->move(x_new_location, 0);
      redraw();
    }
  };


}

int CH16P579EXERC3_FLTKRunExmple::excute()
{
  Image_on_buttom_window myWindow({ 100,100 }, 600, 400, "CH16P579EXERC3_FLTKRunExmple");

  return Graph_lib::gui_main();
}