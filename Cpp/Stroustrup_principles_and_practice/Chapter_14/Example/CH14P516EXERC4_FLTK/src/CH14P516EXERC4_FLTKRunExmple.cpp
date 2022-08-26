/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/26/2022 12:30:01
	author                                          : Andrei-KS
*/

#include "CH14P516EXERC4_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Immobile_Circle.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH14P516EXERC4_FLTKRunExmple();

namespace {
}

int CH14P516EXERC4_FLTKRunExmple::excute()
{
  Graph_lib::Immobile_Circle immobileCircle{ Graph_lib::Point{100,100},50 };
  // error: 'Graph_lib::Immobile_Circle::move': cannot access private member declared in class 'Graph_lib::Immobile_Circle'
  //immobileCircle.move(10, 10);

  static_cast<Graph_lib::Circle*>(&immobileCircle)->move(10, 10);

	return 0;
}