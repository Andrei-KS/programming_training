/*
  Box.cpp
  author  : Andrei-KS
*/

#include "Box.h"

namespace Graph_lib {

  Box::Box(Point topLeftCorner, int width, int height, int cornerRoundingWidth, int cornerRoundingHeight)
    : mWidth(width)
    , mHeight(height)
    , mCornerRoundingWidth(cornerRoundingWidth)
    , mCornerRoundingHeight(cornerRoundingHeight)
  {
    if (mWidth <= 0 || mHeight <= 0)
    {
      error("Bad box: non-positive side");
    }
    if (mCornerRoundingWidth > width / 2)
    {
      error("Bad box: corner rounding width greater than half width");
    }
    if (mCornerRoundingHeight > height / 2)
    {
      error("Bad box: corner rounding height greater than half height");
    }
    add(topLeftCorner);
  }


  Box::Box(Point topLeftCorner, int width, int height, int cornerRoundingSize)
    : mWidth(width)
    , mHeight(height)
    , mCornerRoundingWidth(cornerRoundingSize)
    , mCornerRoundingHeight(cornerRoundingSize)
  {
    if (mWidth <= 0 || mHeight <= 0)
    {
      error("Bad box: non-positive side");
    }
    if (mCornerRoundingWidth > width / 2)
    {
      error("Bad box: corner rounding width greater than half width");
    }
    if (mCornerRoundingHeight > height / 2)
    {
      error("Bad box: corner rounding height greater than half height");
    }
    add(topLeftCorner);
  }


  Box::Box(Point topLeftCorner, Point bottomRightCorner, int cornerRoundingWidth, int cornerRoundingHeight)
    : mWidth(bottomRightCorner.x - topLeftCorner.x)
    , mHeight(bottomRightCorner.y - topLeftCorner.y)
    , mCornerRoundingWidth(cornerRoundingWidth)
    , mCornerRoundingHeight(cornerRoundingHeight)
  {
    if (mWidth <= 0 || mHeight <= 0)
    {
      error("Bad box: first point is not top left");
    }
    if (mCornerRoundingWidth > mWidth / 2)
    {
      error("Bad box: corner rounding width greater than half width");
    }
    if (mCornerRoundingHeight > mHeight / 2)
    {
      error("Bad box: corner rounding height greater than half height");
    }
    add(topLeftCorner);
  }


  Box::Box(Point topLeftCorner, Point bottomRightCorner, int cornerRoundingSize)
    : mWidth(bottomRightCorner.x - topLeftCorner.x)
    , mHeight(bottomRightCorner.y - topLeftCorner.y)
    , mCornerRoundingWidth(cornerRoundingSize)
    , mCornerRoundingHeight(cornerRoundingSize)
  {
    if (mWidth <= 0 || mHeight <= 0)
    {
      error("Bad box: first point is not top left");
    }
    if (mCornerRoundingWidth > mWidth / 2 )
    {
      error("Bad box: corner rounding width greater than half width");
    }
    if (mCornerRoundingHeight > mHeight / 2)
    {
      error("Bad box: corner rounding height greater than half height");
    }
    add(topLeftCorner);
  }


