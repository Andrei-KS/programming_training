/*
  Box.h
  author  : Andrei-KS
*/

#ifndef __BOX_H__
#define __BOX_H__

#include "Graph.h"

namespace Graph_lib{
  /*
  * class Box, consisting of four lines and four arcs
  */
  struct Box : Shape {
    /*
    */
    Box(Point topLeftCorner, int width, int height, int cornerRoundingWidth, int cornerRoundingHeight);

    /*
    */
    Box(Point topLeftCorner, int width, int height, int cornerRoundingSize);

    /*
    */
    Box(Point topLeftCorner, Point bottomRightCorner, int cornerRoundingWidth, int cornerRoundingHeight);

    /*
    */
    Box(Point topLeftCorner, Point bottomRightCorner, int cornerRoundingSize);
    
    /*
    */
    void draw_lines() const;

    /*
    */
    int width() const;
    
    /*
    */
    int height() const;

    /*
    */
    int cornerRoundingWidth() const;

    /*
    */
    int cornerRoundingHeight() const;

  private:
    /**/
    int mWidth;

    /**/
    int mHeight;

    /**/
    int mCornerRoundingWidth;
    
    /**/
    int mCornerRoundingHeight;
  };
}
#endif // !__BOX_H__