/*
  Hat.h
  author  : Andrei-KS
*/

#ifndef __HAT_H__
#define __HAT_H__

#include "Graph.h"

namespace Graph_lib {

  /*
  */
  class Hat : public Shape {
  public:
    /*
    */
    Hat(Point base, int width, int height);

    /*
    */
    Point base() const;

    /*
    */
    int width() const;

    /*
    */
    int height() const;

  protected:
    /*
    */
    void draw_lines() const = 0;

  private:
    /**/
    int mWidth;

    /**/
    int mHeight;
  };

  namespace Hats {
    /*
    */
    class Cap : public Hat {
    public:
      /*
      */
      Cap(Point base, int width, int height);

    protected:
      /*
      */
      void draw_lines() const override;
    };

    /*
    */
    class Cylinder : public Hat {
    public:
      /*
      */
      Cylinder(Point base, int width, int height);

    protected:
      /*
      */
      void draw_lines() const override;
    };
  }

}


#endif // !__HAT_H__