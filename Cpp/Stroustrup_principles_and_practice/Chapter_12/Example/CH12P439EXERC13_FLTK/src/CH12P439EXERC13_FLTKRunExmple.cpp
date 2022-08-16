/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/16/2022 17:18:29
	author                                          : Andrei-KS
*/

#include "CH12P439EXERC13_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P439EXERC13_FLTKRunExmple();

namespace {
  //     !!!
  //    !!!!!
  //    !!!!!
  //    !!!!!
  //    !!!!!
  //    !!!!!
  //     !!!
  //     !!!
  //      !
  //     
  //      !
  //     !!!
  //      !
  //     
  // Attention: The current solution has not uniform distribution by axis Y
  
  const double eps = 0.001;

  // The simple window setting
  constexpr int xUpperLeftWindowCorner = 100;
  constexpr int yUpperLeftWindowCorner = 100;
  constexpr int windowWidth = 1000;
  constexpr int windowHeight = 1000;

  // The superellipse setting
  constexpr int pointsAmountOnQuadrant = 10;
  const int maxNeighboringConnectDistance = 3;
  const int xCenter = windowWidth / 2;
  const int yCenter = windowHeight / 2;
  const int m = 2;
  const int n = 2;
  const double a = 100;
  const double b = 100;
  const vector<Graph_lib::Color> colorSet = {
    Graph_lib::Color::red,
    Graph_lib::Color::blue,
    Graph_lib::Color::green,
  };
  // The function setting
  // A superellipse is a two-dimensional shape defined by the equation
  //     m     n
  //  |x|   |y|
  //  |-| + |-| = 1  m,n > 0.  
  //  |a|   |b|
  // 
  //  Quadrants:
  //              |
  //     fourth   | first
  //              |
  //  ------------|------------>
  //              |
  //     third    | second
  //              |
  struct SuperellipseFuncForFirstQuadrant {
    SuperellipseFuncForFirstQuadrant(double a, double b, int n, int m)
      : ma(a)
      , mb(b)
      , mn(n)
      , mm(m)
      , mpa(1)
    {
      if (n <= 0 || m <= 0)
      {
        error("n and m have to be positive integer");
      }
      if (a <= eps || b <= eps)
      {
        error("n and m have not to near zero, where eps =", eps);
      }
      mpa = std::pow(ma, m);
      if (mpa <= eps)
      {
        error("pow(a,n) have not to near zero, where eps =", eps);
      }
    }

    double operator()(double x)
    {
      double result = 1 - powf(x, mm) / mpa;
      if ((n % 2 == 0) && result <= eps)
      {
        error("1 - powf(x/a, m) < 0, where n is even");
      }
      return mb * powf(result, 1.0 / mn);
    }
    double getXSize() { return ma; }
  private:
    double ma;
    double mb;
    double mpa;
    int mn;
    int mm;
  };
}

int CH12P439EXERC13_FLTKRunExmple::excute()
{
  // Make the simple window
  Graph_lib::Point upperLeftWindowcorner(xUpperLeftWindowCorner, yUpperLeftWindowCorner);
  Graph_lib::Simple_window sWindow(upperLeftWindowcorner, windowWidth, windowHeight, "EXERC12");

  vector<Graph_lib::Lines*> superellipses;
  SuperellipseFuncForFirstQuadrant sfffq(a, b, n, m);
  if (pointsAmountOnQuadrant > 0)
  {
    vector<Graph_lib::Point> superellipsePoints;
    const int maxRight = static_cast<int>(sfffq.getXSize());
    const int adjustedPointsAmountOnQuadrant = (pointsAmountOnQuadrant > maxRight ? maxRight : pointsAmountOnQuadrant) - 1;
    if (adjustedPointsAmountOnQuadrant > 0)
    {
      const int delta = maxRight / adjustedPointsAmountOnQuadrant;
      // make first
      for (int index = 0; index < adjustedPointsAmountOnQuadrant; index++)
      {
        int currX = delta * index;
        superellipsePoints.push_back(Graph_lib::Point{ currX, -static_cast<int>(sfffq(currX)) });
      }
      superellipsePoints.push_back(Graph_lib::Point{ maxRight, 0 });
    }

    // second quadrant
    for (int index = adjustedPointsAmountOnQuadrant - 1; index > 0; index--)
    {
      superellipsePoints.push_back(Graph_lib::Point{ superellipsePoints[index].x + xCenter, -superellipsePoints[index].y + yCenter });
    }
    superellipsePoints.push_back(Graph_lib::Point{ superellipsePoints[0].x + xCenter, -superellipsePoints[0].y + yCenter });

    // third quadrant
    for (int index = 1; index < adjustedPointsAmountOnQuadrant; index++)
    {
      superellipsePoints.push_back(Graph_lib::Point{ -superellipsePoints[index].x + xCenter, -superellipsePoints[index].y + yCenter });
    }
    superellipsePoints.push_back(Graph_lib::Point{ -superellipsePoints[adjustedPointsAmountOnQuadrant].x + xCenter, -superellipsePoints[adjustedPointsAmountOnQuadrant].y + yCenter });
    // fourth quadrant
    for (int index = adjustedPointsAmountOnQuadrant - 1; index > 0; index--)
    {
      superellipsePoints.push_back(Graph_lib::Point{ -superellipsePoints[index].x + xCenter, superellipsePoints[index].y + yCenter });
    }

    // adjust first quadrant
    for (int index = 0; index < adjustedPointsAmountOnQuadrant + 1; index++)
    {
      superellipsePoints[index].x += xCenter;
      superellipsePoints[index].y += yCenter;
    }

    for (int neighboringConnectDistance = 1; neighboringConnectDistance <= maxNeighboringConnectDistance; neighboringConnectDistance++)
    {
      Graph_lib::Lines* superellipse = new Graph_lib::Lines();
      const int sizeSuperellipsePoints = superellipsePoints.size();
      for (int index = 0; index < sizeSuperellipsePoints; index++)
      {
      
        superellipse->add(superellipsePoints[index], superellipsePoints[(index + neighboringConnectDistance) % sizeSuperellipsePoints]);
      }
      superellipse->set_color(colorSet[(neighboringConnectDistance - 1) % colorSet.size()]);
      superellipses.push_back(superellipse);
      sWindow.attach(*superellipse);
    }
    
  }

  //sWindow.attach(arrow);
  sWindow.wait_for_button();
  for(Graph_lib::Lines* superellipse : superellipses)
  {
    delete superellipse;
  }
	return 0;
}