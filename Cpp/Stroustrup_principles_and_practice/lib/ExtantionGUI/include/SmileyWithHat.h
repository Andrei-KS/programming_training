/*
  SmileyWithHat.h
  author  : Andrei-KS
*/

#ifndef __SMILEYWITHHAT_H__
#define __SMILEYWITHHAT_H__

#include "Smiley.h"
#include "Hat.h"

namespace Graph_lib {

  /*
  */
  class SmileyWithHat : public Smiley {
  public:
    /*
    */
    SmileyWithHat(Point center, int radius, Hat* hat = nullptr);
    
    /*
    */
    ~SmileyWithHat();

    /*
    */
    void set_hat_color(Color col);
    
    /*
    */
    Color hat_color() const;

    /*
    */
    void set_hat_fill_color(Color col);
    
    /*
    */
    Color hat_fill_color() const;

    /*
    */
    void change_hat(Hat*);

  protected:
    /*
    */
    void draw_lines() const override;

  private:
    /**/
    Hat* mHat;
  };
}


#endif // !__SMILEYWITHHAT_H__