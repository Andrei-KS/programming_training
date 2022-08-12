/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/11/2022 16:04:03
	author                                          : Andrei-KS
*/

#include "CH12P438EXERC10_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P438EXERC10_FLTKRunExmple();

namespace {
  const double eps = 0.001;

  // The simple window setting
  constexpr int xUpperLeftWindowCorner  = 100;
  constexpr int yUpperLeftWindowCorner  = 100;
  constexpr int windowWidth             = 600;
  constexpr int windowHeight            = 500;

  // The Arrow setting
  const int arrowLength = 15;
  const int arrowWidth  = 5;

  // The box default setting
  struct BoxSetting {
    bool isSingle                       = true;
    
    //
    string title                        = "";
    Graph_lib::Color boxTitleColor      = Graph_lib::Color::black;
    Graph_lib::Font boxTitleFont        = Graph_lib::Font::times_bold;
    
    // box space
    Graph_lib::Color boxSpaceColor      = Graph_lib::Color::black;
    Graph_lib::Color boxSpaceFillColor  = Graph_lib::Color::yellow;

    //
    string content                      = "";
    Graph_lib::Color boxContentColor    = Graph_lib::Color::black;
    Graph_lib::Font boxContentFont      = Graph_lib::Font::times;
    Graph_lib::Font boxContentFontAlt   = Graph_lib::Font::times_bold;
  };

  struct vector2D {
    double x;
    double y;
  };

  double getLentgh(const vector2D& start, const vector2D& end)
  {
    return sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
  }

  vector2D getUnitVectorLine(const vector2D& start, const vector2D& end)
  {
    double length = getLentgh(start, end);
    return vector2D{ (end.x - start.x) / length, (end.y - start.y) / length };
  }

  vector2D getNormalToVector2D(vector2D vect)
  {
    if ( (std::abs(vect.x) < eps) && (std::abs(vect.y) < eps))
    {
      error("x and y of the vector are zero");
    }

    if (std::abs(vect.x) < 0.001)
    {
      return vector2D{ 1, 0};
    }

    if (std::abs(vect.y) < 0.001)
    {
      return vector2D{ 0, 1};
    }

    vector2D temp{ 1, -vect.x / vect.y };
    double length = getLentgh({0,0}, temp);
    return vector2D{ temp.x / length, temp.y / length};
  }

  struct Arrow : Graph_lib::Shape{
    Arrow(Graph_lib::Point start, Graph_lib::Point end, int length, int width)
    {
      Shape::add(start);
      if (std::abs(start.x - end.x) < eps && std::abs(start.y - end.y) < eps)
      {
        error("start and end are equal");
      }
      vector2D unitVectorLine = getUnitVectorLine(vector2D{ static_cast<double>(start.x), static_cast<double>(start.y) }, vector2D{ static_cast<double>(end.x), static_cast<double>(end.y) });
      vector2D normalToVector = getNormalToVector2D(unitVectorLine);
      unitVectorLine.x *= length;
      unitVectorLine.y *= length;
      normalToVector.x *= static_cast<double>(width) / 2;
      normalToVector.y *= static_cast<double>(width) / 2;
      Shape::add(Graph_lib::Point{ end.x - static_cast<int>(unitVectorLine.x), end.y - static_cast<int>(unitVectorLine.y) });
      Shape::add(Graph_lib::Point{ end.x - static_cast<int>(unitVectorLine.x) + static_cast<int>(normalToVector.x), end.y - static_cast<int>(unitVectorLine.y) + static_cast<int>(normalToVector.y) });
      Shape::add(end);
      Shape::add(Graph_lib::Point{ end.x - static_cast<int>(unitVectorLine.x) - static_cast<int>(normalToVector.x), end.y - static_cast<int>(unitVectorLine.y) - static_cast<int>(normalToVector.y) });
      Shape::add(Graph_lib::Point{ end.x - static_cast<int>(unitVectorLine.x), end.y - static_cast<int>(unitVectorLine.y) });
    }
    void draw_lines() const
    {
      if (fill_color().visibility()) {
        fl_color(fill_color().as_int());
        fl_begin_complex_polygon();
        for (int i = 0; i < number_of_points(); ++i) {
          fl_vertex(point(i).x, point(i).y);
        }
        fl_end_complex_polygon();
        fl_color(color().as_int());	// reset color
      }

      if (color().visibility())
        Shape::draw_lines();
    }
  private:
    void add(Graph_lib::Point p) = delete;
  };

  struct BoxFrame {
    Graph_lib::Point mLeftUpperCorner;
    Graph_lib::Point mRightBottomCorner;
  };

