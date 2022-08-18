/*
  Arc.h
  author  : Andrei-KS
*/

#ifndef __ARC_H__
#define __ARC_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  struct Arc : Shape{

  public:
    /*
    * @param center - of arc
    * @param xAxisHalfLength - of arc
    * @param yAxisHalfLength - of arc
    * @param start - of arc measured in degrees counter - clockwise from 3 o'clock.
    * @param end - of arc measured in degrees counter must be greater than or equal to start
    */
    Arc(Point center, int xAxisHalfLength, int yAxisHalfLength, double start, double end);

    /*
    */
    void draw_lines() const;
    
    /*
    */
    Point center() const;
    
    /*
    */
    int xAxisHalfLength() const;
    
    /*
    */
    int yAxisHalfLength() const;
    
    /*
    * @return start of arc measured in degrees counter - clockwise from 3 o'clock.
    */
    double start() const;
    
    /*
    * @return end of arc measured in degrees counter - clockwise from 3 o'clock.
    */
    double end() const;
    
    /*
    */
    void setXAxisHalfLength(int width);
    
    /*
    */
    void setYAxisHalfLength(int height);
    
    /*
    * @param start - of arc measured in degrees counter - clockwise from 3 o'clock.
    */
    void setStart(double start);
    
    /*
    * @param end - of arc measured in degrees counter must be greater than or equal to start
    */
    void setEnd(double end);

  private:
    /* The width of the bounding box of complete circle */
    int mXAxisLength;

    /* The height of the bounding box of complete circle */
    int mYAxisLength;

    /* The start of arc measured in degrees counter - clockwise from 3 o'clock */
    double mStart;
    
    /* The end of arc measured in degrees counter - clockwise from 3 o'clock */
    double mEnd;
  };
}
#endif // !__ARC_H__