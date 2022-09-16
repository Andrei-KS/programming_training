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
    struct NodeInfo {
      Point center = Point{0,0};
      string text;
    };
    /*
    */
    struct ConnectorInfo {
      /*
      */
      enum class TypeConnector {
        None,
        ArrowToStart,
        ArrowToEnd,
        ArrowToBothPoint,
      };

      /**/
      Color color = Color::black;
      
      /**/
      Line_style lineStyle = Line_style{Line_style::dash,2};
      
      /**/
      TypeConnector type = TypeConnector::ArrowToBothPoint;

      /**/
      double arrowLenghtRatio = 1.0 / 4;

      /**/
      double arrowWidthRatio = 1.0 / 8;
    };
    /*
    */
    Binary_tree(const Point& leftTopCorner, int levels, ConnectorInfo connectorInfo = ConnectorInfo());

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

    /*
    */
    void set_node_text(const string& address, const string& text);

    /*
    */
    const string node_text(const string& address) const;

  protected:
    /*
    */
    virtual void draw_node(const NodeInfo& nodeInfo) const;

    /*
    */
    virtual void draw_connecter_line(const Point& start, const Point& end) const;

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
    vector<NodeInfo> mNodes;

    /**/
    ConnectorInfo mConnectorInfo;

    /**/
    Font mNodesFont;

    /**/
    int mNodesFontSize;
  };

  /*
  */
  struct Triangle_Binary_tree : Binary_tree {
    /*
    */
    Triangle_Binary_tree(Point leftTopCorner, int levels);

  protected:
    /*
    */
    void draw_node(Point center) const;
  };
}

#endif // !__BINARY_TREE_H__