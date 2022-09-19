/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/19/2022 12:27:45
	author                                          : Andrei-KS
*/

#include "CH14P518EXERC17_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "TextBox.h"
#include "Group.h"
#include "GUI_Utility_function.h"
#include "Arrow.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH14P518EXERC17_FLTKRunExmple();

namespace {
  // The window setting
  constexpr int xWindowLeftTopCorner = 100;
  constexpr int yWindowLeftTopCorner = 100;
  constexpr int windowWidth = 600;
  constexpr int windowHeight = 600;

  struct Hierarchy_node {
    vector<int> derivedNodes;
    string label;
  };

  unordered_map<string, string> exceptionClassMap = {
    {"exception",""},

    {"bad_alloc","exception"},
    {"bad_cast","exception"},
    {"bad_exception","exception"},
    {"bad_function_call","exception"},
    {"bad_typeid","exception"},
    {"bad_weak_ptr","exception"},
    {"ios_base::failure","exception"},
    {"logic_error","exception"},
    {"runtime_error","exception"},

    {"bad_array_new_length","bad_alloc"},

    {"domain_error","logic_error"},
    {"future_error","logic_error"},
    {"invalid_argument","logic_error"},
    {"length_error","logic_error"},
    {"out_of_range","logic_error"},

    {"overflow_error","runtime_error"},
    {"range_error","runtime_error"},
    {"system_error","runtime_error"},
    {"underflow_error","runtime_error"},

    {"ios_base::failure","system_error"},
  };

  void assemble_hierarchy(Graph_lib::Group& hierarchy, const vector<Hierarchy_node>& hierarchyNodes, Graph_lib::Point& currentPosition, const int currentIndex)
  {
    hierarchy.attach(new Graph_lib::TextBox( currentPosition, hierarchyNodes[currentIndex].label, 5 ));
    int indexCurrentTextBox = hierarchy.size() - 1;
    Graph_lib::TextBox* ptrTextBox = dynamic_cast<Graph_lib::TextBox*>(&hierarchy[indexCurrentTextBox]);
    ptrTextBox->set_fill_color(Graph_lib::Color::yellow);
    ptrTextBox->set_color(Graph_lib::Color::black);
    int textBoxWidth = Graph_lib::ne(*ptrTextBox).x - Graph_lib::nw(*ptrTextBox).x;
    int textBoxHeight = Graph_lib::sw(*ptrTextBox).y - Graph_lib::nw(*ptrTextBox).y;
    Graph_lib::Point CenterLeftSide = Graph_lib::w(*ptrTextBox);

    currentPosition.x += (textBoxWidth + 50);
    if (hierarchyNodes[currentIndex].derivedNodes.size() != 0)
    {
      for (const int derivedNode : hierarchyNodes[currentIndex].derivedNodes)
      {
        hierarchy.attach(new Graph_lib::Arrow({ currentPosition.x, currentPosition.y + (textBoxHeight + 5)/2}, CenterLeftSide ));
        hierarchy[hierarchy.size() - 1].set_color(Graph_lib::Color::black);
        hierarchy[hierarchy.size() - 1].set_fill_color(Graph_lib::Color::black);
        assemble_hierarchy(hierarchy, hierarchyNodes, currentPosition, derivedNode);
      
      }
    }
    else
    {
      currentPosition.y += textBoxHeight + 5;
    }

    currentPosition.x -= (textBoxWidth + 50);

    cout << currentPosition.x << " " << currentPosition.y << "\n";
  }
}

int CH14P518EXERC17_FLTKRunExmple::excute()
{
  unordered_map<string, int> hierarchyNodesMap;
  vector<Hierarchy_node> hierarchyNodes;
  unordered_map<string, string>::iterator exceptionClassMap_it = exceptionClassMap.begin();
  while (exceptionClassMap_it != exceptionClassMap.end())
  {
    unordered_map<string, int>::iterator hierarchyNodesMap_it = hierarchyNodesMap.find(exceptionClassMap_it->first.c_str());
    if (hierarchyNodesMap_it == hierarchyNodesMap.end())
    {
      hierarchyNodes.push_back(Hierarchy_node());
      hierarchyNodes[hierarchyNodes.size() - 1].label = exceptionClassMap_it->first.c_str();
      hierarchyNodesMap[exceptionClassMap_it->first.c_str()] = hierarchyNodes.size() - 1;
    }

    hierarchyNodesMap_it = hierarchyNodesMap.find(exceptionClassMap_it->second.c_str());
    if (hierarchyNodesMap_it == hierarchyNodesMap.end())
    {
      hierarchyNodes.push_back(Hierarchy_node());
      hierarchyNodes[hierarchyNodes.size() - 1].label = exceptionClassMap_it->second.c_str();
      hierarchyNodesMap[exceptionClassMap_it->second.c_str()] = hierarchyNodes.size() - 1;
    }

    hierarchyNodes[hierarchyNodesMap[exceptionClassMap_it->second.c_str()]].derivedNodes.push_back(hierarchyNodesMap[exceptionClassMap_it->first.c_str()]);
    exceptionClassMap_it++;
  }


  for (const Hierarchy_node& node : hierarchyNodes)
  {
    cout << "Node : " << node.label << "\n";
    for (const int derivedNode : node.derivedNodes)
    {
      cout << " <- " << hierarchyNodes[derivedNode].label << "\n";
    }
  }

  Graph_lib::Point windowLeftTopCorner{ xWindowLeftTopCorner, yWindowLeftTopCorner };
  Graph_lib::Simple_window sWindow(windowLeftTopCorner, windowWidth, windowHeight, "CH14P518EXERC17_FLTKRunExmple");
  Graph_lib::Group hierarchy;

  assemble_hierarchy(hierarchy, hierarchyNodes, Graph_lib::Point{ 50,50 }, hierarchyNodesMap["exception"]);

  sWindow.attach(hierarchy);
  sWindow.wait_for_button();
	return 0;
}