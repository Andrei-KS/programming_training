/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 08/25/2023 16:29:49
	author                                          : Andrei-KS
*/

#include "CH20P755EXERC10RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH20P755EXERC10RunExmple();

namespace {
  class Text_iterator;
  /*
  */
  struct Document
  {
  private:
    /**/
    static const long long BIG_PRIME_NUMBER = 100000007;

    /**/
    static const long long ALPHABET_MULTIPLIER = 263;

  public:
    /**/
    using Line = vector<char>;

    /* a document is a list of lines */
    list<Line> mLines;

    /*
    */
    Document();

    /*
    * first character of first line
    */
    Text_iterator begin();

    /*
    * one beyond the last character of the last line
    */
    Text_iterator end();

    /*
    */
    Text_iterator erase(Text_iterator it, int count = 1);

    /*
    */
    Text_iterator insert(Text_iterator it, const string& source);

    /*
    */
    Text_iterator search(const string& pattern);

    /*
    */
    Text_iterator replace(const string& pattern, const string& source);

    /*
    */
    int size();

    /*
    */
    int wordCount(bool IsOnlyAlphabet = false);

    /*
    */
    int wordCount(const string& whitespace);
  };

  /*
  */
  istream& operator>>(istream& is, Document& d);

  /*
  */
  void print(Document& d);

  /*
  * keep track of line and character position within a line
  */
  class Text_iterator
  {
    list<Document::Line>::iterator ln;
    Document::Line::iterator pos;
  public:
    /*
    */
    Text_iterator(list<Document::Line>::iterator ll, Document::Line::iterator pp);

    /*
    */
    char& operator*() { return *pos; }

    /*
    */
    Text_iterator& operator++();

    /*
    */
    bool operator==(const Text_iterator& other) const
    {
      return ln == other.ln && pos == other.pos;
    }

    /*
    */
    bool operator!=(const Text_iterator& other) const
    {
      return !(*this == other);
    }

  };


  //------------------------
  //  Implimentation
  //------------------------


  // Document implimentation
  Document::Document()
  {
    mLines.push_back(Line());
  }

  Text_iterator Document::begin()
  {
    return Text_iterator(mLines.begin(), (*mLines.begin()).begin());
  }

  Text_iterator Document::end()
  {
    auto last = mLines.end();
    --last;
    return Text_iterator(last, (*last).end());
  }

  Text_iterator Document::erase(Text_iterator it, int count)
  {
    if (it == end() || count < 1)
    {
      return it;
    }

    int counter = 0;
    Text_iterator counterIterator = begin();
    list<Line>::iterator listIterator = mLines.begin();
    while (it != counterIterator)
    {
      ++counter;
      ++counterIterator;
      if (counter == listIterator->size())
      {
        ++listIterator;
        counter = 0;
      }
    }

    int remainigCount = count - (listIterator->size() - counter);
    int amountOfDeleteLine = 0;
    list<Line>::iterator currentIterator = listIterator;
    while (remainigCount > 0)
    {
      ++currentIterator;
      ++amountOfDeleteLine;
      remainigCount -= currentIterator->size();
    }

    Text_iterator ret = end();

    if (amountOfDeleteLine == 0)
    {
      Line::iterator startIt = listIterator->begin();
      advance(startIt, counter);
      Line::iterator endIt = startIt;
      advance(endIt, count);
      ret = Text_iterator(listIterator, listIterator->erase(startIt, endIt));
    }
    else
    {
      Line::iterator startIt = listIterator->begin();
      advance(startIt, counter);
      startIt = listIterator->erase(startIt, listIterator->end());
      Line::iterator startInputIt = currentIterator->begin();
      advance(startInputIt, currentIterator->size() + remainigCount);
      listIterator->insert(startIt, startInputIt, currentIterator->end());
      listIterator = mLines.erase(++listIterator, ++currentIterator);

      --listIterator;
      startIt = listIterator->begin();
      advance(startIt, counter);
      ret = Text_iterator(listIterator, startIt);
    }

    return ret;
  }

  Text_iterator Document::insert(Text_iterator it, const string& source)
  {

    if (!source.size())
    {
      return it;
    }

    int counter = 0;
    Text_iterator counterIterator = begin();
    list<Line>::iterator listIterator = mLines.begin();
    while (it != counterIterator)
    {
      ++counter;
      ++counterIterator;
      if (counter == listIterator->size())
      {
        ++listIterator;
        counter = 0;
      }
    }

    Line::iterator startIt = listIterator->begin();
    advance(startIt, counter);
    Line endPart(startIt, listIterator->end());
    listIterator->erase(startIt, listIterator->end());
    for (char ch : source)
    {
      listIterator->push_back(ch);
      if (ch == '\n')
      {
        ++listIterator;
        listIterator = mLines.insert(listIterator, Document::Line{});
      }
    }

    counter = listIterator->size();
    listIterator->insert(listIterator->end(), endPart.begin(), endPart.end());
    startIt = listIterator->begin();
    advance(startIt, counter);
    return Text_iterator(listIterator, startIt);
  }

