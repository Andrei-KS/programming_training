#ifndef __ROOM_H__
#define __ROOM_H__

#include <vector>
#include <array>
#include "InteractiveObject.h"

namespace GameWithGraphMap
{
  struct Room
  {
  public:
    /*
    */
    Room(int roomNumber);

    /*
    */
    ~Room();

    /*
    */
    int GetRoomNumber() const { return mRoomNumber; }

    /*
    */
    void SetAdjoindRooms(Room* room);
    
    /*
    */
    std::vector<Room*>& GetAllAdjoinedRooms() { return mAdjoinedRooms; }

    /*
    */
    const std::vector<Room*>& GetAllAdjoinedRooms() const { return mAdjoinedRooms; }

    /*
    */
    void Place(Hunter* hunter) { mInteractiveObject[0] = hunter; }
    void Place(Bat* bat) { mInteractiveObject[1] = bat; }
    void Place(Pit* pit) { mInteractiveObject[2] = pit; }
    void Place(Wumpus* Wumpus) { mInteractiveObject[3] = Wumpus; }

    /*
    */
    bool IsHunterPlaced() const { return mInteractiveObject[0] != nullptr; }
    bool IsBatPlaced() const { return mInteractiveObject[1] != nullptr; }
    bool IsPitPlaced() const { return mInteractiveObject[2] != nullptr; }
    bool IsWumpusPlaced() const { return mInteractiveObject[3] != nullptr; }

    /*
    */
    void ResetHunter() { mInteractiveObject[0] = nullptr; }
    void ResetBat() { mInteractiveObject[1] = nullptr; }
    void ResetPit() { mInteractiveObject[2] = nullptr; }
    void ResetWumpus() { mInteractiveObject[3] = nullptr; }

  private:
    /**/
    std::vector<Room*> mAdjoinedRooms;

    /**/
    int mRoomNumber;

    /* 0 - Hunter, 1 - Bat, 2 - Pit, 3 - Wumpus*/
    std::array<InteractiveObject*,4> mInteractiveObject;
  };
}



#endif //!__ROOM_H__
