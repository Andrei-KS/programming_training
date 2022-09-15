/*
  Binary_tree.cpp
  author  : Andrei-KS
*/

#include "Binary_tree.h"
#include "Vector2D.h"

namespace {
  constexpr int DEFAULT_NODE_SIZE = 20;
  constexpr double Y_NODE_DISTANCE_RATIO = 1.0 / 2;
  constexpr double X_HALF_BOTTOM_NODE_DISTANCE_RATIO = 1.0 / 4;

  void draw_arrow(const Graph_lib::Point& start, const Graph_lib::Point& end, const double arrowLenght, const double arrowWidth)
  {
    Utility_lib::Vector2D unitVectorLine = Utility_lib::Vector2D{ static_cast<double>(end.x - start.x), static_cast<double>(end.y - start.y) }.getUnitVector();
    Utility_lib::Vector2D normalToVector = unitVectorLine.getNormal();
    unitVectorLine.x *= arrowLenght;
    unitVectorLine.y *= arrowLenght;
    normalToVector.x *= static_cast<double>(arrowWidth) / 2;
    normalToVector.y *= static_cast<double>(arrowWidth) / 2;


    fl_begin_complex_polygon();
    fl_vertex(end.x - static_cast<int>(unitVectorLine.x) + static_cast<int>(normalToVector.x), end.y - static_cast<int>(unitVectorLine.y) + static_cast<int>(normalToVector.y));
    fl_vertex(end.x, end.y);
    fl_vertex(end.x - static_cast<int>(unitVectorLine.x) - static_cast<int>(normalToVector.x), end.y - static_cast<int>(unitVectorLine.y) - static_cast<int>(normalToVector.y));

    fl_end_complex_polygon();
  }
}

namespace Graph_lib {
  Binary_tree::Binary_tree(const Point& leftTopCorner, int levels, ConnectorInfo connectorInfo)
    : mLevels(0)
    , mBoundingRectangleWidth(0)
    , mBoundingRectangleHeight(0)
    , mNodeSize(DEFAULT_NODE_SIZE)
    , mConnectorInfo(connectorInfo)
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

  void Binary_tree::draw_node(const Point& center) const
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

  void Binary_tree::draw_connecter_line(const Point& start, const Point& end) const
  {
    
    fl_color(mConnectorInfo.color.as_int());
    fl_line_style(mConnectorInfo.lineStyle.style(), mConnectorInfo.lineStyle.width());

    int sign = end.x - start.x > 0 ? 1 : -1;
    fl_line(start.x + sign*node_size()/4, start.y + node_size() / 2, end.x - sign * node_size() / 4, end.y - node_size() / 2);
    fl_line_style(Graph_lib::Line_style::solid, mConnectorInfo.lineStyle.width());

    double arrowLenght = mConnectorInfo.arrowLenghtRatio * node_size();
    double arrowWidth = mConnectorInfo.arrowWidthRatio * node_size();
    switch (mConnectorInfo.type)
    {
      case ConnectorInfo::TypeConnector::None:
      {
        break;
      }
      case ConnectorInfo::TypeConnector::ArrowToStart:
      {
        draw_arrow({ end.x - sign * node_size() / 4, end.y - node_size() / 2 }, { start.x + sign * node_size() / 4, start.y + node_size() / 2 }, arrowLenght, arrowWidth);
        break;
      }
      case ConnectorInfo::TypeConnector::ArrowToEnd:
      {
        draw_arrow({ start.x + sign * node_size() / 4, start.y + node_size() / 2 }, { end.x - sign * node_size() / 4, end.y - node_size() / 2 }, arrowLenght, arrowWidth);
        break;
      }
      case ConnectorInfo::TypeConnector::ArrowToBothPoint:
      {
        draw_arrow({ start.x + sign * node_size() / 4, start.y + node_size() / 2 }, { end.x - sign * node_size() / 4, end.y - node_size() / 2 }, arrowLenght, arrowWidth);
        draw_arrow({ end.x - sign * node_size() / 4, end.y - node_size() / 2 }, { start.x + sign * node_size() / 4, start.y + node_size() / 2 }, arrowLenght, arrowWidth);
        break;
      }
      default:
      {
        error("Binary_tree: draw_connecter_line: TypeConnector is wrong");
      }
    }
    fl_color(color().as_int());
    fl_line_style(style().style(),style().width());
  }

  void Binary_tree::recalculate_node_center_positions()
  {
    if (levels() == 0)
    {
      return;
    }

    const int yNodeDistance = static_cast<int>(node_size() * Y_NODE_DISTANCE_RATIO);
    const int xHalfBottomNodeDistance = static_cast<int>(node_size() * X_HALF_BOTTOM_NODE_DISTANCE_RATIO);

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