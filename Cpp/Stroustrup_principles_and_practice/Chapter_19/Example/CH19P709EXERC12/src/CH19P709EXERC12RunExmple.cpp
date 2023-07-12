/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 07/11/2023 16:11:03
	author                                          : Andrei-KS
*/

#include "CH19P709EXERC12RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH19P709EXERC12RunExmple();

namespace {
  class File_handle
  {
  public:
    /*
    */
    File_handle(string fileName)
      : fs{ fstream() }
    {
      fs.open(fileName);
      if (fs.is_open())
      {
        cout << fileName << " is opened\n";
      }
      else
      {
        cout << fileName << " isn't opened\n";
      }
    }

    /*
    */
    ~File_handle()
    {
      if (fs.is_open())
      {
        fs.close();
      }
    }
  private:
    fstream fs;
  };
}

int CH19P709EXERC12RunExmple::excute()
{
  File_handle fh("1.txt");
	return 0;
}