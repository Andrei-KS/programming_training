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
    , mDisplayPoint(vector<Graph_lib::Point>(6))
  {
    int lineLengthSqr = (end.x - start.x) * (end.x - start.x) + (end.y - start.y) * (end.y - start.y);
    if (lineLengthSqr < arrowheadLength * arrowheadLength)
    {
      error("Bad arrow: arrowhead length greater than line length");
    }

    if (std::abs(start.x - end.x) < Utility_lib::EPS && std::abs(start.y - end.y) < Utility_lib::EPS)
    {
      error("start and end are equal");
    }

    mDisplayPoint[0] = start;
    mDisplayPoint[3] = end;
    calculateArrow();
  }

  void Arrow::rotate(double angle)
  {
    Utility_lib::Vector2D rotatedVector = Utility_lib::getRotateVector(Utility_lib::Vector2D{ static_cast<double>(mDisplayPoint[3].x - mDisplayPoint[0].x), static_cast<double>(mDisplayPoint[3].y - mDisplayPoint[0].y) }, angle);
    mDisplayPoint[3].x = rotatedVector.x + mDisplayPoint[0].x;
    mDisplayPoint[3].y = rotatedVector.y + mDisplayPoint[0].y;
    calculateArrow();
  }

  void Arrow::setDirection(double angle)
  {
    double length = Utility_lib::getLength(Utility_lib::Vector2D{ static_cast<double>(mDisplayPoint[3].x - mDisplayPoint[0].x), static_cast<double>(mDisplayPoint[3].y - mDisplayPoint[0].y) });
    Utility_lib::Vector2D direction{ length , 0 };
    direction.rotate(angle);
    mDisplayPoint[3].x = direction.x + mDisplayPoint[0].x;
    mDisplayPoint[3].y = direction.y + mDisplayPoint[0].y;
    calculateArrow();
  }

  void Arrow::move(int dx, int dy)
  {
    for (unsigned int i = 1; i < mDisplayPoint.size(); ++i)
    {
      mDisplayPoint[i].x = dx;
      mDisplayPoint[i].y = dy;
    }
  }

  void Arrow::draw_lines() const
  {
    if (fill_color().visibility()) {
      // fill
      fl_color(fill_color().as_int());
      fl_begin_complex_polygon();
      for (int i = 1; i < mDisplayPoint.size()-1; ++i) {
        fl_vertex(mDisplayPoint[i].x, mDisplayPoint[i].y);
      }
      fl_end_complex_polygon();
      // reset color
      fl_color(color().as_int());	
    }

    if (color().visibility())	// draw sole pixel?
      for (unsigned int i = 1; i < mDisplayPoint.size(); ++i)
        fl_line(mDisplayPoint[i - 1].x, mDisplayPoint[i - 1].y, mDisplayPoint[i].x, mDisplayPoint[i].y);
  }

  void Arrow::calculateArrow()
  {
    Graph_lib::Point& end = mDisplayPoint[3];
    Graph_lib::Point& start = mDisplayPoint[0];

    Utility_lib::Vector2D unitVectorLine = Utility_lib::Vector2D{ static_cast<double>(end.x - start.x), static_cast<double>(end.y - start.y) }.getUnitVector();
    Utility_lib::Vector2D normalToVector = unitVectorLine.getNormal();
    unitVectorLine.x *= mArrowheadLength;
    unitVectorLine.y *= mArrowheadLength;
    normalToVector.x *= static_cast<double>(mArrowheadWidth) / 2;
    normalToVector.y *= static_cast<double>(mArrowheadWidth) / 2;

    mDisplayPoint[1].x = end.x - static_cast<int>(unitVectorLine.x);
    mDisplayPoint[1].y = end.y - static_cast<int>(unitVectorLine.y);
    
    mDisplayPoint[2].x = end.x - static_cast<int>(unitVectorLine.x) + static_cast<int>(normalToVector.x);
    mDisplayPoint[2].y = end.y - static_cast<int>(unitVectorLine.y) + static_cast<int>(normalToVector.y);
    
    mDisplayPoint[4].x = end.x - static_cast<int>(unitVectorLine.x) - static_cast<int>(normalToVector.x);
    mDisplayPoint[4].y = end.y - static_cast<int>(unitVectorLine.y) - static_cast<int>(normalToVector.y);

    mDisplayPoint[5].x = end.x - static_cast<int>(unitVectorLine.x);
    mDisplayPoint[5].y = end.y - static_cast<int>(unitVectorLine.y);
  }
}