  Text_iterator Document::search(const string& pattern)
  {
    const size_t patternSize = pattern.size();
    const size_t textSize = size();

    if (patternSize > textSize)
    {
      return end();
    }

    long long hashPattern = 0;
    string::const_iterator pcit = pattern.begin();
    for (size_t index = 0; index < patternSize; ++index)
    {
      hashPattern *= ALPHABET_MULTIPLIER;
      hashPattern %= BIG_PRIME_NUMBER;
      hashPattern += *pcit;
      hashPattern %= BIG_PRIME_NUMBER;
      ++pcit;
    }

    long long hashText = 0;
    Text_iterator textiterator = begin();
    for (size_t index = 0; index < patternSize; ++index)
    {
      hashText *= ALPHABET_MULTIPLIER;
      hashText %= BIG_PRIME_NUMBER;
      hashText += *textiterator;
      hashText %= BIG_PRIME_NUMBER;
      ++textiterator;
    }

    long long maxOrderMultiplier = 1;
    for (size_t index = 0; index < patternSize - 1; ++index)
    {
      maxOrderMultiplier *= ALPHABET_MULTIPLIER;
      maxOrderMultiplier %= BIG_PRIME_NUMBER;
    }

    Text_iterator secondTextiterator = begin();
    while (textiterator != end())
    {
      if (hashPattern == hashText)
      {
        bool isFind = true;
        Text_iterator probTextiterator = secondTextiterator;
        for (char ch : pattern)
        {
          if (*probTextiterator != ch)
          {
            isFind = false;
            break;
          }
          ++probTextiterator;
        }
        if (isFind)
        {
          return secondTextiterator;
        }
      }
      hashText -= ((*secondTextiterator) * maxOrderMultiplier) % BIG_PRIME_NUMBER;
      if (hashText < 0) hashText += BIG_PRIME_NUMBER;
      hashText *= ALPHABET_MULTIPLIER;
      hashText %= BIG_PRIME_NUMBER;
      hashText += *textiterator;
      hashText %= BIG_PRIME_NUMBER;
      ++textiterator;
      ++secondTextiterator;
    }

    return end();
  }

  Text_iterator Document::replace(const string& pattern, const string& source)
  {
    Text_iterator searchIterator = search(pattern);
    if (searchIterator == end())
    {
      return end();
    }

    searchIterator = erase(searchIterator, pattern.size());
    searchIterator = insert(searchIterator, source);

    return searchIterator;
  }

  int Document::size()
  {
    int result = 0;
    for (Line l : mLines)
    {
      result += l.size();
    }
    return result;
  }

  template<typename Func>
  int wordCountHelper(Document& doc, Func& fun)
  {
    int result = 0;
    int addWord = 1;
    Text_iterator it = doc.begin();
    while (it != doc.end())
    {
      if (fun(*it))
      {
        result += addWord;
        addWord = 0;
      }
      else
      {
        addWord = 1;
      }
      ++it;
    }

    return result;
  }


  struct IsNotWhitespace
  {
    IsNotWhitespace(string ws) : mWhiteSpace{ ws } {}
    int operator()(int ch)
    {
      for (char symbol : mWhiteSpace)
      {
        if (ch == symbol)
        {
          return 0;
        }
      }

      return 1;
    }
  private:
    string mWhiteSpace;
  };

  int Document::wordCount(const string& whitespace)
  {
    IsNotWhitespace isNotWhitespace(whitespace);
    return wordCountHelper(*this,isNotWhitespace);
  }

  int Document::wordCount(bool IsOnlyAlphabet)
  {
    int (*comp)(int) = isalnum;
    if (IsOnlyAlphabet)
    {
      comp = isalpha;
    }

    return wordCountHelper(*this,comp);
  }

  istream& operator>>(istream& is, Document& d)
  {
    for (char ch; is.get(ch);)
    {
      // add the character
      d.mLines.back().push_back(ch);
      if (ch == '\n')
      {
        // add another line
        d.mLines.push_back(Document::Line{});
      }
    }

    // add final empty line
    if (d.mLines.back().size())
    {
      d.mLines.push_back(Document::Line{});
    }

    return is;
  }

  void print(Document& d)
  {
    for (auto p : d)
    {
      cout << p;
    }
  }

  // Text_iterator implimentation
  Text_iterator::Text_iterator(list<Document::Line>::iterator ll, Document::Line::iterator pp)
    : ln{ ll }
    , pos{ pp }
  {
  }

  Text_iterator& Text_iterator::operator++()
  {
    // procees to next character
    ++pos;
    if (pos == (*ln).end())
    {
      // proceed to next line
      ++ln;
      // bad if ln == line.end(); so make sure it isn't
      pos = (*ln).begin();
    }
    return *this;
  }
}

int CH20P755EXERC10RunExmple::excute()
{
  stringstream ss{ "as1aa aa\na aa v2\n22222\n111111\n" };
  Document doc;
  ss >> doc;
  print(doc);
  cout << "\ncount alphabet word : " << doc.wordCount(true) << "\n";
  cout << "\ncount alphabet and number word : " << doc.wordCount() << "\n";
  cout << "\ncount word with \"a1\" whitespace: " << doc.wordCount(string("s")) << "\n";
	return 0;
}