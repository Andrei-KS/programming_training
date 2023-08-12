#ifndef __GAME_H__
#define __GAME_H__

#include "Room.h"
#include "InteractiveObject.h"
#include "TokenStream.h"
#include <random>

namespace GameWithGraphMap
{
  /*
  */
  class Game
  {
  public:
    /*
    */
    Game();
    
    /*
    */
    ~Game();

    /*
    */
    void run();

  protected:
    /*
    */
    void PromoAtStartGame() const;
    
    /*
    */
    void GenerateNewCave();
    
    /*
    */
    void HelpInfo() const;
#ifdef DEBUG_BUILD
    /*
    */
    void DebugInfo() const;
#endif //!DEBUG_BUILD

  private:
    /**/
    bool mIsNewGameInitialized;

    /**/
    bool mIsQuit;

    /**/
    bool mNeedHelp;

    /**/
    std::vector<Room> mRooms;

    /**/
    std::vector<Hunter> mHunters;
    std::vector<Room*> mHunterRooms;
    std::vector<int> mArrowsAmounts;

    /**/
    std::vector<Bat> mBats;
    
    /**/
    std::vector<Pit> mPits;

    /**/
    Wumpus mWumpus;
    bool mIsWumpusShooted;

    /**/
    std::random_device mRandomDevice;

    /**/
    TokenStream mTokenStream;
  };
}



#endif //!__TAIL_H__