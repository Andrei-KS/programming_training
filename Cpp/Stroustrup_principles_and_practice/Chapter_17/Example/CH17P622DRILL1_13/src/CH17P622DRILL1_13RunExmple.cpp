/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/03/2023 08:19:17
	author                                          : Andrei-KS
*/

#include "CH17P622DRILL1_13RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH17P622DRILL1_13RunExmple();

namespace {
  void print_array(ostream& os, int* array, int n)
  {
    for (int index = 0; index < n; ++index)
    {
      cout << array[index] << '\n';
    }
  }
}

int CH17P622DRILL1_13RunExmple::excute()
{
  int* p1 = new int(7);
  cout << p1 << " <- " << *p1 << '\n';

  const int SECOND_ARRAY_SIZE = 7;
  int* p2 = new int[SECOND_ARRAY_SIZE];
  for (int index = 0; index < SECOND_ARRAY_SIZE; ++index)
  {
    *(p2 + index) = pow(2, index);
  }
  print_array(cout, p2, SECOND_ARRAY_SIZE);
  cout << p2 << '\n';
  
  int* p3 = p2;
  int* temp = p2;

  p2 = p1;
  p2 = p3;

  cout << "p1 :=" << p1 << " <- " << *p1 << '\n';
  cout << "p2 :=" << p2 << " <- " << *p2 << '\n';

  delete[] temp;
  delete p1;

  const int THIRD_ARRAY_SIZE = 10;
  p1 = new int[THIRD_ARRAY_SIZE];
  for (int index = 0; index < THIRD_ARRAY_SIZE; ++index)
  {
    *(p1 + index) = pow(2, index);
  }
  
  const int FOURTH_ARRAY_SIZE = 10;
  p2 = new int[FOURTH_ARRAY_SIZE];
  for (int index = 0; index < FOURTH_ARRAY_SIZE; ++index)
  {
    *(p2 + index) = *(p1+index);
  }

  print_array(cout, p1, THIRD_ARRAY_SIZE);
  print_array(cout, p2, FOURTH_ARRAY_SIZE);

  delete[] p1;
  delete[] p2;


  vector<int> vp1(THIRD_ARRAY_SIZE, 0);
  for (int index = 0; index < THIRD_ARRAY_SIZE; ++index)
  {
    vp1[index] = pow(2, index);
  }
  vector<int> vp2(vp1);
  print_array(cout, &vp1[0], THIRD_ARRAY_SIZE);
  print_array(cout, &vp2[0], FOURTH_ARRAY_SIZE);

	return 0;
}