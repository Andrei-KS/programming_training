/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 07/25/2023 08:56:14
	author                                          : Andrei-KS
*/

#include "Game.h"
#include "CH18P665EXERC12RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH18P665EXERC12RunExmple();

namespace {
}

int CH18P665EXERC12RunExmple::excute()
{
  GameWithGraphMap::Game g;
  g.run();

	return 0;
}