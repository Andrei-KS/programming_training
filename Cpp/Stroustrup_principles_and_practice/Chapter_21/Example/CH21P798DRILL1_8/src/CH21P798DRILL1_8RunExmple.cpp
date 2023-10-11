/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/15/2023 13:39:22
	author                                          : Andrei-KS
*/

#include "CH21P798DRILL1_8RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P798DRILL1_8RunExmple();

namespace {
  /*
  */
  struct Item {
    /**/
    string name;

    /**/
    int iid;

    /**/
    double value;
  };

  ostream& operator<<(ostream& os, const Item& item)
  {
    os << "{" << item.name
      << "," << item.iid
      << "," << item.value
      << "}";
    return os;
  }

  istream& operator>>(istream& is, Item& item)
  {
    Item tItem;
    char symbol, nextSymbol;
    is.get(symbol);
    while (symbol != '{')
    {
      if (is.eof())
      {
        item = tItem;
        return is;
      }
      is.get(symbol);
    }
    is.get(nextSymbol);
    if (!is && symbol != '{' && nextSymbol != '\"')
    {
      is.setstate(ios::failbit);
      return is;
    }
    
    while (is.get(symbol) && (isalnum(symbol) || symbol == '_'))
    {
      tItem.name.push_back(symbol);
    }

    is.get(nextSymbol);
    if (symbol != '\"' && nextSymbol != ',')
    {
      is.setstate(ios::failbit);
      return is;
    }

    is >> tItem.iid;
    if (is.get(symbol) && symbol != ',')
    {
      is.setstate(ios::failbit);
      return is;
    }

    is >> tItem.value;
    if (is.get(symbol) && symbol != '}')
    {
      is.setstate(ios::failbit);
      return is;
    }

    item = tItem;
    return is;
  }

  ostream& operator<<(ostream& os, const vector<Item>& vItem)
  {
    for (vector<Item>::const_iterator cit = vItem.begin(); cit != vItem.end(); ++cit)
    {
      os << *cit << "\n";
    }
    return os;
  }

  vector<Item>::iterator searchByName(const string& name, vector<Item>& vi)
  {
    return find_if(vi.begin(), vi.end(), [name](const Item& i) { return i.name == name; });
  }

  vector<Item>::iterator searchById(int id, vector<Item>& vi)
  {
    return find_if(vi.begin(), vi.end(), [id](const Item& i) { return i.iid == id; });
  }

  ostream& operator<<(ostream& os, const list<Item>& vItem)
  {
    for (list<Item>::const_iterator cit = vItem.begin(); cit != vItem.end(); ++cit)
    {
      os << *cit << "\n";
    }
    return os;
  }

  list<Item>::iterator searchByName(const string& name, list<Item>& vi)
  {
    return find_if(vi.begin(), vi.end(), [name](const Item& i) { return i.name == name; });
  }

  list<Item>::iterator searchById(int id, list<Item>& vi)
  {
    return find_if(vi.begin(), vi.end(), [id](const Item& i) { return i.iid == id; });
  }
}

int CH21P798DRILL1_8RunExmple::excute()
{
  cout << "\n\n---Test---\n";
  vector<Item> vi = {
    {"frist",1,3.0},
    {"second",2,19.0},
    {"third",3,2.0},
    {"fourth",4,32.1},
    {"fifth",5,32.0},
    {"sixth",6,33.0},
    {"seventh",7,-1.0},
    {"eighth",8,9.0},
    {"ninth",9,-11.0},
    {"tenth",10,1.0},
  };
  cout << "Get data from code:\n";
  cout << vi;

  cout << "\n\n---Test 1---\n";
  string fileName = "CH21P798DRILL1_8Data";
  cout << "Get data from \"" << fileName << "\" file :\n";
  ifstream fileIStream(fileName);
  if (!fileIStream.is_open())
  {
    error(fileName + " is not opened\n");
  }
  // make input iterator from stream
  istream_iterator<Item> is_iterator{ fileIStream };
  // input sentinel
  istream_iterator<Item> eos;
  vi = vector<Item>{ is_iterator, eos };
  fileIStream.close();
  cout << vi;

  cout << "\n\n---Test 2---\n";
  sort(vi.begin(), vi.end(), [](const Item& lhs, const Item& rhs) { return lhs.name < rhs.name; });
  cout << vi;

  cout << "\n\n---Test 3---\n";
  sort(vi.begin(), vi.end(), [](const Item& lhs, const Item& rhs) { return lhs.iid < rhs.iid; });
  cout << vi;

  cout << "\n\n---Test 4---\n";
  sort(vi.begin(), vi.end(), [](const Item& lhs, const Item& rhs) { return lhs.value > rhs.value; });
  cout << vi;

  cout << "\n\n---Test 5---\n";
  vi.insert(vi.begin(), { Item{"horse shoe",99,12.34},Item{"Canon S400",9988,499.95} });
  cout << vi;

  cout << "\n\n---Test 6---\n";
  vi.erase(searchByName("frist",vi));
  vi.erase(searchByName("sixth",vi));
  cout << vi;

  cout << "\n\n---Test 7---\n";
  vi.erase(searchById(8, vi));
  vi.erase(searchById(4, vi));
  cout << vi;

  cout << "\n\n---Test 1 (list version)---\n";
  fileName = "CH21P798DRILL1_8Data";
  cout << "Get data from \"" << fileName << "\" file :\n";
  fileIStream = ifstream(fileName);
  if (!fileIStream.is_open())
  {
    error(fileName + " is not opened\n");
  }
  // make input iterator from stream
  is_iterator = istream_iterator<Item>{fileIStream};
  // input sentinel
  eos = istream_iterator<Item>();
  vi = vector<Item>{ is_iterator, eos };
  fileIStream.close();
  cout << vi;

  cout << "\n\n---Test 2 (list version)---\n";
  sort(vi.begin(), vi.end(), [](const Item& lhs, const Item& rhs) { return lhs.name < rhs.name; });
  cout << vi;

  cout << "\n\n---Test 3 (list version)---\n";
  sort(vi.begin(), vi.end(), [](const Item& lhs, const Item& rhs) { return lhs.iid < rhs.iid; });
  cout << vi;

  cout << "\n\n---Test 4 (list version)---\n";
  sort(vi.begin(), vi.end(), [](const Item& lhs, const Item& rhs) { return lhs.value > rhs.value; });
  cout << vi;

  cout << "\n\n---Test 5 (list version)---\n";
  vi.insert(vi.begin(), { Item{"horse shoe",99,12.34},Item{"Canon S400",9988,499.95} });
  cout << vi;

  cout << "\n\n---Test 6 (list version)---\n";
  vi.erase(searchByName("frist", vi));
  vi.erase(searchByName("sixth", vi));
  cout << vi;

  cout << "\n\n---Test 7 (list version)---\n";
  vi.erase(searchById(8, vi));
  vi.erase(searchById(4, vi));
  cout << vi;

	return 0;
}