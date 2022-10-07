/*
  My_window.cpp
  author  : Andrei-KS
*/

#include "My_window.h"

namespace Graph_lib {

  My_window::My_window(Point xy, int width, int height, const string& title)
    : Window(xy,width,height,title)
    , quit_button(Point{ x_max() - 50, 0}, 50, 20, "Quit", cb_quit)
    , next_button(Point{ x_max() - 100, 0}, 50, 20, "Next", cb_next)
  {
    attach(quit_button);
    attach(next_button);
  }

  void My_window::cb_next(Address, Address pw)
  {
    reference_to<My_window>(pw).next();
  }

  void My_window::cb_quit(Address, Address pw)
  {
    reference_to<My_window>(pw).quit();
  }

  void My_window::next()
  {
    redraw();
  }

  void My_window::quit()
  {
    hide();
  }

}