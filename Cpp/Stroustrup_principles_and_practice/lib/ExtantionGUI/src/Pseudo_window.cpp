/*
  Pseudo_window.cpp
  author  : Andrei-KS
*/

#include "Pseudo_window.h"

namespace {
  constexpr int CORNER_ROUNDING_SIZE = 5;
  constexpr int SIZE_BUTTON_PSEUDO_WINDOW = 15;
  constexpr int MIN_WIDTH_PSEUDO_WINDOW = 10 + 2 * SIZE_BUTTON_PSEUDO_WINDOW + 2 * CORNER_ROUNDING_SIZE;

  struct TextInfo
  {
    int width;
    int height;
    int shiftToUp;
  };

  TextInfo get_defualt_text_info()
  {
    return { -1,-1,-1 };
  }

  const TextInfo get_text_info(const string& title, Graph_lib::Font fnt, int fnt_size)
  {
    TextInfo result = get_defualt_text_info();
    int ofnt = fl_font();
    int osz = fl_size();
    fl_font(fnt.as_int(), fnt_size);
    result.width = fl_width(title.c_str());
    result.height = fl_height();
    result.shiftToUp = result.height * 3 / 10;
    fl_font(ofnt, osz);
    return result;
  }
}

namespace Graph_lib {

  Pseudo_window::Pseudo_window(Point leftTopCorner, int width, int height, const string& title)
    : mWidth(width)
    , mHeight(height)
    , mTitle(title)
    , mCornerRoundingSize(CORNER_ROUNDING_SIZE)
    , mTitleColor(Color::black)
    , mTitleAreaColor(Color::blue)
    , mTitleFont(fl_font())
    , mTitleFontSize((14 < fl_size()) ? fl_size() : 14)
  {
    if (mWidth < MIN_WIDTH_PSEUDO_WINDOW)
    {
      error("Pseudo_window: Pseudo_window: width less than min width Pseudo_window that is equal to ", MIN_WIDTH_PSEUDO_WINDOW);
    }

    if (mHeight < 0)
    {
      error("Pseudo_window: Pseudo_window: height less zero");
    }

    add(leftTopCorner);
  }

