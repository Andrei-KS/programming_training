/*
  Binary_tree.cpp
  author  : Andrei-KS
*/

#include "Binary_tree.h"

namespace {
  constexpr int DEFAULT_NODE_SIZE = 20;
}

namespace Graph_lib {
  Binary_tree::Binary_tree(Point leftTopCorner, int levels)
    : mLevels(0)
    , mBoundingRectangleWidth(0)
    , mBoundingRectangleHeight(0)
    , mNodeSize(DEFAULT_NODE_SIZE)
  {
    if (levels < 0)
    {
      error("Binary_tree: Binary_tree: levels less than zero");
    }
    Shape::add(leftTopCorner);
    set_levels(levels);
  }

  void Binary_tree::draw_lines() const
  {
    int size = mNodePositions.size() - (1 << (levels() - 1));
    for (int index = 0; index < size; index++)
    {
      draw_connecter_line(mNodePositions[index], mNodePositions[2 * index + 1]);
      draw_connecter_line(mNodePositions[index], mNodePositions[2 * index + 2]);
    }

    for (const Point& nodePosition : mNodePositions)
    {
      draw_node(nodePosition);
    }

  }

  Point Binary_tree::bounding_rectangle_left_top_corner() const
  {
    return point(0);
  }

  int Binary_tree::bounding_rectangle_width() const
  {
    return mBoundingRectangleWidth;
  }

  int Binary_tree::bounding_rectangle_height() const
  {
    return mBoundingRectangleHeight;
  }

  int Binary_tree::node_size() const
  {
    return mNodeSize;
  }

  void Binary_tree::set_node_size(int size)
  {
    mNodeSize = size;
    recalculate_node_center_positions();
  }

  int Binary_tree::levels() const
  {
    return mLevels;
  }

  void Binary_tree::set_levels(int levels)
  {
    if (levels < 0)
    {
      error("Binary_tree: set_levels: levels less than zero");
    }
    mLevels = levels;
    mNodePositions.clear();
    
    if (mLevels == 0)
    {
      return;
    }

    int nodesAmount = 0;
    int nodesOnLevel = 1;
    while (levels--)
    {
      nodesAmount += nodesOnLevel;
      nodesOnLevel = nodesOnLevel << 1;
    }

    mNodePositions.insert(mNodePositions.begin(), nodesAmount, Point{ 0,0 });
    recalculate_node_center_positions();
  }

  void Binary_tree::draw_node(Point center) const
  {
    if (fill_color().visibility()) {	// fill
      fl_color(fill_color().as_int());
      fl_pie(center.x - node_size() / 2, center.y - node_size() / 2, node_size() - 1, node_size() - 1, 0, 360);
      fl_color(color().as_int());	// reset color
    }

    if (color().visibility()) {
      fl_color(color().as_int());
      fl_arc(center.x - node_size() / 2, center.y - node_size() / 2, node_size() - 1, node_size() - 1, 0, 360);
    }
  }

  void Binary_tree::draw_connecter_line(Point start, Point end) const
  {
    fl_line(start.x, start.y, end.x, end.y);
  }

  void Binary_tree::recalculate_node_center_positions()
  {
    if (levels() == 0)
    {
      return;
    }

    const int yNodeDistance = node_size() * 1 / 4;
    const int xHalfBottomNodeDistance = node_size() * 1 / 4;

    // fill the bottom level of binary tree
    int processedNodesAmount = 0;
    int nodesAmountOnLevel = 1;
    int currentXShift = (xHalfBottomNodeDistance * 2 + node_size()) << (levels() - 1);
    int currentYPosition = bounding_rectangle_left_top_corner().y + node_size() / 2;
    for (int currentLevel = 0; currentLevel < levels(); currentLevel++)
    {
      for (int indexNodeOnLevel = 0; indexNodeOnLevel < nodesAmountOnLevel; indexNodeOnLevel++)
      {
        mNodePositions[indexNodeOnLevel + processedNodesAmount].x = bounding_rectangle_left_top_corner().x + currentXShift * indexNodeOnLevel - xHalfBottomNodeDistance + currentXShift / 2;
        mNodePositions[indexNodeOnLevel + processedNodesAmount].y = currentYPosition;
      }
      currentYPosition += yNodeDistance + node_size();
      processedNodesAmount += nodesAmountOnLevel;
      nodesAmountOnLevel = nodesAmountOnLevel << 1;
      currentXShift = currentXShift >> 1;
    }
    mBoundingRectangleHeight = (*mNodePositions.rbegin()).y - bounding_rectangle_left_top_corner().y + node_size() / 2;
    mBoundingRectangleWidth = (*mNodePositions.rbegin()).x - bounding_rectangle_left_top_corner().x + node_size() / 2;
  }

  Triangle_Binary_tree::Triangle_Binary_tree(Point leftTopCorner, int levels)
    : Binary_tree(leftTopCorner, levels)
  {
  }

  void Triangle_Binary_tree::draw_node(Point center) const
  {
    if (fill_color().visibility()) {
      fl_color(fill_color().as_int());
      fl_begin_complex_polygon();

      fl_vertex(center.x, center.y - node_size()/2);
      fl_vertex(center.x - node_size() / 2, center.y + node_size() / 2);
      fl_vertex(center.x + node_size() / 2, center.y + node_size() / 2);

      fl_end_complex_polygon();
      fl_color(color().as_int());	// reset color
    }

    if (color().visibility())
      Shape::draw_lines();
  }
}