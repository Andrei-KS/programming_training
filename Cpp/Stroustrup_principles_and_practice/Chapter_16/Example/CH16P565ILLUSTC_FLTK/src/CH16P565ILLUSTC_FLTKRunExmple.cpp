/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/05/2022 19:02:11
	author                                          : Andrei-KS
*/

#include "CH16P565ILLUSTC_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH16P565ILLUSTC_FLTKRunExmple();

namespace {
  /*
  */
  struct Lines_window : Graph_lib::Window {
    /*
    */
    Lines_window(Graph_lib::Point xy, int width, int height, const string& title);

    /**/
    Graph_lib::Open_polyline lines;

    /**/
    Graph_lib::Menu color_menu;

    /**/
    Graph_lib::Button menu_button;

    /*
    * callback for red button
    */
    static void cb_red(Graph_lib::Address, Graph_lib::Address);

    /*
    * callback for blue button
    */
    static void cb_blue(Graph_lib::Address, Graph_lib::Address);

    /*
    * callback for black button
    */
    static void cb_black(Graph_lib::Address, Graph_lib::Address);

    /*
    * callback for menu button
    */
    static void cb_menu(Graph_lib::Address, Graph_lib::Address);

    // the actions:
    /*
    */
    void red_pressed()
    {
      change(Graph_lib::Color::red);
      hide_menu();
    }

    /*
    */
    void blue_pressed()
    {
      change(Graph_lib::Color::blue);
      hide_menu();
    }

    /*
    */
    void black_pressed()
    {
      change(Graph_lib::Color::black);
      hide_menu();
    }

    /*
    */
    void menu_pressed()
    {
      menu_button.hide();
      color_menu.show();
    }

    /*
    */
    void change(Graph_lib::Color color)
    {
      lines.set_color(color);
      redraw();
    }

    /*
    */
    void hide_menu()
    {
      color_menu.hide();
      menu_button.show();
    }

  private:
    /**/
    Graph_lib::Button next_button;

    /**/
    Graph_lib::Button quit_button;

    /**/
    Graph_lib::In_box next_x;

    /**/
    Graph_lib::In_box next_y;

    /**/
    Graph_lib::Out_box xy_out;

    /*
    */
    void next();

    /*
    */
    void quit();
  };

  Lines_window::Lines_window(Graph_lib::Point xy, int width, int height, const string& title)
    : Window(xy, width, height, title)
    , next_button{ Graph_lib::Point{x_max() - 150,0},70,20,"Next point",[](Graph_lib::Address,Graph_lib::Address pw) {Graph_lib::reference_to<Lines_window>(pw).next(); } }
  , quit_button{ Graph_lib::Point{x_max() - 70,0},70,20,"Quit",[](Graph_lib::Address,Graph_lib::Address pw) {Graph_lib::reference_to<Lines_window>(pw).quit(); } }
    , next_x{ Graph_lib::Point{x_max() - 310,0},50,20,"next x:" }
    , next_y{ Graph_lib::Point{x_max() - 210,0},50,20, "next y:" }
    , xy_out{ Graph_lib::Point{100,0},100,20,"current (x,y):" }
    , color_menu{ Graph_lib::Point{x_max() - 70,40},70,20,Graph_lib::Menu::vertical,"color" }
    , menu_button{ Graph_lib::Point{x_max() - 80,30},80,20,"color menu",cb_menu }
  {
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");

    color_menu.attach(new Graph_lib::Button{ Graph_lib::Point{0,0},0,0,"red",cb_red });
    color_menu.attach(new Graph_lib::Button{ Graph_lib::Point{0,0},0,0,"blue",cb_blue });
    color_menu.attach(new Graph_lib::Button{ Graph_lib::Point{0,0},0,0,"black",cb_black });
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);

    attach(lines);
  }

  void Lines_window::quit()
  {
    hide();
  }

  void Lines_window::next()
  {
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add(Graph_lib::Point{ x,y });

    // update currrent position readout:
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
  }

  void Lines_window::cb_red(Graph_lib::Address, Graph_lib::Address pw)
  {
    Graph_lib::reference_to<Lines_window>(pw).red_pressed();
  }

  void Lines_window::cb_blue(Graph_lib::Address, Graph_lib::Address pw)
  {
    Graph_lib::reference_to<Lines_window>(pw).blue_pressed();
  }

  void Lines_window::cb_black(Graph_lib::Address, Graph_lib::Address pw)
  {
    Graph_lib::reference_to<Lines_window>(pw).black_pressed();
  }

  void Lines_window::cb_menu(Graph_lib::Address, Graph_lib::Address pw)
  {
    Graph_lib::reference_to<Lines_window>(pw).menu_pressed();
  }
}

int CH16P565ILLUSTC_FLTKRunExmple::excute()
{
  try {
    Lines_window win{ Graph_lib::Point{100,100},600,400,"lines" };
    return Graph_lib::gui_main();
  }
  catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
  }
  catch (...) {
    cerr << "some exception\n";
    return 2;
  }
}