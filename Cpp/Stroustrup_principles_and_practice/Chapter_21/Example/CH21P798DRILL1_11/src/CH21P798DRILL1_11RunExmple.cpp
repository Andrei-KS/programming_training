/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 10/11/2023 08:24:31
	author                                          : Andrei-KS
*/

#include "CH21P798DRILL1_11RunExmple.h"
#include <map>
#include <numeric>
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P798DRILL1_11RunExmple();

namespace {
  // using "Overloading >> ifstream_iterator for pairs [duplicate]" topic
  // from https://stackoverflow.com/questions/28054528/overloading-ifstream-iterator-for-pairs
  // for resolve issue with istream_iterator<> and std::pair
  /*
  * You'll note that simply doing this:
  *   T t;
  *   infile >> t;
  *
  * Works like a charm! What is up?
  * 
  * std::pair is declared in namespace std.
  * 
  * istream_iterator<> uses operator>> indeed, and it does
  * so using ADL at instantiation time (this is known as two-phase-lookup).
  *
  * However, at instantiation time, it will not consider your operator>> as
  * it doesn't exist in the namespace that implements istream_iterator and\
  * neither was it declared in any of the associated namespaces implied by
  * the arguments (this is the ADL step).
  *
  * You could be tempted "fix" it by defining your overload in the
  * std namespace (and it works) but that is not allowed by the standard
  * and technically results in Undefined Behaviour.

  * So you'd do better to introduce a type that allows ADL to kick in:
  *   struct T : public std::pair<int,float> {};
  */
  template<typename TF, typename TS>
  struct tPair : public pair<TF, TS>
  {
    using pair<TF, TS>::pair;
  };

  template<typename TF, typename TS>
  ostream& operator<<(ostream& os, const tPair<TF, TS>& p)
  {
    return os << "{\"" << p.first
      << "\"," << p.second
      << "}";
  }

  template<typename TK, typename TV>
  ostream& operator<<(ostream& os, const map<TK, TV>& m)
  {
    for (map<TK, TV>::const_iterator it = m.begin(); it != m.end(); ++it)
    {
      os << static_cast<tPair<TK, TV>>(*it) << "\n";
    }
    return os;
  }

  istream& operator>>(istream& is, tPair<string, int>& psi)
  {
    pair<string, int> tpsi;
    char symbol, nextSymbol;
    is.get(symbol);
    while (symbol != '{')
    {
      if (is.eof())
      {
        psi = tpsi;
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
      tpsi.first.push_back(symbol);
    }

    is.get(nextSymbol);
    if (symbol != '\"' && nextSymbol != ',')
    {
      is.setstate(ios::failbit);
      return is;
    }

    is >> tpsi.second;
    if (is.get(symbol) && symbol != '}')
    {
      is.setstate(ios::failbit);
      return is;
    }

    psi = tpsi;
    return is;
  }
}


namespace std {

}

int CH21P798DRILL1_11RunExmple::excute()
{
  random_device rd;
  map<string, int> msi;
  msi["lecture"] = 21;
  for (int index = 0; index < 9; ++index)
  {
    msi["key" + to_string(index)] = rd() % (10+index);
  }
  cout << "--- msi: ---\n";
  cout << msi;

  msi.erase(msi.begin());
  cout << "\n--- msi: ---\n";
  cout << msi;

  cout << "\nenter item to msi:\n";
  msi.clear();
  istream_iterator<tPair<string, int>> is{ cin };
  istream_iterator<tPair<string, int>> eos;
  ostream_iterator<tPair<string, int>> oo{ cout, "\n"};
  
  while(is != eos)
  {
    msi.insert(*is);
    ++is;
  }
  cout << "\n--- msi: ---\n";
  copy(msi.begin(), msi.end(), oo);

  cout << "\n--- sum of values in msi:---\n"
    << accumulate(msi.begin(), msi.end(), 0, [](int value, const pair<string, int>& p) {return value + p.second; }) << "\n";

  cout << "\n--- msi tp mis:---\n";
  map<int, string> mis;
  for_each(msi.begin(), msi.end(), [&mis](const pair<string, int>& p)
    {
      mis[p.second] = p.first;
    }
  );
  ostream_iterator<tPair<int, string>> oo2{ cout, "\n" };
  copy(mis.begin(), mis.end(), oo2);

	return 0;
}