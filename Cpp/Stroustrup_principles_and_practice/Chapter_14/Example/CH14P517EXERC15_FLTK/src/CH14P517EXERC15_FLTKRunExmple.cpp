/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/16/2022 15:39:03
	author                                          : Andrei-KS
*/

#include "CH14P517EXERC15_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH14P517EXERC15_FLTKRunExmple();

namespace {
  class myIterator {
  public:
    /*
    */
    myIterator() {}

    /*
    */
    virtual double* next() = 0;
  };

  class Vector_iterator : public myIterator {
  public:
    /*
    */
    Vector_iterator(vector<double>& vectorD)
      : mVector(&vectorD)
      , mCurrentIndex(0)
    {
    }

    /*
    */
    double* next() override
    {
      if (mCurrentIndex < mVector->size())
      {
        double* result = &(*mVector)[mCurrentIndex];
        mCurrentIndex++;
        return result;
      }
      else
      {
        return nullptr;
      }
    }

  private:
    /**/
    vector<double>* mVector;

    /**/
    int mCurrentIndex;
  };

  class List_iterator : public myIterator {
  public:
    /*
    */
    List_iterator(list<double>& listD)
      : mList(&listD)
      , mCurrentIterator(listD.begin())
    {
    }

    /*
    */
    double* next() override
    {
      if (mCurrentIterator != mList->end())
      {
        double* result = &(*mCurrentIterator);
        mCurrentIterator++;
        return result;
      }
      else
      {
        return nullptr;
      }
    }

  private:
    /**/
    list<double>* mList;

    /**/
    list<double>::iterator mCurrentIterator;
  };

  void printVIT(myIterator& it)
  {
    double* pValue = it.next();
    if (pValue == nullptr)
    {
      cout << "Iterator get to the end" << "\n";
      return;
    }
    cout << *pValue << "\n";
  }
}

int CH14P517EXERC15_FLTKRunExmple::excute()
{
  vector<double> vectorDouble1 = { 1.0, 2.0, 3.0 };
  vector<double> vectorDouble2 = { 4.0, 5.0 };

  Vector_iterator vit1(vectorDouble1);
  Vector_iterator vit2(vectorDouble2);

  printVIT(vit1);
  printVIT(vit2);
  printVIT(vit1);
  printVIT(vit2);
  printVIT(vit1);
  printVIT(vit2);
  printVIT(vit1);

  list<double> lDouble1 = { 1.0, 2.0, 3.0 };
  list<double> lDouble2 = { 4.0 };

  List_iterator lit1(lDouble1);
  List_iterator lit2(lDouble2);

  printVIT(lit1);
  printVIT(lit2);
  printVIT(lit1);
  printVIT(lit2);
  printVIT(lit1);
  printVIT(lit2);
  printVIT(lit1);

	return 0;
}