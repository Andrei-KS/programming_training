/*
  Pseudo_window.h
  author  : Andrei-KS
*/

#ifndef __PSEUDO_WINDOW_H__
#define __PSEUDO_WINDOW_H__

#include "Graph.h"

namespace Graph_lib {
  /*
  */
  class Pseudo_window : public Shape {
  public:
    /*
    */
    Pseudo_window(Point leftTopCorner, int width, int height, const string& title);

    /*
    */
    void draw_lines() const;

    /*
    */
    int width() const;
    
    /*
    */
    void set_width(int width);

    /*
    */
    int height() const;

    /*
    */
    void set_height(int height);

    /*
    */
    Color title_color() const;

    /*
    */
    void set_title_color(Color color);

    /*
    */
    Color title_area_color() const;

    /*
    */
    void set_title_area_color(Color color);

    /*
    */
    const string& title() const;
    
    /*
    */
    void set_title(const string& title);

    /*
    */
    Font title_font() const;

    /*
    */
    void set_title_font(Font fnot);

    /*
    */
    int title_font_size() const;

    /*
    */
    void set_title_font_size(int size);

  private:
    /**/
    int mWidth;

    /**/
    int mHeight;

    /**/
    int mCornerRoundingSize;

    /**/
    Color mTitleColor;

    /**/
    Color mTitleAreaColor;

    /**/
    string mTitle;

    /**/
    Font mTitleFont;

    /**/
    int mTitleFontSize;
  };
}


#endif // !__PSEUDO_WINDOW_H__