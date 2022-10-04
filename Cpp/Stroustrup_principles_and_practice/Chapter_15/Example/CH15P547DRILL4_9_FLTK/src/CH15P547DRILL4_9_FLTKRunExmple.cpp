/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 09/20/2022 17:41:38
	author                                          : Andrei-KS
*/

#include "CH15P547DRILL4_9_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH15P547DRILL4_9_FLTKRunExmple();

namespace {
  constexpr bool SIMPLE_TEST = false;

  string forbidden—haracters = ";:\"'[]*&^%$#@!.";

  /*
  */
  struct Person {
    /*
    */
    Person(const string& firstName, int age)
      : mFirstName(firstName)
      , mSecondName("")
      , mAge(age)
    {
      if (mAge < 0 || mAge >= 150)
      {
        error("Person: Person: age is not into range [0:150), current age is equal ", mAge);
      }

      if (!checkName(first_name()))
      {
        error("Person: Person: first_name contain some of the characters from list: ;:\"'[]*&^%$#@!.");
      }
    }
    
    /*
    */
    Person(const string& firstName, const string& secondName, int age)
      : mFirstName(firstName)
      , mSecondName(secondName)
      , mAge(age)
    {
      if (mAge < 0 || mAge >= 150)
      {
        error("Person: Person: age is not into range [0:150), current age is equal ", mAge);
      }

      if (!checkName(first_name()))
      {
        error("Person: Person: name contain some of the characters from list: ;:\"'[]*&^%$#@!.");
      }

      if (!checkName(second_name()))
      {
        error("Person: Person: second_name contain some of the characters from list: ;:\"'[]*&^%$#@!.");
      }
    }

    /*
    */
    const string& first_name() const
    {
      return mFirstName;
    }

    /*
    */
    const string& second_name() const
    {
      return mSecondName;
    }

    /*
    */
    const int age() const
    {
      return mAge;
    }

  private:
    /*
    */
    bool checkName(const string& name)
    {
      for (const char symbol : first_name())
      {
        for (const char forbidden—haracter : forbidden—haracters)
        {
          if (forbidden—haracter == symbol)
          {
            return false;
          }
        }
      }
      return true;
    }

    /**/
    string mFirstName;

    /**/
    string mSecondName;

    /**/
    int mAge;
  };

  /*
  */
  ostream& operator<<(ostream& ost, const Person& person)
  {
    return ost << "(" << person.first_name() << ", "
      << person.second_name() << ", "
      << person.age() << ")";
  }

  /*
  */
  istream& operator>>(istream& ist, Person& person)
  {
    int step = 0;
    string firstName;
    string secondName;
    int age;

    // step 0: get '('
    // step 1: get first name
    // step 2: get ','
    // step 3: get second name
    // step 4: get ','
    // step 5: get age
    // step 6: get ')'
    // step 7: finished reading
    while (step < 7)
    {
      char ch = ist.get();
      switch (ch)
      {
        case ' ':
        {
          break;
        }
        case '(':
        {
          if (step != 0)
          {
            ist.putback(ch);
            ist.clear(ios_base::failbit);
            return ist;
          }
          step++;
          break;
        }
        case ',':
        {
          if(step != 2 && step != 4)
          {
            ist.putback(ch);
            ist.clear(ios_base::failbit);
            return ist;
          }
          step++;
          break;
        }
        case ')':
        {
          if (step != 6)
          {
            ist.putback(ch);
            ist.clear(ios_base::failbit);
            return ist;
          }
          step++;
          break;
        }
        default:
        {
          if ((step == 1 || step == 3) && isalpha(ch))
          {
            string str = string() + ch;
            while(ist.get(ch))
            {
              if(!isalnum(ch) && ch != '_')
              {
                break;
              }
              str += ch;
            }
            ist.putback(ch);
            switch (step)
            {
              case 1:
              {
                firstName = str;
                break;
              }
              case 3:
              {
                secondName = str;
                break;
              }
            }
            step++;
            break;
          }

          if (step == 5 && isdigit(ch))
          {
            ist.putback(ch);
            ist >> age;
            step++;
            break;
          }

          ist.putback(ch);
          ist.clear(ios_base::failbit);
          return ist;
        }
      }
    }
    person = Person(firstName, secondName, age);
    return ist;
  }

  /*
  */
  vector<Person> getPersons(istream& ist)
  {
    vector<Person> result;
    Person person{"None",0};
    while (ist)
    {
      char ch;
      ist.get(ch);
      if (ch == '(')
      {
        ist.putback(ch);
        ist >> person;
        if (ist || ist.eof())
        {
          result.push_back(person);
        }
        if (ist.fail())
        {
          cout << "format fail\n";
          ist.clear();
        }
      }
    }
    return result;
  }
}

int CH15P547DRILL4_9_FLTKRunExmple::excute()
{

  if (SIMPLE_TEST)
  {
    Person pr1{"Goofy",63};
    cout << pr1 << "\n";
    cin >> pr1;
    cout << pr1 << "\n";

    try
    {
      Person pr2{ "Aton", -1 };
    }
    catch (const exception& e)
    {
      cout << e.what() << "\n";
    }

    try
    {
      Person pr2{ "Aton",152};
    }
    catch (const exception& e)
    {
      cout << e.what() << "\n";
    }

    try
    {
      Person pr2{ "At^on",100 };
    }
    catch (const exception& e)
    {
      cout << e.what() << "\n";
    }
  }
  vector<Person> persons = getPersons(cin);
  for (const Person& pr : persons)
  {
    cout << pr << "\n";
  }

  return 0;
}