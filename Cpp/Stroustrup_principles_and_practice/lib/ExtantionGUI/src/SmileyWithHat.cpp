/*
  SmileyWithHat.cpp
  author  : Andrei-KS
*/

#include "SmileyWithHat.h"

namespace Graph_lib {
  SmileyWithHat::SmileyWithHat(Point center, int radius, Hat* hat)
    : Smiley(center, radius)
    , mHat(nullptr)
  {
    change_hat(hat);
  }

  SmileyWithHat::~SmileyWithHat()
  {
    delete mHat;
  }

  void SmileyWithHat::set_hat_color(Color col)
  {
    if (mHat != nullptr)
    {
      mHat->set_color(col);
    }
  }
  Color SmileyWithHat::hat_color() const
  {
    if (mHat != nullptr)
    {
      return mHat->color();
    }
    return Color::invisible;
  }

  void SmileyWithHat::set_hat_fill_color(Color col)
  {
    if (mHat != nullptr)
    {
      mHat->set_fill_color(col);
    }
  }

  Color SmileyWithHat::hat_fill_color() const
  {
    if (mHat != nullptr)
    {
      return mHat->fill_color();
    }
    return Color::invisible;
  }

  void SmileyWithHat::change_hat(Hat* hat)
  {
    if (mHat != nullptr)
    {
      delete mHat;
    }

    mHat = hat;

    if (mHat == nullptr)
    {
      return;
    }

    // move hat to top smiley
    int valueROnRoot2Per2 = static_cast<int>(sqrt(2.0) * radius() / 2);
    int dx = center().x - mHat->base().x;
    int dy = center().y - valueROnRoot2Per2 - mHat->base().y;
    mHat->move(dx, dy);
  }

  void SmileyWithHat::draw_lines() const
  {
    Smiley::draw_lines();
    if (mHat != nullptr)
    {
      mHat->draw();
    }
  }
}
