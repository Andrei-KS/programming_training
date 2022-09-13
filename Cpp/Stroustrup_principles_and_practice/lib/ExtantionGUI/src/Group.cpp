/*
  Group.cpp
  author  : Andrei-KS
*/

#include "Group.h"

namespace Graph_lib {
  Group::Group()
  {
  }

  Group::~Group()
  {
    for (int i = 0; i < mOwnedShapes.size(); ++i)
    {
      delete mOwnedShapes[i];
    }
  }

  void Group::attach(Shape& shape)
  {
    for (Shape* item : mShapes)
    {
      if (item == &shape)
      {
        return;
      }
    }
    mShapes.push_back(&shape);
  }

  void Group::attach(Shape* shape)
  {
    mShapes.push_back(shape);
    mOwnedShapes.push_back(shape);
  }

  void Group::detach(Shape& shape)
  {
    vector<Shape*>::iterator it = mShapes.begin();
    while (it != mShapes.end())
    {
      if (*it == &shape)
      {
        mShapes.erase(it);
        break;
      }
      it++;
    }
  }

  /*
  */
  Shape& Group::operator[](int i)
  {
    return *mShapes[i];
  }

  /*
  */
  const Shape& Group::operator[](int i) const
  {
    return *mShapes[i];
  }

  /*
  */
  int Group::size() const
  {
    return mShapes.size();
  }

  /*
  */
  void Group::draw_lines() const
  {
    for (Shape* item : mShapes)
    {
      item->draw();
    }
  }

  /*
  */
  void Group::move(int dx, int dy)
  {
    for (Shape* item : mShapes)
    {
      item->move(dx,dy);
    }
  }
}