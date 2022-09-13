/*
  Group.h
  author  : Andrei-KS
*/

#ifndef __GROUP_H__
#define __GROUP_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  struct Group : Shape {
    /*
    */
    Group();
    
    /*
    */
    ~Group();

    /*
    * add s to shape group
    */
    void attach(Shape& shape);

    /*
    * add s to shape group and transfer responsibility to delete
    */
    void attach(Shape* shape);

    /*
    * remove s from shape group
    */
    void detach(Shape& shape);

    /*
    */
    Shape& operator[](int i);
    
    /*
    */
    const Shape& operator[](int i) const;
    
    /*
    */
    int size() const;

    /*
    */
    void draw_lines() const;

    /*
    */
    virtual void move(int dx, int dy);


  protected:
    /**/
    vector<Shape*> mShapes;

    /**/
    vector<Shape*> mOwnedShapes;
  };
}

#endif // !__GROUP_H__