  vector<Graph_lib::Shape*> makeBox(Graph_lib::Point currentPosition, BoxFrame& boxframe, const BoxSetting& boxSetting = BoxSetting())
  {
    vector<Graph_lib::Shape*> box;
    boxframe.mLeftUpperCorner.x = currentPosition.x;
    boxframe.mLeftUpperCorner.y = currentPosition.y;

    // the title section
    if (boxSetting.title.size() && boxSetting.isSingle)
    {
      Graph_lib::Text* titleItem = new Graph_lib::Text(currentPosition, boxSetting.title);
      titleItem->set_color(boxSetting.boxTitleColor);
      titleItem->set_font(boxSetting.boxTitleFont);
      box.push_back(titleItem);
      currentPosition.y += 2;
    }

    int amount_N = 1;
    int maxLengthStr = 0;
    int currLength = 0;
    for (const char ch : boxSetting.content)
    {
      currLength++;
      if (ch == '\n')
      {
        amount_N++;
        currLength = 0;
      }
      if (currLength > maxLengthStr)
      {
        maxLengthStr = currLength;
      }
    }
    
    // the box space section
    int boxWidth = 8 * maxLengthStr + 10;
    int boxHeight = 20 * amount_N;
    if (!boxSetting.isSingle)
    {
      for (int index = 0; index < 2; index++)
      {
        Graph_lib::Rectangle* boxSpaceItem = new Graph_lib::Rectangle(currentPosition, boxWidth, boxHeight);
        boxSpaceItem->set_color(boxSetting.boxSpaceColor);
        boxSpaceItem->set_fill_color(boxSetting.boxSpaceFillColor);
        box.push_back(boxSpaceItem);
        currentPosition.x += 5;
        currentPosition.y += 5;
      }
    }

    {
      Graph_lib::Rectangle* boxSpaceItem = new Graph_lib::Rectangle(currentPosition, boxWidth, boxHeight);
      boxSpaceItem->set_color(boxSetting.boxSpaceColor);
      boxSpaceItem->set_fill_color(boxSetting.boxSpaceFillColor);
      box.push_back(boxSpaceItem);

      boxframe.mRightBottomCorner.x = currentPosition.x + boxWidth;
      boxframe.mRightBottomCorner.y = currentPosition.y + boxHeight;

      currentPosition.x += 5;
      currentPosition.y += 14;
    }



    // the content section
    if (boxSetting.content.size())
    {
      istringstream iss(boxSetting.content.c_str());
      string str;
      while (getline(iss, str))
      {
        Graph_lib::Text* contentItem = new Graph_lib::Text(currentPosition, str);
        contentItem->set_color(boxSetting.boxContentColor);
        contentItem->set_font(((isalpha(str[0])|| str[0] == '#') && boxSetting.isSingle) ? boxSetting.boxContentFontAlt : boxSetting.boxContentFont);
        box.push_back(contentItem);
        currentPosition.y += 14;
      }
    }
    return box;
  }
}

