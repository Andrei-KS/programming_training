/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/18/2023 14:47:44
	author                                          : Andrei-KS
*/

#include "CH20P754EXERC3RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P754EXERC3RunExmple();

namespace {
  /*
* Jack puts doubles into an arrayand
* @param count that will be filled and equal number of array elements  when this function finishes
* @return double* contains pointer to array data
*/
  double* get_from_jack(int* count)
  {
    fstream fs;
    string fileName = "JackData.txt";
    fs.open(fileName);
    if (!fs.is_open())
    {
      error(fileName + " isn't opened\n");
    }

    *count = 0;
    double value;
    while (fs >> value)
    {
      *count += 1;
    }

    fs.clear();
    fs.seekg(0);
    double* data = new double[*count];
    for (int index = 0; index < *count; ++index)
    {
      fs >> data[index];
    }

    return data;
  }

  /*
  * Jill fills the vector
  */
  vector<double>* get_from_jill()
  {
    fstream fs;
    string fileName = "JillData.txt";
    fs.open(fileName);
    if (!fs.is_open())
    {
      error(fileName + " isn't opened\n");
    }

    vector<double>* data = new vector<double>();
    double value;
    while (fs >> value)
    {
      data->push_back(value);
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

    h = -1;
    auto jill_dataIt = jill_data.begin();
    while (jill_dataIt != jill_data.end())
    {
      if (h < *jill_dataIt) {
        // save address of largest element
        jill_high = &(*jill_dataIt);
        // update “largest element”
        h = *jill_dataIt;
      }
      ++jill_dataIt;
    }

    cout << "Jill's max: " << *jill_high << ";\n"
      << "Jack's max: " << *jack_high;


    delete[] jack_data;
    delete& jill_data;
  }
}

int CH20P754EXERC3RunExmple::excute()
{
  fct();
	return 0;
}