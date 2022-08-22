/*
  TextBox.cpp
  author  : Andrei-KS
*/

#include "TextBox.h"

namespace Graph_lib {

  TextBox::TextBox(Point topLeftCorner, const string& lab, int margin)
    : mBox(topLeftCorner, 2 * margin + 1, 2 * margin + 1, margin)
    , mLabel(Point{0,0}, lab)
  {
    int widthText = getTextWidth();
    int heightText = getTextHeight();
    mBox.setWidth(widthText + 2 * margin);
    mBox.setHeight(heightText + 2 * margin);
    mLabel.move(topLeftCorner.x + margin, topLeftCorner.y + heightText * 8 / 10 + margin);
    add(topLeftCorner);
  }

  
  void TextBox::draw_lines() const
  {
    mBox.draw_lines();
    mLabel.draw_lines();
  }

  
  void TextBox::move(int dx, int dy)
  {
    Shape::move(dx, dy);
    mBox.move(dx, dy);
    mLabel.move(dx, dy);
  }


  void TextBox::set_color(Color color)
  {
    mBox.set_color(color);
    mLabel.set_color(color);
  }

  void TextBox::set_fill_color(Color fill_color)
  {
    mBox.set_fill_color(fill_color);
  }
  
  
  string TextBox::label() const
  {
    return mLabel.label();
  }

  
  Font TextBox::font() const
  {
    return Font(mLabel.font());
  }

  
  int TextBox::font_size() const
  {
    return mLabel.font_size();
  }

  
  void TextBox::set_label(const string& str)
  {
    mLabel.set_label(str);
    mBox.setWidth(getTextWidth() + 2 * mBox.cornerRoundingWidth());
  }

  
  void TextBox::set_font(Font fnt)
  {
    int prevHeight = getTextHeight();
    mLabel.set_font(fnt);
    int currHeight = getTextHeight();
    mBox.setWidth(getTextWidth() + 2 * mBox.cornerRoundingWidth());
    mBox.setHeight(currHeight + 2 * mBox.cornerRoundingWidth());
    mLabel.move(0, currHeight - prevHeight);
  }

  
  void TextBox::set_font_size(int size)
  {
    int prevHeight = getTextHeight();
    mLabel.set_font_size(size);
    int currHeight = getTextHeight();
    mBox.setWidth(getTextWidth() + 2 * mBox.cornerRoundingWidth());
    mBox.setHeight(currHeight + 2 * mBox.cornerRoundingWidth());
    mLabel.move(0, currHeight - prevHeight);
  }

  
  int TextBox::getTextWidth()
  {
    int result = -1;
    int ofnt = fl_font();
    int osz = fl_size();
    fl_font(mLabel.font().as_int(), mLabel.font_size());
    result = fl_width(mLabel.label().c_str());
    fl_font(ofnt, osz);
    return result;
  }

  
  int TextBox::getTextHeight()
  {
    int result = -1;
    int ofnt = fl_font();
    int osz = fl_size();
    fl_font(mLabel.font().as_int(), mLabel.font_size());
    result = fl_height();
    fl_font(ofnt, osz);
    return result;
  }

  int TextBox::width() const
  {
    return mBox.width();
  }

  int TextBox::height() const
  {
    return mBox.height();
  }

  int TextBox::marginSize() const
  {
    return mBox.cornerRoundingHeight();
  }
}