/*
  GUI_Utility_function.h
  author  : Andrei-KS
*/

#ifndef __UTILITY_FUNCTION_H__
#define __UTILITY_FUNCTION_H__

#include "Graph.h"
#include "Box.h"
#include "TextBox.h"

namespace Graph_lib {
//-------------------------------------- Rectangle
  Point n(const Rectangle& rect);
  Point ne(const Rectangle& rect);
  Point nw(const Rectangle& rect);
  Point s(const Rectangle& rect);
  Point se(const Rectangle& rect);
  Point sw(const Rectangle& rect);
  Point e(const Rectangle& rect);
  Point w(const Rectangle& rect);
  Point center(const Rectangle& rect);

//-------------------------------------- Circle
  Point n(const Circle& circle);
  Point ne(const Circle& circle);
  Point nw(const Circle& circle);
  Point s(const Circle& circle);
  Point se(const Circle& circle);
  Point sw(const Circle& circle);
  Point e(const Circle& circle);
  Point w(const Circle& circle);
  Point center(const Circle& circle);

//-------------------------------------- Ellipse
  Point n(const Ellipse& ellipse);
  Point ne(const Ellipse& ellipse);
  Point nw(const Ellipse& ellipse);
  Point s(const Ellipse& ellipse);
  Point se(const Ellipse& ellipse);
  Point sw(const Ellipse& ellipse);
  Point e(const Ellipse& ellipse);
  Point w(const Ellipse& ellipse);
  Point center(const Ellipse& circle);

//-------------------------------------- Box
  Point n(const Box& box);
  Point ne(const Box& box);
  Point nw(const Box& box);
  Point s(const Box& box);
  Point se(const Box& box);
  Point sw(const Box& box);
  Point e(const Box& box);
  Point w(const Box& box);
  Point center(const Box& box);

//-------------------------------------- TextBox
  Point n(const TextBox& textBox);
  Point ne(const TextBox& textBox);
  Point nw(const TextBox& textBox);
  Point s(const TextBox& textBox);
  Point se(const TextBox& textBox);
  Point sw(const TextBox& textBox);
  Point e(const TextBox& textBox);
  Point w(const TextBox& textBox);
  Point center(const TextBox& textBox);
}


#endif // !__UTILITY_FUNCTION_H__