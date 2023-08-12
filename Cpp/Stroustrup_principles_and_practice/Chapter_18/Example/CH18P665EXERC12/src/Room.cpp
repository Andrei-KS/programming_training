#include "Room.h"

namespace GameWithGraphMap
{
  Room::Room(int roomNumber)
    : mRoomNumber{ roomNumber }
  {
    mInteractiveObject.fill(nullptr);
  }

  Room::~Room()
  {
  }

  void Room::SetAdjoindRooms(Room* room)
  {
    std::vector<Room*>::iterator it = std::find(mAdjoinedRooms.begin(), mAdjoinedRooms.end(), room);
    if (it == mAdjoinedRooms.end())
    {
      mAdjoinedRooms.push_back(room);
    }
  }


}