/*
  GUI_Utility_function.h
  author  : Andrei-KS
*/

#ifndef __UTILITY_FUNCTION_H__
#define __UTILITY_FUNCTION_H__

#include "Graph.h"

namespace Graph_lib {
  Point n(const Rectangle& rect);
  Point ne(const Rectangle& rect);
  Point nw(const Rectangle& rect);
  Point s(const Rectangle& rect);
  Point se(const Rectangle& rect);
  Point sw(const Rectangle& rect);
  Point e(const Rectangle& rect);
  Point w(const Rectangle& rect);
  Point center(const Rectangle& rect);
}


#endif // !__UTILITY_FUNCTION_H__