/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 11/06/2024 14:00:22
	author                                          : Andrei-KS
*/

#include "CH21P800EXERC9RunExmple.h"
#include <algorithm>
#include <functional>
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH21P800EXERC9RunExmple();

namespace CH21P800EXERC9NS{

  // trim from start (in place)
  void ltrim(string& s)
  {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char uch) {return !isspace(uch); }));
  }
 
  // trim from end (in place)
  void rtrim(string& s)
  {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char uch) {return !isspace(uch); }).base(), s.end());
  }

  string getTextField(istream& is, char delimitator = ',')
  {
    string textField;
    char ch;
    while (true)
    {
      ch = is.get();
      if (ch == delimitator) break;
      textField += ch;
    }
    is.putback(ch);
    ltrim(textField);
    rtrim(textField);
    return textField;
  }

  void skipIf(istream& is, const function<bool(int)>& condition)
  {
    char ch = is.get();
    while (condition(ch))
    {
      ch = is.get();
    }
    is.putback(ch);
  }

  class Purchase
  {
  public:
    enum FieldLabel
    {
      PRODUCT_NAME = 0,
      PRODUCT_UNITPRICE,
      PRODUCT_COUNT,
    };

    /* product info */
    string name;
    double unitPrice;
    unsigned int count;

    friend ostream& operator<<(ostream& os, const Purchase& purchase);
    friend istream& operator>>(istream& is, Purchase& purchase);
  };

  ostream& operator<<(ostream& os, const Purchase& purchase)
  {
    os << "{ " << purchase.name << ", " << purchase.unitPrice << ", " << purchase.count << " }";
    return os;
  }
  
  istream& operator>>(istream& is, Purchase& hPurchase)
  {
    Purchase purchase;
    bool isOpen = false;
    bool isRequestedCompletion = false;
    int separaterCount = 0;
    char ch;
    while (!isRequestedCompletion)
    {
      skipIf(is, isspace);
      ch = is.get();

      switch (ch)
      {
      case '{':
        {
          if (isOpen) error("error Purchase : istream& operator>>(istream& is, Purchase& purchase) : enter of the '{' symbol is incorrect.");
          isOpen = true;
          purchase.name = getTextField(is);
          ++separaterCount;
          break;
        }
      case ',':
        {
        switch (separaterCount)
        {
          case Purchase::PRODUCT_UNITPRICE:
            {
              is >> purchase.unitPrice;
              ++separaterCount;
              break;
            }
          case Purchase::PRODUCT_COUNT:
            {
              is >> purchase.count;
              ++separaterCount;
              break;
            }
          default:
            {
              error("error Purchase : istream& operator>>(istream& is, Purchase& purchase) : something is wrong format in case ','.");
              break;
            }
        }
          
          break;
        }
      case '}':
        {
          if (!isOpen) error("error Purchase : istream& operator>>(istream& is, Purchase& purchase) : enter of the '}' symbol is incorrect.");
          isRequestedCompletion = true;
          break;
        }
      default:
        {
          if (is.eofbit)
          {
            if (isOpen) error("error Purchase : istream& operator>>(istream& is, Purchase& purchase) : EoF reached but the purchase filling in is incomplete.");
            return is;
          }

          error("error Purchase : istream& operator>>(istream& is, Purchase& purchase) : something is wrong format.");
          break;
        }
      }
    }
    hPurchase = purchase;
    return is;
  }

  class Order
  {
  public:
    enum FieldLabel
    {
      CUSTOMER_NAME = 0,
      CUSTOMER_ADDRESS,
      CUSTOMER_DATA,
      CUSTOMER_PURCHASE,
    };

    /* customer info */
    string name;
    string address;
    string data;

    /* purchase info */
    vector<Purchase> purchases;

    friend ostream& operator<<(ostream& os, const Order& order);
    friend istream& operator>>(istream& is, Order& order);
  };
  
  ostream& operator<<(ostream& os, const Order& order)
  {
    os << "{ " << order.name << ", " << order.address << ", " << order.data << ", [";
    ostream_iterator<Purchase> oo(os, ", ");
    copy(order.purchases.begin(), order.purchases.end() - 1, oo);
    os << order.purchases.back() << " ]}";
    return os;
  }

  istream& operator>>(istream& is, Order& hOrder)
  {
    Order order;
    bool isOpen = false;
    bool isRequestedCompletion = false;
    int separaterCount = 0;
    char ch;
    while (!isRequestedCompletion)
    {
      skipIf(is, isspace);
      ch = is.get();

      switch (ch)
      {
      case '{':
      {
        if (isOpen) error("error Order : istream& operator>>(istream& is, Order& order) : enter of the '{' symbol is incorrect.");
        isOpen = true;
        order.name = getTextField(is);
        ++separaterCount;
        break;
      }
      case ',':
      {
        switch (separaterCount)
        {
          case Order::CUSTOMER_ADDRESS:
            {
              order.address = getTextField(is);
              ++separaterCount;
              break;
            }
          case Order::CUSTOMER_DATA:
            {
              order.data = getTextField(is);
              ++separaterCount;
              break;
            }
          case Order::CUSTOMER_PURCHASE:
            {
              skipIf(is, isspace);
              ch = is.get();
              if(ch != '[') error("error Order : istream& operator>>(istream& is, Order& order) : ']' is not found in CUSTOMER_PURCHASE case.");
              while (true)
              {
                skipIf(is, isspace);
                ch = is.get();
                if (ch == ']') break;
                if(ch != ',') is.putback(ch);
                Purchase p;
                is >> p;
                order.purchases.push_back(p);
              }
              ++separaterCount;
              break;
            }
          default:
            {
              error("error Order : istream& operator>>(istream& is, Order& order) : something is wrong format in case ','.");
              break;
            }
        }

        break;
      }
      case '}':
      {
        if (!isOpen) error("error Order : istream& operator>>(istream& is, Order& order) : enter of the '}' symbol is incorrect.");
        isRequestedCompletion = true;
        break;
      }
      default:
      {
        if (is.eofbit)
        {
          if (isOpen) error("error Order : istream& operator>>(istream& is, Order& order) : EoF reached but the order filling in is incomplete.");
          return is;
        }

        error("error Order : istream& operator>>(istream& is, Order& order) : something is wrong format.");
        break;
      }
      }  
    }
    hOrder = order;
    return is;
  }

  template<class T>
  void printToOStream(ostream& os, const T& sequence,const string& delimitator = "\n")
  {
    ostream_iterator<T::value_type> oo(os, delimitator.c_str());
    copy(sequence.begin(), sequence.end(), oo);
  }

  void printLabel(ostream& os, string labelText)
  {
    const int lengthBorder = 10;
    const auto adjustfield = os.flags();
    os.setf(ios_base::right, ios_base::adjustfield);
    os << setw(lengthBorder) << setfill('-') << "- ";
    os.unsetf(ios_base::adjustfield);
    os << labelText << setw(lengthBorder);
    os.setf(ios_base::left, ios_base::adjustfield);
    os << setw(lengthBorder) << setfill('-') << " -" << "\n";
    os.flags(adjustfield);
  }
}

