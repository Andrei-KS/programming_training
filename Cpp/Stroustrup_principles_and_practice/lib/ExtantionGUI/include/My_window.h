/*
  My_window.h
  author  : Andrei-KS
*/

#ifndef __MY_WINDOW_H__
#define __MY_WINDOW_H__

#include "GUI.h"

namespace Graph_lib {

  /*
  */
  struct My_window : Window {
    /*
    */
    My_window(Point xy, int width, int height, const string& title);

  private:
    /**/
    Button next_button;

    /**/
    Button quit_button;

    /*
    */
    static void cb_next(Address, Address pw);
    
    /*
    */
    static void cb_quit(Address, Address pw);

    /*
    */
    void next();

    /*
    */
    void quit();
  };
}


#endif // !__MY_WINDOW_H__