  void Box::draw_lines() const
  {
    const int cornerAmount = 4;

    if (fill_color().visibility()) {	// fill
      fl_color(fill_color().as_int());
      
      fl_rectf(point(0).x, point(0).y + mCornerRoundingHeight, mCornerRoundingWidth, mHeight - 2 * mCornerRoundingHeight);
      fl_rectf(point(0).x + mCornerRoundingWidth, point(0).y, mWidth - 2 * mCornerRoundingWidth, mHeight);
      fl_rectf(point(0).x + mWidth - mCornerRoundingWidth, point(0).y + mCornerRoundingHeight, mCornerRoundingWidth, mHeight - 2 * mCornerRoundingHeight);
      
      fl_pie(point(0).x, point(0).y, 2 * mCornerRoundingWidth, 2 * mCornerRoundingHeight, 90, 180);
      fl_pie(point(0).x, point(0).y + (mHeight - 2 * mCornerRoundingHeight), 2 * mCornerRoundingWidth, 2 * mCornerRoundingHeight, 180, 270);
      fl_pie(point(0).x + (mWidth - 2 * mCornerRoundingWidth), point(0).y + (mHeight - 2 * mCornerRoundingHeight), 2 * mCornerRoundingWidth, 2 * mCornerRoundingHeight, 270, 360);
      fl_pie(point(0).x + (mWidth - 2 * mCornerRoundingWidth), point(0).y, 2 * mCornerRoundingWidth, 2 * mCornerRoundingHeight, 0, 90);
    }

    if (color().visibility()) {	// edge on top of fill
      fl_color(color().as_int());
      fl_line(point(0).x + mCornerRoundingWidth, point(0).y, point(0).x + mWidth - mCornerRoundingWidth, point(0).y);
      fl_line(point(0).x + mWidth, point(0).y + mCornerRoundingHeight, point(0).x + mWidth, point(0).y + mHeight - mCornerRoundingHeight);
      fl_line(point(0).x + mCornerRoundingWidth, point(0).y + mHeight, point(0).x + mWidth - mCornerRoundingWidth, point(0).y + mHeight);
      fl_line(point(0).x, point(0).y + mCornerRoundingHeight, point(0).x, point(0).y + mHeight - mCornerRoundingHeight);

      fl_arc(point(0).x, point(0).y, 2 * mCornerRoundingWidth, 2 * mCornerRoundingHeight, 90, 180);
      fl_arc(point(0).x, point(0).y + (mHeight - 2 * mCornerRoundingHeight), 2 * mCornerRoundingWidth, 2 * mCornerRoundingHeight, 180, 270);
      fl_arc(point(0).x + (mWidth - 2 * mCornerRoundingWidth), point(0).y + (mHeight - 2 * mCornerRoundingHeight), 2 * mCornerRoundingWidth, 2 * mCornerRoundingHeight, 270, 360);
      fl_arc(point(0).x + (mWidth - 2 * mCornerRoundingWidth), point(0).y, 2 * mCornerRoundingWidth, 2 * mCornerRoundingHeight, 0, 90);
    }
  }

  int Box::width() const
  {
    return mWidth;
  }

  int Box::height() const
  {
    return mHeight;
  }

  int Box::cornerRoundingWidth() const
  {
    return mCornerRoundingWidth;
  }

  int Box::cornerRoundingHeight() const
  {
    return mCornerRoundingHeight;
  }

  void Box::setWidth(int width)
  {
    if (mCornerRoundingWidth > width / 2)
    {
      error("Bad box: corner rounding width greater than half width");
    }
    mWidth = width;
  }

  /*
  */
  void Box::setHeight(int height)
  {
    if (mCornerRoundingHeight > height / 2)
    {
      error("Bad box: corner rounding height greater than half height");
    }
    mHeight = height;
  }

  /*
  */
  void Box::setCornerRoundingSize(int cornerRoundingSize)
  {
    if (cornerRoundingSize > mWidth / 2)
    {
      error("Bad box: corner rounding width greater than half width");
    }
    if (cornerRoundingSize > mHeight / 2)
    {
      error("Bad box: corner rounding height greater than half height");
    }
    mCornerRoundingWidth = cornerRoundingSize;
    mCornerRoundingHeight = cornerRoundingSize;
  }

  /*
  */
  void Box::setCornerRoundingWidth(int cornerRoundingWidth)
  {
    if (cornerRoundingWidth > mWidth / 2)
    {
      error("Bad box: corner rounding width greater than half width");
    }
    mCornerRoundingWidth = cornerRoundingWidth;
  }

  /*
  */
  void Box::setCornerRoundingHeight(int cornerRoundingHeight)
  {
    if (cornerRoundingHeight > mHeight / 2)
    {
      error("Bad box: corner rounding height greater than half height");
    }
    mCornerRoundingHeight = cornerRoundingHeight;
  }
}