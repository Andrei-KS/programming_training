/*
  Binary_tree.h
  author  : Andrei-KS
*/

#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  struct Binary_tree : Shape {
    /*
    */
    Binary_tree(Point leftTopCorner, int levels);

    /*
    */
    void draw_lines() const;

    /*
    */
    Point bounding_rectangle_left_top_corner() const;

    /*
    */
    int bounding_rectangle_width() const;

    /*
    */
    int bounding_rectangle_height() const;

    /*
    */
    int node_size() const;

    /*
    */
    void set_node_size(int size);

    /*
    */
    int levels() const;

    /*
    */
    void set_levels(int levels);

  protected:
    /*
    */
    virtual void draw_node(Point center) const;

    /*
    */
    virtual void draw_connecter_line(Point start, Point end) const;

  private:
    /*
    */
    void recalculate_node_center_positions();

    /**/
    int mLevels;

    /**/
    int mBoundingRectangleWidth;

    /**/
    int mBoundingRectangleHeight;

    /**/
    int mNodeSize;

    /**/
    vector<Point> mNodePositions;
  };
}

#endif // !__BINARY_TREE_H__