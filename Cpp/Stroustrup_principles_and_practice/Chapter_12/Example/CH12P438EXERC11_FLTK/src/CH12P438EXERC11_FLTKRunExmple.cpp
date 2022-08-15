/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/12/2022 15:44:22
	author                                          : Andrei-KS
*/

#include "CH12P438EXERC11_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH12P438EXERC11_FLTKRunExmple();

namespace {
  const double eps = 0.001;

  // The simple window setting
  constexpr int xUpperLeftWindowCorner = 100;
  constexpr int yUpperLeftWindowCorner = 100;
  constexpr int windowWidth = 1000;
  constexpr int windowHeight = 1000;

  // First Shapes settings
  const int fShapesAmount = 10;
  const int xFCenter = windowWidth/2 - 100;
  const int yFCenter = windowHeight/2;
  const int inscribedCircleRadiusInFirstShape = 10;
  const double startAngle = -120/2;

  // Second Shape setting
  const int sShapesAmount = 8;
  const int xSCenter = windowWidth / 2;
  const int ySCenter = windowHeight / 2;
  const int sideSShapeLenght = 20;
  const double startSAngle = 0;

  // Third Shape setting
  const int oThapesAmount = 6;
  const int xTSCenter = windowWidth / 2 + 100;
  const int yTSCenter = windowHeight / 2;
  const int sideTShapeLenght = 20;
  const double startTAngle = 0;

  struct Vector2D
  {
    double x;
    double y;
  };

  inline double toRadian(double angle)
  {
    return angle / 180 * std::_Pi;
  }

  Vector2D rotateTo(const Vector2D& vect, const double angle)
  {
    double valueInRadian = toRadian(angle);
    return Vector2D{ vect.x * cos(valueInRadian) - vect.y * sin(valueInRadian), vect.x * sin(valueInRadian) + vect.y * cos(valueInRadian) };
  }
  
  int toInt(double value)
  {
    value *= 10;
    int result = static_cast<int>(value);
    return result / 10 + ((result % 10) > 5 ? 1 : 0);
  }

}

int CH12P438EXERC11_FLTKRunExmple::excute()
{
  // Make the simple window
  Graph_lib::Point upperLeftWindowcorner(xUpperLeftWindowCorner, yUpperLeftWindowCorner);
  Graph_lib::Simple_window sWindow(upperLeftWindowcorner, windowWidth, windowHeight, "EXERC11");

  vector<Graph_lib::Shape*> shapes;

  // make first shape
  {
    Vector2D fDirection = rotateTo(Vector2D{ 0, 1 }, startAngle);
    Vector2D fCenter{ xFCenter , yFCenter };
    double inscribedCircleRadiusInShape = inscribedCircleRadiusInFirstShape;

    for (int index = 0; index < fShapesAmount; index++)
    {
      Graph_lib::Polygon* polygon = new Graph_lib::Polygon;
      int amountAngle = 3 + index;
      double rotateAngle = 360 / amountAngle;
      double otherAngle = 90 - rotateAngle / 2;
      double length = inscribedCircleRadiusInShape / sin(toRadian(otherAngle));
      double adjacentÑathetLenght = inscribedCircleRadiusInShape * cos(toRadian(otherAngle));
      fDirection = rotateTo(fDirection, rotateAngle / 2);

      for (int indexAngle = 0; indexAngle < amountAngle; indexAngle++)
      {
        Vector2D currentDirect = rotateTo(fDirection, rotateAngle * indexAngle);
        polygon->add(Graph_lib::Point{ static_cast<int>(currentDirect.x * length) + xFCenter, static_cast<int>(currentDirect.y * length) + yFCenter});
      }
      inscribedCircleRadiusInShape = length;
      polygon->set_color(Graph_lib::Color::red);
      shapes.push_back(polygon);
    }
  }

  // make second shape
  {
    Vector2D sDirection = rotateTo(Vector2D{ 0, 1 }, startSAngle);
    double sideHalfLenght = sideSShapeLenght / 2;
    double prevLength = sideHalfLenght / sin(toRadian(120.0 / 2));

    for (int index = 0; index < sShapesAmount; index++)
    {
      Graph_lib::Polygon* polygon = new Graph_lib::Polygon;
      int amountAngle = 3 + index;
      double rotateAngle = 360 / amountAngle;
      double length = sideHalfLenght / sin(toRadian(rotateAngle / 2));
      double diffLength = length - prevLength;
      Vector2D currentCenter{ xSCenter - sDirection.x * diffLength, ySCenter - sDirection.y * diffLength};
      for (int indexAngle = 0; indexAngle < amountAngle; indexAngle++)
      {
        Vector2D currentDirect = rotateTo(sDirection, rotateAngle * indexAngle);
        polygon->add(Graph_lib::Point{ static_cast<int>(currentDirect.x * length + currentCenter.x), static_cast<int>(currentDirect.y * length + currentCenter.y) });
      }
      polygon->set_color(Graph_lib::Color::black);
      shapes.push_back(polygon);
    }
  }

  // make third shape
  {
    Vector2D tDirection = rotateTo(Vector2D{ 0, 1 }, startTAngle);
    double prevSideLength = sideTShapeLenght * cos(toRadian(30));
    double prevAngle = 0;
    for (int index = 0; index < oThapesAmount; index++)
    {
      Graph_lib::Polygon* polygon = new Graph_lib::Polygon;
      int amountAngle = 3 + index;
      double rotateAngle = 360 / amountAngle;
      double currentAngle = (180 - rotateAngle) / 2;
      double currentSideLength = prevSideLength * cos(toRadian(3.0 * currentAngle - prevAngle - 90)) / cos(toRadian(90 - 2.0 * currentAngle));
      double circumscribedCircleRadius = currentSideLength / 2.0 / cos(toRadian(currentAngle));

      Vector2D currentCenter{ xTSCenter - tDirection.x * circumscribedCircleRadius, yTSCenter - tDirection.y * circumscribedCircleRadius };

      for (int indexAngle = 0; indexAngle < amountAngle; indexAngle++)
      {
        Vector2D currentDirect = rotateTo(tDirection, rotateAngle * indexAngle);
        polygon->add(Graph_lib::Point{ toInt(currentDirect.x * circumscribedCircleRadius + currentCenter.x), toInt(currentDirect.y * circumscribedCircleRadius + currentCenter.y) });
      }

      polygon->set_color(Graph_lib::Color::blue);
      shapes.push_back(polygon);

      prevAngle = currentAngle;
      prevSideLength = currentSideLength;
    }
  }


  
  for (Graph_lib::Shape* shape : shapes)
  {
    sWindow.attach(*shape);
  }
  //sWindow.attach(arrow);
  sWindow.wait_for_button();

  for (Graph_lib::Shape* shape : shapes)
  {
    delete shape;
  }
	return 0;
}