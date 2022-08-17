/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/17/2022 13:02:13
	author                                          : Andrei-KS
*/

#include "CH13P462ILLUST_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH13P462ILLUST_FLTKRunExmple();

namespace {
}

int CH13P462ILLUST_FLTKRunExmple::excute()
{
  const Graph_lib::Point x{ 100,100 };
  Graph_lib::Simple_window win{ x,600,400,"Rectangle" };

  Graph_lib::Rectangle rect00{ Graph_lib::Point{150,100},200,100 };
  Graph_lib::Rectangle rect11{ Graph_lib::Point{50,50},Graph_lib::Point{250,150} };
  // just below rect11
  Graph_lib::Rectangle rect12{ Graph_lib::Point{50,150},Graph_lib::Point{250,250} };
  // just to the right of rect11
  Graph_lib::Rectangle rect21{ Graph_lib::Point{250,50},200,100 };
  // just below rect21
  Graph_lib::Rectangle rect22{ Graph_lib::Point{250,150},200,100 };

  rect00.set_fill_color(Graph_lib::Color::yellow);
  rect11.set_fill_color(Graph_lib::Color::blue);
  rect12.set_fill_color(Graph_lib::Color::red);
  rect21.set_fill_color(Graph_lib::Color::green);

  rect00.set_color(Graph_lib::Color::black);
  rect11.set_color(Graph_lib::Color::black);
  rect12.set_color(Graph_lib::Color::black);
  rect21.set_color(Graph_lib::Color::black);
  rect22.set_color(Graph_lib::Color::black);


  win.attach(rect00);
  win.attach(rect11);
  win.attach(rect12);
  win.attach(rect21);
  win.attach(rect22);

  win.wait_for_button();


  // to the right of rect21
  rect11.move(400, 0); 
  rect11.set_fill_color(Graph_lib::Color::white);
  win.set_label("Rectangle 2 - move rect21 to right");
  win.wait_for_button();


  // rect00 is put on top
  win.put_on_top(rect00);
  win.set_label("Rectangle 3 - put on top rect00");
  win.wait_for_button();

  // remove outline
  rect00.set_color(Graph_lib::Color::invisible);
  rect11.set_color(Graph_lib::Color::invisible);
  rect12.set_color(Graph_lib::Color::invisible);
  rect21.set_color(Graph_lib::Color::invisible);
  rect22.set_color(Graph_lib::Color::invisible);
  win.set_label("Rectangle 4 - remove outline");
  win.wait_for_button();

  return 0;
}