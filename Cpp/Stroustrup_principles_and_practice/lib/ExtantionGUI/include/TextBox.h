/*
  TextBox.h
  author  : Andrei-KS
*/

#ifndef __TEXTBOX_H__
#define __TEXTBOX_H__

#include "Box.h"

namespace Graph_lib {
  /*
  */
  struct TextBox : Shape{
    /*
    */
    TextBox(Point topLeftCorner, const string& lab, int margin = 1);

    /*
    */
    void draw_lines() const;
    
    /*
    */
    void move(int dx, int dy);

    /*
    */
    void set_color(Color color);

    /*
    */
    void set_fill_color(Color fill_color);

    /*
    */
    string label() const;
    
    /*
    */
    Font font() const;
    
    /*
    */
    int font_size() const;
    
    /*
    */
    void set_label(const string& str);

    /*
    */
    void set_font(Font fnt);

    /*
    */
    void set_font_size(int size);

    /*
    */
    int width() const;

    /*
    */
    int height() const;

    /*
    */
    int marginSize() const;

  protected:
    /*
    */
    int getTextWidth();

    /*
    */
    int getTextHeight();

  private:
    Box mBox;
    Text mLabel;
  };
}

#endif // !__TEXTBOX_H__