  /*
  */
  void Pseudo_window::draw_lines() const
  {
    const TextInfo textinfo = get_text_info(mTitle, mTitleFont, mTitleFontSize);

    // Title area
    fl_color(mTitleAreaColor.as_int());
    fl_pie(point(0).x, point(0).y, 2 * mCornerRoundingSize, 2 * mCornerRoundingSize, 90, 180);
    fl_pie(point(0).x + width() - 2 * mCornerRoundingSize, point(0).y, 2 * mCornerRoundingSize, 2 * mCornerRoundingSize, 0, 90);
    fl_rectf(point(0).x, point(0).y + mCornerRoundingSize, width(), textinfo.height);
    fl_rectf(point(0).x + mCornerRoundingSize, point(0).y, width() - 2 * mCornerRoundingSize, mCornerRoundingSize);
    fl_color(color().as_int()); // reset color

    // button x
    fl_color(Color::red);
    fl_pie(point(0).x + width() - 2 * mCornerRoundingSize, point(0).y, 2 * mCornerRoundingSize, 2 * mCornerRoundingSize, 0, 90);
    fl_rectf(point(0).x + width() - SIZE_BUTTON_PSEUDO_WINDOW, point(0).y, SIZE_BUTTON_PSEUDO_WINDOW - mCornerRoundingSize, mCornerRoundingSize);
    fl_rectf(point(0).x + width() - SIZE_BUTTON_PSEUDO_WINDOW, point(0).y + mCornerRoundingSize, SIZE_BUTTON_PSEUDO_WINDOW, textinfo.height);
    fl_color(Color::black);
    fl_line_style(Line_style::solid, 1);
    fl_line(point(0).x + width() - SIZE_BUTTON_PSEUDO_WINDOW, point(0).y, point(0).x + width() - SIZE_BUTTON_PSEUDO_WINDOW, point(0).y + mCornerRoundingSize + textinfo.height);
    fl_line(point(0).x + width() - SIZE_BUTTON_PSEUDO_WINDOW, point(0).y + mCornerRoundingSize, point(0).x + width() - mCornerRoundingSize, point(0).y + textinfo.height + mCornerRoundingSize);
    fl_line(point(0).x + width() - SIZE_BUTTON_PSEUDO_WINDOW, point(0).y + textinfo.height + mCornerRoundingSize, point(0).x + width() - mCornerRoundingSize, point(0).y + mCornerRoundingSize);
    fl_line_style(style().style(), style().width());
    fl_color(color().as_int()); // reset color

    // button -
    fl_color(Color::red);
    fl_rectf(point(0).x + width() - 2 * SIZE_BUTTON_PSEUDO_WINDOW, point(0).y, SIZE_BUTTON_PSEUDO_WINDOW, mCornerRoundingSize + textinfo.height);
    fl_color(Color::black);
    fl_line_style(Line_style::solid, 1);
    fl_line(point(0).x + width() - 2 * SIZE_BUTTON_PSEUDO_WINDOW, point(0).y, point(0).x + width() - 2 * SIZE_BUTTON_PSEUDO_WINDOW, point(0).y + mCornerRoundingSize + textinfo.height);
    fl_line(point(0).x + width() - 2 * SIZE_BUTTON_PSEUDO_WINDOW, point(0).y + mCornerRoundingSize + textinfo.height / 2, point(0).x + width() - SIZE_BUTTON_PSEUDO_WINDOW, point(0).y + mCornerRoundingSize + textinfo.height / 2);
    fl_line_style(style().style(), style().width());
    fl_color(color().as_int()); // reset color
    
    // Title text
    int textFieldLength = width() - 2 * mCornerRoundingSize - MIN_WIDTH_PSEUDO_WINDOW / 2;
    fl_color(mTitleColor.as_int());
    int ofnt = fl_font();
    int osz = fl_size();
    fl_font(mTitleFont.as_int(), mTitleFontSize);
    if (textFieldLength >= textinfo.width)
    {
      fl_draw(mTitle.c_str(), point(0).x + mCornerRoundingSize, point(0).y + mCornerRoundingSize + textinfo.height - textinfo.shiftToUp);
    }
    else
    {
      fl_draw("...", point(0).x + mCornerRoundingSize, point(0).y + mCornerRoundingSize + textinfo.height - textinfo.shiftToUp);
    }
    fl_font(ofnt, osz);
    fl_color(color().as_int()); // reset color


    // Body area
    if (fill_color().visibility()) {	// fill
      // Body area
      fl_color(fill_color().as_int());
      fl_pie(point(0).x, point(0).y + textinfo.height + height(), 2 * mCornerRoundingSize, 2 * mCornerRoundingSize, 180, 270);
      fl_pie(point(0).x + width() - 2 * mCornerRoundingSize, point(0).y + textinfo.height + height(), 2 * mCornerRoundingSize, 2 * mCornerRoundingSize, 270, 360);
      fl_rectf(point(0).x, point(0).y + mCornerRoundingSize + textinfo.height, width(), height());
      fl_rectf(point(0).x + mCornerRoundingSize, point(0).y + mCornerRoundingSize + textinfo.height + height(), width() - 2 * mCornerRoundingSize, mCornerRoundingSize);
      fl_color(color().as_int());	// reset color
    }

    if (color().visibility()) {	// edge on top of fill
      fl_color(color().as_int());
      fl_line(point(0).x + mCornerRoundingSize, point(0).y, point(0).x + width() - mCornerRoundingSize, point(0).y);
      fl_line(point(0).x + width(), point(0).y + mCornerRoundingSize, point(0).x + width(), point(0).y + mCornerRoundingSize + textinfo.height + height());
      fl_line(point(0).x + mCornerRoundingSize, point(0).y + 2 * mCornerRoundingSize + textinfo.height + height(), point(0).x + width() - mCornerRoundingSize, point(0).y + 2 * mCornerRoundingSize + textinfo.height + height());
      fl_line(point(0).x, point(0).y + mCornerRoundingSize, point(0).x, point(0).y + mCornerRoundingSize + textinfo.height + height());

      fl_arc(point(0).x, point(0).y, 2 * mCornerRoundingSize, 2 * mCornerRoundingSize, 90, 180);
      fl_arc(point(0).x + width() - 2 * mCornerRoundingSize, point(0).y, 2 * mCornerRoundingSize, 2 * mCornerRoundingSize, 0, 90);
      fl_arc(point(0).x, point(0).y + textinfo.height + height(), 2 * mCornerRoundingSize, 2 * mCornerRoundingSize, 180, 270);
      fl_arc(point(0).x + width() - 2 * mCornerRoundingSize, point(0).y + textinfo.height + height(), 2 * mCornerRoundingSize, 2 * mCornerRoundingSize, 270, 360);
    }


  }

  int Pseudo_window::width() const
  {
    return mWidth;
  }

  void Pseudo_window::set_width(int width)
  {
    mWidth = width;
  }

  int Pseudo_window::height() const
  {
    return mHeight;
  }

  void Pseudo_window::set_height(int height)
  {
    mHeight = height;
  }

  Color Pseudo_window::title_color() const
  {
    return mTitleColor;
  }

  void Pseudo_window::set_title_color(Color color)
  {
    mTitleColor = color;
  }

  Color Pseudo_window::title_area_color() const
  {
    return mTitleAreaColor;
  }

  void Pseudo_window::set_title_area_color(Color color)
  {
    mTitleAreaColor = color;
  }

  const string& Pseudo_window::title() const
  {
    return mTitle;
  }

  void Pseudo_window::set_title(const string& title)
  {
    mTitle = title;
  }

  Font Pseudo_window::title_font() const
  {
    return mTitleFont;
  }

  void Pseudo_window::set_title_font(Font font)
  {
    mTitleFont = font;
  }

  int Pseudo_window::title_font_size() const
  {
    return mTitleFontSize;
  }

  void Pseudo_window::set_title_font_size(int size)
  {
    mTitleFontSize = size;
  }
}