int CH12P438EXERC10_FLTKRunExmple::excute()
{
  // Make the simple window
  Graph_lib::Point upperLeftWindowcorner(xUpperLeftWindowCorner, yUpperLeftWindowCorner);
  Graph_lib::Simple_window sWindow(upperLeftWindowcorner, windowWidth, windowHeight, "EXERC10");

  vector<vector<Graph_lib::Shape*>> boxes;
  vector<BoxFrame> boxFrames;
  vector<pair<int, int>> connections;

  BoxSetting boxSetting;
  boxFrames.push_back(BoxFrame());
  boxSetting.title = "Point.h:";
  boxSetting.content = "struct Point {...};";
  boxes.push_back(makeBox(Graph_lib::Point{ 30, 30 }, *boxFrames.rbegin(), boxSetting ));
  
  boxSetting = BoxSetting();
  boxFrames.push_back(BoxFrame());
  boxSetting.isSingle = false;
  boxSetting.content = "FLTK headers";
  boxes.push_back(makeBox(Graph_lib::Point{ 290, 10 }, *boxFrames.rbegin(), boxSetting));

  boxSetting = BoxSetting();
  boxFrames.push_back(BoxFrame());
  boxSetting.isSingle = false;
  boxSetting.content = "FLTK code";
  boxes.push_back(makeBox(Graph_lib::Point{ 470, 50 }, *boxFrames.rbegin(), boxSetting));
  connections.push_back(pair<int, int>{2, 1});

  boxSetting = BoxSetting();
  boxFrames.push_back(BoxFrame());
  boxSetting.title = "Graph.h:";
  boxSetting.content = "//graphing interface:\nstructure Shape {...};\n...";
  boxes.push_back(makeBox(Graph_lib::Point{ 30,100 }, *boxFrames.rbegin(), boxSetting));
  connections.push_back(pair<int, int>{3, 0});
  connections.push_back(pair<int, int>{3, 1});

  boxSetting = BoxSetting();
  boxFrames.push_back(BoxFrame());
  boxSetting.title = "Window.h:";
  boxSetting.content = "//window interface:\nclass Window {...};\n...";
  boxes.push_back(makeBox(Graph_lib::Point{ 270,100 }, *boxFrames.rbegin(), boxSetting));
  connections.push_back(pair<int, int>{4, 1});

  boxSetting = BoxSetting();
  boxFrames.push_back(BoxFrame());
  boxSetting.title = "Window.cpp:";
  boxSetting.content = "Window code";
  boxes.push_back(makeBox(Graph_lib::Point{ 165,200 }, *boxFrames.rbegin(), boxSetting));
  connections.push_back(pair<int, int>{5, 4});

  boxSetting = BoxSetting();
  boxFrames.push_back(BoxFrame());
  boxSetting.title = "GUI.h:";
  boxSetting.content = "// GUI interface:\nstruct In_box { ... };\n... ";
  boxes.push_back(makeBox(Graph_lib::Point{ 370,200 }, *boxFrames.rbegin(), boxSetting));
  connections.push_back(pair<int, int>{6, 4});
  connections.push_back(pair<int, int>{6, 1});

  boxSetting = BoxSetting();
  boxFrames.push_back(BoxFrame());
  boxSetting.title = "Graph.cpp:";
  boxSetting.content = "Graph code";
  boxes.push_back(makeBox(Graph_lib::Point{ 10, 290 }, *boxFrames.rbegin(), boxSetting));
  connections.push_back(pair<int, int>{7, 3});

  boxSetting = BoxSetting();
  boxFrames.push_back(BoxFrame());
  boxSetting.title = "Simple_window.h:";
  boxSetting.content = "// window interface:\nclass Simple_window { ... };\n...";
  boxes.push_back(makeBox(Graph_lib::Point{ 170, 290 }, *boxFrames.rbegin(), boxSetting));
  connections.push_back(pair<int, int>{8, 4});
  connections.push_back(pair<int, int>{8, 6});

  boxSetting = BoxSetting();
  boxFrames.push_back(BoxFrame());
  boxSetting.title = "GUI.cpp:";
  boxSetting.content = "GUI code";
  boxes.push_back(makeBox(Graph_lib::Point{ 420, 290 }, *boxFrames.rbegin(), boxSetting));
  connections.push_back(pair<int, int>{9, 6});

  boxSetting = BoxSetting();
  boxFrames.push_back(BoxFrame());
  boxSetting.title = "CH12P438EXERC10_FLTKRunExmple.cpp:";
  boxSetting.content = "#include \"CH12P438EXERC10_FLTKRunExmple.h\"\n#include \"std_lib_facilities.h\"\n#include \"Simple_window.h\"\n#include \"Graph.h\"\n...";
  boxes.push_back(makeBox(Graph_lib::Point{ 40, 380 }, *boxFrames.rbegin(), boxSetting));
  connections.push_back(pair<int, int>{10, 3});
  connections.push_back(pair<int, int>{10, 8});

  vector<Arrow*> arrows;
  for (pair<int, int> connection : connections)
  {
    // start
    Graph_lib::Point topRightBoundPoint{
      (boxFrames[connection.first].mRightBottomCorner.x - boxFrames[connection.first].mLeftUpperCorner.x)/2 + boxFrames[connection.first].mLeftUpperCorner.x,
      boxFrames[connection.first].mLeftUpperCorner.y,
    };
    // end
    Graph_lib::Point bottomCenterBoundPoint{
      (boxFrames[connection.second].mRightBottomCorner.x - boxFrames[connection.second].mLeftUpperCorner.x) / 2 + boxFrames[connection.second].mLeftUpperCorner.x,
      boxFrames[connection.second].mRightBottomCorner.y,
    };
    Arrow* arrow = new Arrow(topRightBoundPoint, bottomCenterBoundPoint, arrowLength, arrowWidth);
    arrow->set_fill_color(Graph_lib::Color::black);
    arrow->set_color(Graph_lib::Color::black);
    arrows.push_back(arrow);
  }

  for (vector<Graph_lib::Shape*> box : boxes)
  {
    for (Graph_lib::Shape* item : box)
    {
      sWindow.attach(*item);
    }
  }

  for (Graph_lib::Shape* item : arrows)
  {
    sWindow.attach(*item);
  }

  //sWindow.attach(arrow);
  sWindow.wait_for_button();

  for (vector<Graph_lib::Shape*> box : boxes)
  {
    for (Graph_lib::Shape* item : box)
    {
      delete item;
    }
  }

  for (Graph_lib::Shape* item : arrows)
  {
    delete item;
  }

	return 0;
}