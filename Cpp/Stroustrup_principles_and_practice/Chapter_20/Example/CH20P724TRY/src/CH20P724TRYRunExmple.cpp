/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/18/2023 08:13:23
	author                                          : Andrei-KS
*/

#include "CH20P724TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P724TRYRunExmple();

namespace {
  const int MAX_ARRAY_SIZE = 100;
  const int MAX_FRACTION = 100;
  const int MAX_VALUE = 100000;

  /*
  * Jack puts doubles into an arrayand
  * @param count that will be filled and equal number of array elements  when this function finishes
  * @return double* contains pointer to array data
  */
  double* get_from_jack(int* count)
  {
    random_device rd;
    *count = rd() % (MAX_ARRAY_SIZE - 5) + 5;
    double* data = new double[*count];
    for (int index = 0; index < *count; ++index)
    {
      *(data + index) = 1.0 * (rd() % MAX_VALUE) / MAX_FRACTION;
    }
    return data;
  }

  /*
  * Jill fills the vector
  */
  vector<double>* get_from_jill()
  {
    random_device rd;
    vector<double>* data = new vector<double>(rd() % (MAX_ARRAY_SIZE - 5) + 5);
    for (int index = 0; index < data->size(); ++index)
    {
      (*data)[index] = 1.0 * (rd() % MAX_VALUE) / MAX_FRACTION;
    }
    return data;
  }

  /*
  * @return an iterator to the element in[first:last) that has the highest value
  */
  template<typename Iterator>
  Iterator high(Iterator first, Iterator last)
  {
    if (first == last)
    {
      return nullptr;
    }

    Iterator high = first;
    for (Iterator p = first; p != last; ++p)
    if (*high < *p) high = p;
    return high;
  }

  template<typename Iterator>
  void printMax(string text, Iterator it)
  {
    if (!it)
    {
      cout << text <<" data is empty\n";
    }
    else
    {
      cout << text << " max: " << *it << "\n";
    }
  }

  void fct()
  {
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    //vector<double>* jill_data = get_from_jill();
    vector<double>& jill_data = *get_from_jill();

    //. ..process . . .
    // jack_high will point to the element with the highest value
    double* jack_high = high(jack_data, jack_data+ jack_count);
    // jill_high will point to the element with the highest value
    double* jill_high = high(&jill_data[0], (&jill_data[0]) + jill_data.size());

    printMax("Jack's", jack_high);
    printMax("Jill's", jill_high);

    delete[] jack_data;
    delete& jill_data;
  }
}

int CH20P724TRYRunExmple::excute()
{
  fct();
	return 0;
}