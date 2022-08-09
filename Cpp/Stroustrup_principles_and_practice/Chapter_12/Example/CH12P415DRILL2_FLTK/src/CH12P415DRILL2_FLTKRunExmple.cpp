/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/09/2022 16:00:17
	author                                          : Andrei-KS
*/

#include "CH12P415DRILL2_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P415DRILL2_FLTKRunExmple();

namespace {
}

int CH12P415DRILL2_FLTKRunExmple::excute()
{
  // top left corner of our window
  Graph_lib::Point topLeft(100, 100);
  
  // screen coordinate tl for top left corner
  // window size(600*400)
  // title: Canvas
  Graph_lib::Simple_window sWindow(topLeft, 600, 400, "Canvas");
  // display!
  sWindow.wait_for_button();

  const int x_max_left_margin = 20;
  const int y_max_bottom_margin = 300;
  const int axis_lenght = 280;
  // make an Axis
  // an Axis is a kind of Shape
  // Axis::x means vertical
  // starting at (x_max_left_margin, y_max_bottom_margin)
  // axis_lenght pixels long
  // 10 “notches”
  // label the axis "x axis"
  Graph_lib::Axis xAxis(Graph_lib::Axis::x, Graph_lib::Point(x_max_left_margin, y_max_bottom_margin), axis_lenght, 10, "x axis");
  // choose a color
  xAxis.set_color(Graph_lib::Color::black);
  // attach xAxis to the window
  sWindow.attach(xAxis);
  // relabel the window
  sWindow.set_label("Canvas #2");
  sWindow.wait_for_button();

  // make an Axis
  // an Axis is a kind of Shape
  // Axis::y means horizontal
  // starting at (x_max_left_margin, y_max_bottom_margin)
  // axis_lenght pixels long
  // 10 “notches”
  // label the axis "y axis"
  Graph_lib::Axis yAxis(Graph_lib::Axis::y, Graph_lib::Point(x_max_left_margin, y_max_bottom_margin), axis_lenght, 10, "y axis");
  // choose a color
  yAxis.set_color(Graph_lib::Color::cyan);
  // choose a color for the text
  yAxis.label.set_color(Graph_lib::Color::dark_red);
  // attach yAxis to the window
  sWindow.attach(yAxis);
  sWindow.set_label("Canvas #3");
  sWindow.wait_for_button();

  // sine curve
  // plot sin() in the range [0:100) with (0,0) at (20,150)
  // using 1000 points; scale x values *50, scale y values *50
  Graph_lib::Function sine(sin, 0, 100, Graph_lib::Point(20, 150), 1000, 50, 50);
  // choose a color
  sine.set_color(Graph_lib::Color::blue);
  sWindow.attach(sine);
  sWindow.set_label("Canvas #4");
  sWindow.wait_for_button();

  // a Polygon is a kind of Shape
  Graph_lib::Polygon poly;
  // three points make a triangle
  poly.add(Graph_lib::Point{ 300,200 });
  poly.add(Graph_lib::Point{ 350,100 });
  poly.add(Graph_lib::Point{ 400,200 });
  poly.set_color(Graph_lib::Color::red);
  poly.set_style(Graph_lib::Line_style::dash);
  sWindow.attach(poly);
  sWindow.set_label("Canvas #5");
  sWindow.wait_for_button();

  // a rectangle requires four values: top left corner, width, height
  Graph_lib::Rectangle rect{ Graph_lib::Point{200,200}, 100, 50 }; 
  sWindow.attach(rect);

  Graph_lib::Closed_polyline poly_rect;
  poly_rect.add(Graph_lib::Point{ 100,50 });
  poly_rect.add(Graph_lib::Point{ 200,50 });
  poly_rect.add(Graph_lib::Point{ 200,100 });
  poly_rect.add(Graph_lib::Point{ 100,100 });
  poly_rect.add(Graph_lib::Point{ 50,75 });
  sWindow.attach(poly_rect);
  sWindow.set_label("Canvas #6");
  sWindow.wait_for_button();

  // color the inside of the rectangle
  rect.set_fill_color(Graph_lib::Color::yellow);
  poly.set_style(Graph_lib::Line_style(Graph_lib::Line_style::dash, 4));
  poly_rect.set_style(Graph_lib::Line_style(Graph_lib::Line_style::dash, 2));
  poly_rect.set_fill_color(Graph_lib::Color::green);
  sWindow.set_label("Canvas #7");
  sWindow.wait_for_button();

  Graph_lib::Text text{ Graph_lib::Point{150,150}, "Hello, graphical world!" };
  sWindow.attach(text);
  sWindow.set_label("Canvas #8");
  sWindow.wait_for_button();

  text.set_font(Graph_lib::Font::times_bold);
  text.set_font_size(20);
  sWindow.set_label("Canvas #9");
  sWindow.wait_for_button();

  Graph_lib::Image image{ Graph_lib::Point{100,50},"image.jpg" };
  sWindow.attach(image);
  sWindow.set_label("Canvas #10");
  sWindow.wait_for_button();

  image.move(100, 200);
  sWindow.set_label("Canvas #10");
  sWindow.wait_for_button();

  Graph_lib::Circle c{ Graph_lib::Point{100,200},50 };
  Graph_lib::Ellipse e{ Graph_lib::Point{100,200}, 75,25 };
  e.set_color(Graph_lib::Color::dark_red);
  Graph_lib::Mark m{ Graph_lib::Point{100,200},'x' };
  ostringstream oss;
  oss << "screen size: " << Graph_lib::x_max() << "*" << Graph_lib::y_max()
   << "; window size: " << sWindow.x_max() << "*" << sWindow.y_max();
  Graph_lib::Text sizes { Graph_lib::Point{100,20},oss.str()};
  Graph_lib::Image cal { Graph_lib::Point{225,225},"snow_cpp.gif"};
  // display center part of image
  cal.set_mask(Graph_lib::Point{40,40},200,150);
  sWindow.attach(c);
  sWindow.attach(m);
  sWindow.attach(e);
  sWindow.attach(sizes);
  sWindow.attach(cal);
  sWindow.set_label("Canvas #12");
  sWindow.wait_for_button();

  return 0;
}