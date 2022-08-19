/*
  Arrow.cpp
  author  : Andrei-KS
*/

#include "Arrow.h"
#include <cmath>
#include "Utility_lib_Constatnt.h"
#include "Vector2D.h"

namespace Graph_lib {

  Arrow::Arrow(Point start, Point end, int arrowheadLength, int arrowheadWidth)
    : mArrowheadWidth(arrowheadWidth)
    , mArrowheadLength(arrowheadLength)
  {
    int lineLengthSqr = (end.x - start.x) * (end.x - start.x) + (end.y - start.y) * (end.y - start.y);
    if (lineLengthSqr < arrowheadLength * arrowheadLength)
    {
      error("Bad arrow: arrowhead length greater than line length");
    }
    add(start);

    if (std::abs(start.x - end.x) < Utility_lib::EPS && std::abs(start.y - end.y) < Utility_lib::EPS)
    {
      error("start and end are equal");
    }
    Utility_lib::Vector2D unitVectorLine = Utility_lib::Vector2D{ static_cast<double>(end.x - start.x), static_cast<double>(end.y - start.y) }.getUnitVector();
    Utility_lib::Vector2D normalToVector = unitVectorLine.getNormal();
    unitVectorLine.x *= arrowheadLength;
    unitVectorLine.y *= arrowheadLength;
    normalToVector.x *= static_cast<double>(arrowheadWidth) / 2;
    normalToVector.y *= static_cast<double>(arrowheadWidth) / 2;
    Shape::add(Graph_lib::Point{ end.x - static_cast<int>(unitVectorLine.x), end.y - static_cast<int>(unitVectorLine.y) });
    Shape::add(Graph_lib::Point{ end.x - static_cast<int>(unitVectorLine.x) + static_cast<int>(normalToVector.x), end.y - static_cast<int>(unitVectorLine.y) + static_cast<int>(normalToVector.y) });
    Shape::add(end);
    Shape::add(Graph_lib::Point{ end.x - static_cast<int>(unitVectorLine.x) - static_cast<int>(normalToVector.x), end.y - static_cast<int>(unitVectorLine.y) - static_cast<int>(normalToVector.y) });
    Shape::add(Graph_lib::Point{ end.x - static_cast<int>(unitVectorLine.x), end.y - static_cast<int>(unitVectorLine.y) });
  }


  void Arrow::draw_lines() const
  {
    if (fill_color().visibility()) {
      // fill
      fl_color(fill_color().as_int());
      fl_begin_complex_polygon();
      for (int i = 1; i < number_of_points()-1; ++i) {
        fl_vertex(point(i).x, point(i).y);
      }
      fl_end_complex_polygon();
      // reset color
      fl_color(color().as_int());	
    }

    if (color().visibility())
      Shape::draw_lines();
  }
}