int CH21P800EXERC9RunExmple::excute()
{
  using namespace CH21P800EXERC9NS;
  // make test files
  cout << "Need it create test files from this program?(y/n)";
  char ch;
  cin >> ch;
  if (ch == 'y')
  {
    ofstream oFile1("inputFile1.txt");
    if(!oFile1.is_open()) error("error CH21P800EXERC9RunExmple::excute() : can't open inputFile1.txt.");
    oFile1 << Order{ "Name11","Adress11","Data4",vector<Purchase>{{"PName2",15.1,2}} } << "\n";
    oFile1 << Order{ "Name1","Adress1","Data1",vector<Purchase>{{"PName1",32.0,1},{"PName2",15.1,2}} } << "\n";
    oFile1 << Order{ "Name2","Adress2","Data2",vector<Purchase>{{"PName1",32.0,3},{"PName2",15.1,2},{"PName3",15.0,4}}} << "\n";
    oFile1 << Order{ "Name3","Adress3","Data3",vector<Purchase>{{"PName1",32.0,4},{"PName2",15.1,2}} } << "\n";
    oFile1 << Order{ "Name4","Adress4","Data5",vector<Purchase>{{"PName1",32.0,5},{"PName2",15.1,2}} } << "\n";
    oFile1 << Order{ "Name5","Adress5","Data6",vector<Purchase>{{"PName1",32.0,3},{"PName2",15.1,4}} } << "\n";
    oFile1 << Order{ "Name6","Adress6","Data7",vector<Purchase>{{"PName1",32.0,5},{"PName2",15.1,21}} } << "\n";
    oFile1 << Order{ "Name7","Adress7","Data8",vector<Purchase>{{"PName1",32.0,5},{"PName2",15.1,2}} } << "\n";
    oFile1 << Order{ "Name2","Adress2","Data9",vector<Purchase>{{"PName1",32.0,3},{"PName2",15.1,2},{"PName3",15.0,4}}} << "\n";
    oFile1 << Order{ "Name3","Adress3","Data10",vector<Purchase>{{"PName1",32.0,3},{"PName2",15.1,2},{"PName3",15.0,4}}} << "\n";
    oFile1.close();
    
    ofstream oFile2("inputFile2.txt");
    if(!oFile2.is_open()) error("error CH21P800EXERC9RunExmple::excute() : can't open inputFile2.txt.");
    oFile2 << Order{ "3Name11","3Adress11","Data4",vector<Purchase>{{"PName2",15.1,2}} } << "\n";
    oFile2 << Order{ "4Name1","4Adress1","Data1",vector<Purchase>{{"PName1",32.0,1},{"PName2",15.1,2}} } << "\n";
    oFile2 << Order{ "2Name2","2Adress2","Data2",vector<Purchase>{{"PName1",32.0,3},{"PName2",15.1,2},{"PName3",15.0,4}}} << "\n";
    oFile2 << Order{ "5Name3","5Adress3","Data3",vector<Purchase>{{"PName1",32.0,4},{"PName2",15.1,2}} } << "\n";
    oFile2 << Order{ "1Name4","1Adress4","Data5",vector<Purchase>{{"PName1",32.0,5},{"PName2",15.1,2}} } << "\n";
    oFile2 << Order{ "2Name5","2Adress5","Data6",vector<Purchase>{{"PName1",32.0,3},{"PName2",15.1,4}} } << "\n";
    oFile2 << Order{ "3Name6","3Adress6","Data7",vector<Purchase>{{"PName1",32.0,5},{"PName2",15.1,21}} } << "\n";
    oFile2 << Order{ "4Name7","4Adress7","Data8",vector<Purchase>{{"PName1",32.0,5},{"PName2",15.1,2}} } << "\n";
    oFile2 << Order{ "5Name2","5Adress2","Data9",vector<Purchase>{{"PName1",32.0,3},{"PName2",15.1,2},{"PName3",15.0,4}}} << "\n";
    oFile2 << Order{ "6Name3","6Adress3","Data10",vector<Purchase>{{"PName1",32.0,3},{"PName2",15.1,2},{"PName3",15.0,4}}} << "\n";
    oFile2.close();
  }
  
  // sort by type
  {
    ifstream iFile1("inputFile1.txt");
    if(!iFile1.is_open()) error("error CH21P800EXERC9RunExmple::excute() : can't open inputFile1.txt.");
    vector<Order> firstPartOrders{ istream_iterator<Order>{iFile1}, istream_iterator<Order>{} };
    iFile1.close();

    printLabel(cout, "raw vector");
    printToOStream(cout, firstPartOrders);
    sort(firstPartOrders.begin(), firstPartOrders.end(), [](Order o1, Order o2) {return o1.name < o2.name; });
    printLabel(cout, "sorted vector by Name");
    printToOStream(cout, firstPartOrders);

    ofstream oFile1("OutputFile1.txt");
    if(!oFile1.is_open()) error("error CH21P800EXERC9RunExmple::excute() : can't open OutputFile1.txt.");
    printToOStream(oFile1, firstPartOrders);
    oFile1.close();


    ifstream iFile2("inputFile2.txt");
    if(!iFile2.is_open()) error("error CH21P800EXERC9RunExmple::excute() : can't open inputFile2.txt.");
    list<Order> secondPartOrders{ istream_iterator<Order>{iFile2}, istream_iterator<Order>{} };
    printLabel(cout, "raw list");
    printToOStream(cout, secondPartOrders);
    secondPartOrders.sort([](Order o1, Order o2) {return o1.address < o2.address; });
    //sort(secondPartOrders.begin(), secondPartOrders.end(), [](Order o1, Order o2) {return o1.address < o2.address; });
    // std::sort
    // Type requirements:
    // -RandomIt must meet the requirements of LegacyRandomAccessIterator.
    // -Compare must meet the requirements of Compare.
    // First requirement is not satisfied This we can't use this function
    printLabel(cout, "sorted list by Name");
    printToOStream(cout, secondPartOrders);
    iFile2.close();

    ofstream oFile2("OutputFile2.txt");
    if (!oFile2.is_open()) error("error CH21P800EXERC9RunExmple::excute() : can't open OutputFile2.txt.");
    printToOStream(oFile2, secondPartOrders);
    oFile2.close();
  }
  
  // merge
  {
    ifstream iFile1("OutputFile1.txt");
    if (!iFile1.is_open()) error("error CH21P800EXERC9RunExmple::excute() : can't open OutputFile1.txt.");
    ifstream iFile2("OutputFile2.txt");
    if (!iFile2.is_open())
    {
      iFile1.close();
      error("error CH21P800EXERC9RunExmple::excute() : can't open OutputFile2.txt.");
    }
    ofstream oFile3("OutputFile3.txt");
    if (!oFile3.is_open())
    {
      iFile1.close();
      iFile2.close();
      error("error CH21P800EXERC9RunExmple::excute() : can't open OutputFile3.txt.");
    }
    merge(istream_iterator<Order>(iFile1), istream_iterator<Order>(), istream_iterator<Order>(iFile2), istream_iterator<Order>(), ostream_iterator<Order>(oFile3,"\n"), [](Order o1, Order o2) {return false; });
    iFile1.close();
    iFile2.close();
    oFile3.close();
  }
	
  return 0;
}