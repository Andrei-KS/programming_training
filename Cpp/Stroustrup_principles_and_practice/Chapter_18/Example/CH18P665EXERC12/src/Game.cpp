#include "Game.h"
#include <iostream>
#include <iomanip> // std::setw

namespace GameWithGraphMap
{
  Game::Game()
    : mIsNewGameInitialized{ true }
    , mIsQuit{ false }
    , mIsWumpusShooted{ false }
    , mNeedHelp{ true }
  {
  }

  Game::~Game()
  {
  }

  void Game::PromoAtStartGame() const
  {
    std::cout << "Hello, you run the \"Hunt the Wumpus\" game.\n"
      << "This is a simple (non-graphical) computer game\n"
      << "originally invented by Gregory Yob. But current\n"
      << "implementation was made by Andrei Ksenz using book\n"
      << "of \"Programming Principlesand Practice Using C++\"\n"
      << "/Second Edition/Bjarne Stroustrup/2014/ISBN-13: 978-0-321-99278-9\n\n";
  }

  void Game::HelpInfo() const
  {
    std::cout << "---- Help info: --\n"
      << "| Help: help\n"
      << "| Move: m(target)\n"
      << "| Shoot: s(target), s(target)-(target), s(target)-(target)-(target)\n"
      << "| New Game: new\n"
      << "| Quit: quit\n"
      << "------------------\n";
  }

