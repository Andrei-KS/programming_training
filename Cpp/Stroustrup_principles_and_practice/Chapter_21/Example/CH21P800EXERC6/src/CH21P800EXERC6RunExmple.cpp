/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 12/06/2023 06:37:14
	author                                          : Andrei-KS
*/
#include "Chrono.h"
#include <set>
#include "CH21P800EXERC6RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P800EXERC6RunExmple();

namespace
{
  struct Fruit
  {
    string name;
    int count;
    double unit_price;
    Chrono::Date last_sale_date;
  };

  struct Fruit_order
  {
    bool operator()(const Fruit* a, const Fruit* b) const
    {
      return a->name < b->name;
    }
  };

  set<Fruit*, Fruit_order> inventory; //use Fruit_order(x, y) to compare Fruits
  vector<Fruit> fruitInstances;

  void printSet(set<Fruit*, Fruit_order> fruitSet)
  {
    cout << "fruit set info:\n";
    for (const auto& x : inventory)
    {
      cout << setw(10) << "name" << " : " << x->name << "\n"
        << setw(10) << "count" << " : " << x->count << "\n"
        << setw(10) << "unit price" << " : " << x->unit_price << "\n"
        << setw(10) << "last sale data" << " : " << x->last_sale_date << "\n"
        << "--\n";
    }
  }
}

int CH21P800EXERC6RunExmple::excute()
{
  fruitInstances.push_back(Fruit{ "Quince",5 });
  fruitInstances.push_back(Fruit{ "Apple",200,0.37 });
  fruitInstances.push_back(Fruit{ "Orange",20,1.03,Chrono::Date{2021,Chrono::Month::feb,4 }});
  inventory.insert(&fruitInstances[0]);
  inventory.insert(&fruitInstances[1]);
  inventory.insert(&fruitInstances[2]);
  printSet(inventory);
	return 0;
}