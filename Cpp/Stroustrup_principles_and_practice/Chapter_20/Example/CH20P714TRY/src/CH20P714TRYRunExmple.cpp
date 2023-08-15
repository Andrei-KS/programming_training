/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/14/2023 09:07:38
	author                                          : Andrei-KS
*/
//#include <cstdlib>
#include "CH20P714TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P714TRYRunExmple();

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
    *count = rd()% (MAX_ARRAY_SIZE-5) + 5;
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
  
  void fct()
  {
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    //vector<double>* jill_data = get_from_jill();
    vector<double>& jill_data = *get_from_jill();
    
    //. ..process . . .
    // jack_high will point to the element with the highest value
    double* jack_high;
    // jill_high will point to the element with the highest value
    double* jill_high;
    
    
    double h = -1;
    for (int i = 0; i < jack_count; ++i)
    {
      if (h < jack_data[i]) {
        // save address of largest element
        jack_high = &jack_data[i];
        // update “largest element”
        h = jack_data[i];
      }
    }

    //h = -1;
    //for (int i = 0; i < jill_data->size(); ++i)
    //{
    //  if (h < (*jill_data)[i]) {
    //    // save address of largest element
    //    jill_high = &(*jill_data)[i];
    //    // update “largest element”
    //    h = (*jill_data)[i];
    //  }
    //}

    h = -1;
    for (int i = 0; i < jill_data.size(); ++i)
    {
      if (h < (jill_data)[i]) {
        // save address of largest element
        jill_high = &(jill_data)[i];
        // update “largest element”
        h = (jill_data)[i];
      }
    }
    cout << "Jill's max: " << *jill_high << ";\n"
      << "Jack's max: " << *jack_high;


    delete[] jack_data;
    delete &jill_data;
  }
}

int CH20P714TRYRunExmple::excute()
{
  fct();
	return 0;
}