  void Game::run()
  {
    PromoAtStartGame();
    while (true)
    {
      if (mIsNewGameInitialized)
      {
        GenerateNewCave();
        mIsNewGameInitialized = false;
        mIsWumpusShooted = false;
        std::cout << "New map has been generated\n";
      }

      for (int hunterIndex = 0; hunterIndex < mHunters.size() && !mIsQuit && !mIsNewGameInitialized; ++hunterIndex)
      {
        std::cout << "\n";
        bool bIsWarrningBat = false;
        bool bIsWarrningPit = false;
        bool bIsWarrningWumpus = false;
        std::cout << "You is in [" << mHunterRooms[hunterIndex]->GetRoomNumber() << "] and can go to : ";
        for (Room* adjoinedRoom : mHunterRooms[hunterIndex]->GetAllAdjoinedRooms())
        {
          std::cout << " " << adjoinedRoom->GetRoomNumber() << ",";
          if (adjoinedRoom->IsBatPlaced())
          {
            bIsWarrningBat = true;
          }
          if (adjoinedRoom->IsPitPlaced())
          {
            bIsWarrningPit = true;
          }
          if (adjoinedRoom->IsWumpusPlaced())
          {
            bIsWarrningWumpus = true;
          }
        }
        std::cout << "\b \n";
        if (bIsWarrningBat)
        {
          std::cout << "I hear a bat.\n";
        }
        if (bIsWarrningPit)
        {
          std::cout << "I feel a breeze.\n";
        }
        if (bIsWarrningWumpus)
        {
          std::cout << "I smell the wumpus.\n";
        }

        bool IsEndTurn = false;
        while (!IsEndTurn)
        {
          if (mNeedHelp)
          {
            HelpInfo();
            mNeedHelp = false;
          }

          IsEndTurn = true;
          std::cout << "Hunter[" << hunterIndex << "]{" << mArrowsAmounts[hunterIndex] << "} ?>";
          Token token = mTokenStream.Get();
          if (token.GetType() == TokenType::MOVE)
          {
            token = mTokenStream.Get();
            if (token.GetType() == TokenType::INT_VALUE)
            {
              bool bIsMovementCorrect = false;
              int target = token.GetValue();
              if (target > -1 && target < mRooms.size())
              {
                for (Room* adjoinedRoom : mHunterRooms[hunterIndex]->GetAllAdjoinedRooms())
                {
                  if (adjoinedRoom->GetRoomNumber() == target)
                  {
                    mHunterRooms[hunterIndex]->ResetHunter();
                    mHunterRooms[hunterIndex] = adjoinedRoom;
                    mHunterRooms[hunterIndex]->Place(&mHunters[hunterIndex]);
                    bIsMovementCorrect = true;
                    break;
                  }
                }
              }
              if (!bIsMovementCorrect)
              {
                std::cout << "Enter incorrect movement command!\n";
              }
            }
          }
          else if (token.GetType() == TokenType::SHOOT)
          {
            bool bIsShootingCorrect = false;
            const int MaxTargets = 3;
            Room* curentRoom = mHunterRooms[hunterIndex];
            bool bNeedNext = true;
            for (int index = 0; index < MaxTargets && bNeedNext; ++index)
            {
              bNeedNext = false;
              token = mTokenStream.Get();
              if (token.GetType() == TokenType::INT_VALUE)
              {
                int value = token.GetValue();
                bIsShootingCorrect = true;
                token = mTokenStream.Get();

                if(token.GetType() != TokenType::LINE_END && token.GetType() != TokenType::CONNECTOR)
                {
                  bIsShootingCorrect = false;
                  break;
                }

                bIsShootingCorrect = false;
                for (std::vector<Room*>::iterator it = curentRoom->GetAllAdjoinedRooms().begin(); it != curentRoom->GetAllAdjoinedRooms().end(); ++it)
                {
                  Room* nextRoom = (*it);
                  if (nextRoom->GetRoomNumber() == value)
                  {
                    bIsShootingCorrect = true;
                    mIsWumpusShooted |= nextRoom->IsWumpusPlaced();
                    bNeedNext |= token.GetType() == TokenType::CONNECTOR;
                    curentRoom = nextRoom;
                    break;
                  }
                }

              }
              else
              {
                bIsShootingCorrect = false;
                break;
              }
            }

            if (bIsShootingCorrect)
            {
              --mArrowsAmounts[hunterIndex];
            }
            else
            {
              std::cout << "Enter incorrect shooting command!\n";
              mIsWumpusShooted = false;
              IsEndTurn = false;
            }

          }
          else if (token.GetType() == TokenType::QUIT)
          {
            mIsQuit = true;
          }
          else if (token.GetType() == TokenType::NEW)
          {
            mIsNewGameInitialized = true;
          }
          else if (token.GetType() == TokenType::HELP)
          {
            mNeedHelp = true;
            IsEndTurn = false;
          }
          else
          {
            std::cout << "Enter incorrect command!\n";
            IsEndTurn = false;
          }

          if (token.GetType() != TokenType::LINE_END)
          {
            mTokenStream.Ignore();
          }
        }

        if (mHunterRooms[hunterIndex]->IsBatPlaced())
        {
          std::cout << "Bat move you from [" << mHunterRooms[hunterIndex]->GetRoomNumber() << "] to [";
          mHunterRooms[hunterIndex]->ResetHunter();
          mHunterRooms[hunterIndex] = &mRooms[mRandomDevice()%mRooms.size()];
          mHunterRooms[hunterIndex]->Place(&mHunters[hunterIndex]);
          std::cout << mHunterRooms[hunterIndex]->GetRoomNumber() << "]\n";
        }

        if (mHunterRooms[hunterIndex]->IsWumpusPlaced())
        {
          std::cout << "!!!Wumpus eat you!!!\n";
          mIsNewGameInitialized = true;
        }

        if (mHunterRooms[hunterIndex]->IsPitPlaced())
        {
          std::cout << "!!!You died in the bottomless pit!!!\n";
          mIsNewGameInitialized = true;
        }

        if (mIsWumpusShooted)
        {
          std::cout << "!!!Wumpus is shooted!!!\n";
          mIsNewGameInitialized = true;
        }

        if (mArrowsAmounts[hunterIndex] == 0 && !mIsWumpusShooted)
        {
          std::cout << "!!!You have zero of arrows and can't kill a wumpus, you lose!!!\n";
          mIsNewGameInitialized = true;
        }
      }

      if (mIsQuit)
      {
        break;
      }
    }
  }

  /*
  */
  void CreatBlocksMap(std::vector<int>& blocksMap, std::vector<std::vector<int>>& roomsInBlock, const Room* room, int currentBlockNumber)
  {
    if (blocksMap[room->GetRoomNumber()] != -1)
    {
      return;
    }

    blocksMap[room->GetRoomNumber()] = currentBlockNumber;
    roomsInBlock[currentBlockNumber].push_back(room->GetRoomNumber());
    for (const Room* adjionedRoom : room->GetAllAdjoinedRooms())
    {
      CreatBlocksMap(blocksMap, roomsInBlock, adjionedRoom, currentBlockNumber);
    }
  }

