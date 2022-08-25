/*
  Frowny.cpp
  author  : Andrei-KS
*/

#include "Frowny.h"

namespace Graph_lib {
  Frowny::Frowny(Point center, int radius)
    : Circle(center, radius)
  {
  }

  void Frowny::draw_lines() const
  {
    Circle::draw_lines();

    int valueROnRoot2Per2 = static_cast<int>(sqrt(2.0) * radius() / 2);

    if (fill_color().visibility()) {	// fill
      fl_color(color().as_int());
      fl_pie(center().x - valueROnRoot2Per2 * 7 / 6, center().y - radius() / 2, valueROnRoot2Per2 - 1, valueROnRoot2Per2 - 1, 0, 360);
      fl_pie(center().x + valueROnRoot2Per2 * 1 / 6, center().y - radius() / 2, valueROnRoot2Per2 - 1, valueROnRoot2Per2 - 1, 0, 360);
      fl_color(color().as_int());	// reset color
    }

    if (color().visibility()) {
      fl_color(color().as_int());
      fl_arc(center().x - valueROnRoot2Per2 * 7 / 6, center().y - radius() / 2, valueROnRoot2Per2, valueROnRoot2Per2, 0, 360);
      fl_arc(center().x + valueROnRoot2Per2 * 1 / 6, center().y - radius() / 2, valueROnRoot2Per2, valueROnRoot2Per2, 0, 360);
      fl_arc(center().x - valueROnRoot2Per2, center().y + radius() / 2, 2 * valueROnRoot2Per2, 2 * valueROnRoot2Per2, 45, 135);
    }

  }
}