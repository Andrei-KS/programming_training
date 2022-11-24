/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 11/23/2022 14:38:06
	author                                          : Andrei-KS
*/

#include "CH16P579EXERC4_FLTKRunExmple.h"
#include "map"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "My_window.h"
#include "Regular_polygon.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH16P579EXERC4_FLTKRunExmple();

namespace {
	const int FORM_SIZE = 50;
	Graph_lib::Shape* make_circle(const Graph_lib::Point& xy)
	{
		return new Graph_lib::Circle(xy, FORM_SIZE/2);
	}

	Graph_lib::Shape* make_square(const Graph_lib::Point& xy)
	{
		return new Graph_lib::Regular_polygon(xy, FORM_SIZE * 2 / 3, 4, 45);
	}

	Graph_lib::Shape* make_equilateral_triangle(const Graph_lib::Point& xy)
	{
		return new Graph_lib::Regular_polygon(xy, FORM_SIZE*2/3, 3, 90);
	}

	Graph_lib::Shape* make_hexagon(const Graph_lib::Point& xy)
	{
		return new Graph_lib::Regular_polygon(xy, FORM_SIZE * 2 / 3, 6, 90);
	}
	const map<string, Graph_lib::Shape*(*)(const Graph_lib::Point&)> geometry_names = {
		{"1. circle", make_circle},
		{"2. square", make_square},
		{"3. equilateral triangle", make_equilateral_triangle},
		{"4. hexagon", make_hexagon},
	};

	struct Geometry_forms_window : Graph_lib::My_window {
	public:
		/*
		*/
		Geometry_forms_window(Graph_lib::Point xy, int width, int height, const string& title)
			: My_window(xy, width, height, title)
			, geometry_forms_menu{Graph_lib::Point{0,0}, 150, 20, Graph_lib::Menu::vertical, "forms"}
			, next_x{ Graph_lib::Point{200, 0}, 50, 20, "next x:" }
			, next_y{ Graph_lib::Point{300, 0}, 50, 20, "next y:" }
		{
			map<string, Graph_lib::Shape* (*)(const Graph_lib::Point&)>::const_iterator it = geometry_names.begin();
			while (it != geometry_names.end())
			{
				geometry_forms_menu.attach(new Graph_lib::Button{ Graph_lib::Point{0,0},0,0,it->first.c_str(),cb_pushed_menu_button });
				it++;
			}
			attach(geometry_forms_menu);
			attach(next_x);
			attach(next_y);
			Graph_lib::Shape* shape_ptr = new Graph_lib::Circle({200,200}, FORM_SIZE);
			attach(*shape_ptr);
		}

		/*
		*/
		static void cb_pushed_menu_button(Graph_lib::Address pWidget, Graph_lib::Address pWindow)
		{
			Fl_Button& button = Graph_lib::reference_to<Fl_Button>(pWidget);
			map<string, Graph_lib::Shape* (*)(const Graph_lib::Point&)>::const_iterator it = geometry_names.find(button.label());
			if (it != geometry_names.end())
			{
				Graph_lib::reference_to<Geometry_forms_window>(pWindow).pushed_menu_button(it->second);
			}
		}

		void pushed_menu_button(Graph_lib::Shape* (*shape_maker)(const Graph_lib::Point&))
		{
			Graph_lib::Shape* shape_ptr = shape_maker(Graph_lib::Point{ next_x.get_int(), next_y.get_int() });
			if (shape_ptr)
			{
				forms.push_back(shape_ptr);
				shape_ptr->set_fill_color(Graph_lib::Color::black);
				attach(*shape_ptr);
				redraw();
			}
		}

	private:
		/**/
		Graph_lib::Menu geometry_forms_menu;

		/**/
		Graph_lib::In_box next_x;

		/**/
		Graph_lib::In_box next_y;

		/**/
		Graph_lib::Vector_ref<Graph_lib::Shape> forms;
	};
}

int CH16P579EXERC4_FLTKRunExmple::excute()
{
	Geometry_forms_window myWindow({ 100,100 }, 600, 400, "CH16P579EXERC4_FLTKRunExmple");

	return Graph_lib::gui_main();
}