  void Game::GenerateNewCave()
  {
    mRooms.clear();
    mHunters.clear();
    mHunterRooms.clear();
    mArrowsAmounts.clear();
    mBats.clear();
    mPits.clear();

    // make interactive object
    int hunterAmount = 1;
    for (size_t index = 0; index < hunterAmount; ++index)
    {
      mHunters.push_back(Hunter());
      mHunterRooms.push_back(nullptr);
      mArrowsAmounts.push_back(3);
    }

    int pitAmount = 2;
    for (size_t index = 0; index < pitAmount; ++index)
    {
      mPits.push_back(Pit());
    }

    int batAmount = 2;
    for (size_t index = 0; index < batAmount; ++index)
    {
      mBats.push_back(Bat());
    }

    // first stage of cave generation 
    const int maxCaveRoomAmount = 20;
    const int minCaveRoomAmount = 5;
    int newCaveRoomAmount = mRandomDevice() % (maxCaveRoomAmount - minCaveRoomAmount) + minCaveRoomAmount + mHunters.size() + mPits.size() + mBats.size();
    mRooms.reserve(newCaveRoomAmount);
    for (int roomIndex = 0; roomIndex < newCaveRoomAmount; ++roomIndex)
    {
      mRooms.push_back(Room(roomIndex));
    }

    // control a generation of primary adjoined rooms of a block
    const int allCases = 100;
    const int goodCases = 20;
    // generate of primary adjoined rooms of a block
    for (int roomIndex = 0; roomIndex < newCaveRoomAmount; ++roomIndex)
    {
      for (int adjoinedRoomIndex = roomIndex + 1; adjoinedRoomIndex < newCaveRoomAmount; ++adjoinedRoomIndex)
      {
        int caseValue = mRandomDevice() % allCases;
        if (caseValue < goodCases)
        {
          mRooms[roomIndex].SetAdjoindRooms(&mRooms[adjoinedRoomIndex]);
          mRooms[adjoinedRoomIndex].SetAdjoindRooms(&mRooms[roomIndex]);
        }
      }
    }

    {
      // Connect individual blocks
      std::vector<int> blocksMap(newCaveRoomAmount, -1);
      std::vector<std::vector<int>> roomsInBlock;

      // Place pits in cave
      for (int index = 0; index < mPits.size(); ++index)
      {
        int roomIndex = mRandomDevice() % newCaveRoomAmount;
        while (mRooms[roomIndex].IsPitPlaced())
        {
          roomIndex = mRandomDevice() % newCaveRoomAmount;
        }
        mRooms[roomIndex].Place(&mPits[index]);
        blocksMap[roomIndex] = -2;
      }

      // Find Block
      int currentBlockNumber = 0;
      for (int roomIndex = 0; roomIndex < newCaveRoomAmount; ++roomIndex)
      {
        if (blocksMap[roomIndex] == -1)
        {
          roomsInBlock.push_back(std::vector<int>());
          CreatBlocksMap(blocksMap, roomsInBlock, &mRooms[roomIndex], currentBlockNumber);
          ++currentBlockNumber;
        }
      }

      // Process of connecting individual blocks
      for (int firstBlockIndex = 0; firstBlockIndex < roomsInBlock.size(); ++firstBlockIndex)
      {
        for (int secondBlockIndex = firstBlockIndex + 1; secondBlockIndex < roomsInBlock.size(); ++secondBlockIndex)
        {
          int connectionAmount = mRandomDevice() % std::max(roomsInBlock[firstBlockIndex].size(), roomsInBlock[secondBlockIndex].size());
          if (!connectionAmount)
          {
            connectionAmount = 1;
          }

          while (connectionAmount)
          {
            for (int firstBlockRoomIndex = 0; firstBlockRoomIndex < roomsInBlock[firstBlockIndex].size() && connectionAmount; ++firstBlockRoomIndex)
            {
              for (int secondBlockRoomIndex = 0; secondBlockRoomIndex < roomsInBlock[secondBlockIndex].size() && connectionAmount; ++secondBlockRoomIndex)
              {
                int caseValue = mRandomDevice() % allCases;
                if (caseValue < goodCases)
                {
                  mRooms[roomsInBlock[firstBlockIndex][firstBlockRoomIndex]].SetAdjoindRooms(&mRooms[roomsInBlock[secondBlockIndex][secondBlockRoomIndex]]);
                  mRooms[roomsInBlock[secondBlockIndex][secondBlockRoomIndex]].SetAdjoindRooms(&mRooms[roomsInBlock[firstBlockIndex][firstBlockRoomIndex]]);
                  --connectionAmount;
                }
              }
            }
          }
        }
      }
    }


    std::vector<int> availablePlace;
    for (int roomIndex = 0; roomIndex < newCaveRoomAmount; ++roomIndex)
    {
      if (!mRooms[roomIndex].IsPitPlaced())
      {
        availablePlace.push_back(mRooms[roomIndex].GetRoomNumber());
      }
    }

    for (int index = 0; index < mBats.size(); ++index)
    {
      int availablePlaceIndex = mRandomDevice() % availablePlace.size();
      mRooms[availablePlace[availablePlaceIndex]].Place(&mBats[index]);
      availablePlace.erase(availablePlace.begin() + availablePlaceIndex);
    }

    for (int index = 0; index < mHunters.size(); ++index)
    {
      int availablePlaceIndex = mRandomDevice() % availablePlace.size();
      mHunterRooms[index] = &mRooms[availablePlace[availablePlaceIndex]];
      mHunterRooms[index]->Place(&mHunters[index]);
      availablePlace.erase(availablePlace.begin() + availablePlaceIndex);
    }

    for (int availablePlaceIndex = 0; availablePlaceIndex < availablePlace.size(); )
    {
      Room* pRoom = &mRooms[availablePlace[availablePlaceIndex]];
      bool bNeedRemove = false;
      for (std::vector<Room*>::const_iterator ajonedRoomIt =  pRoom->GetAllAdjoinedRooms().begin(); ajonedRoomIt != pRoom->GetAllAdjoinedRooms().end() && !bNeedRemove; ++ajonedRoomIt)
      {
        for (int index = 0; index < mHunters.size() && !bNeedRemove; ++index)
        {
          if (*ajonedRoomIt == mHunterRooms[index])
          {
            bNeedRemove = true;
            break;
          }
        }
      }
      if (bNeedRemove)
      {
        availablePlace.erase(availablePlace.begin() + availablePlaceIndex);
      }
      else
      {
        ++availablePlaceIndex;
      }
    }

    int availableWumpusPlaceIndex = mRandomDevice() % availablePlace.size();
    mRooms[availablePlace[availableWumpusPlaceIndex]].Place(&mWumpus);

#ifdef DEBUG_BUILD
    DebugInfo();
#endif //!DEBUG_BUILD

  }

#ifdef DEBUG_BUILD
  /*
  */
  void Game::DebugInfo() const
  {
    std::cout << "/------ DEBUG INFO: -------\\\n";
    std::cout << "Room amount : " << mRooms.size() << "\n";
    std::cout << "Info about rooms :\n";
    for (int index = 0; index < mRooms.size(); ++index)
    {
      std::cout << "Room[" << mRooms[index].GetRoomNumber() << "] :: \n"
        << "\t" << std::setw(7) << std::left << "Wumpus" << " : " << std::boolalpha << mRooms[index].IsWumpusPlaced() << "\n"
        << "\t" << std::setw(7) << std::left << "Bat" << " : " << std::boolalpha << mRooms[index].IsBatPlaced() << "\n"
        << "\t" << std::setw(7) << std::left << "Pit" << " : " << std::boolalpha << mRooms[index].IsPitPlaced() << "\n"
        << "\t" << std::setw(7) << std::left << "Hunter" << " : " << std::boolalpha << mRooms[index].IsHunterPlaced() << "\n";
      for (std::vector<Room*>::const_iterator adjoinedRoomIterator = mRooms[index].GetAllAdjoinedRooms().begin(); adjoinedRoomIterator != mRooms[index].GetAllAdjoinedRooms().end(); ++adjoinedRoomIterator)
      {
        std::cout << "\t" << "AdjoinedRoom[" << (*adjoinedRoomIterator)->GetRoomNumber() << "]\n";
      }
    }
    std::cout << "\\------ DEBUG INFO  -------/\n";
  }
#endif //!DEBUG_BUILD
}