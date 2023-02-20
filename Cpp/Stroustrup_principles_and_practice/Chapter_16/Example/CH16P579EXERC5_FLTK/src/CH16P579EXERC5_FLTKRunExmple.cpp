/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 02/20/2023 06:20:01
	author                                          : Andrei-KS
*/

#include "CH16P579EXERC5_FLTKRunExmple.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include "My_window.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH16P579EXERC5_FLTKRunExmple();

namespace {
  constexpr int FORM_SIZE = 50;

  // Definition of kinds
  constexpr char NUMBER_KIND = '8';	// we use ‘8’ to represent a number

  /*
  * Token class - this type is required for lexicographic analysis
  * It has two parts (called members): kind and value
  */
  class Token
  {
  public:
    /* kind of tokens */
    char kind;

    /* for numeric tokens: value */
    double value;

    /* for string tokens: name */
    string name;

    /*
    * Make a Token from a char
    * @param ch - defines the kind of token to be created
    */
    Token(char ch) :kind(ch), value(0), name("") { }

    /*
    * Make a Token from a char and a double
    * @param ch - defines the kind of token to be created
    * @param val - defines the value of token to be created
    */
    Token(char ch, double val) :kind(ch), value(val), name("") { }

    /*
    * Make a Token from a char and a double
    * @param ch - defines the kind of token to be created
    * @param name - defines the name of token to be created
    */
    Token(char ch, string name) :kind(ch), value(0), name(name) { }
  };

  /*
  * Token_stream class - this type is required for lexicographic analysis.
  * This class has the ability to receive from stream (cin)
  * and return tokens to the stream (cin).
  *
  * Important: We assume that tokens are returned to the
  * stream no more than one at a time.
  *
  * @see Token
  */
  class Token_stream
  {
  public:
    /*
    * Creates an object of the Token Stream.
    */
    Token_stream::Token_stream()
      :full(false)
      ,buffer(Token('\0'))
      ,stream(&cin)
    {}

    /*
    * Creates an object of the Token Stream.
    * @param st - a stream that gives data for processing
    */
    Token_stream(istream& st)
      :full(false)
      ,buffer(Token('\0'))
      ,stream(&st)
    {}

    /*
    * Retrieves a Token object from a stream.
    * @return Token object
    */
    Token get()
    {
      if (full)
      {
        full = false;
        return buffer;
      }
      char ch;
      // note if not use noskipws then >> skips whitespace symbols
      // (space, newline, tab, etc.)
      cin >> noskipws >> ch;

      while (true) {
        switch (ch) {
        case '(':
        case ')':
        case ',':
        {
          // let each character represent itself
          return Token(ch);
        }
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {
          // put digit back into the input stream
          cin.putback(ch);
          int val;
          cin >> val;

          // let '8' represent "a number"
          return Token(NUMBER_KIND, val);
        }
        default:
        {
          if (isspace(ch))
          {
            cin >> noskipws >> ch;
            continue;
          }
          error("Bad token");
        }
        }
      }
    }

    /*
    * Returns the Token back to the stream.
    * @param token - which will return to the stream.
    */
    void putback(Token token)
    {
      if (full) error("putback(): buffer is full");
      buffer = token;
      full = true;
    }

    /*
    * @param c - discard characters up to and including a c
    */
    void ignore(char c)
    {
      if (full && c == buffer.kind)
      {
        full = false;
        return;
      }
      full = false;

      char ch = 0;
      while (cin >> noskipws >> ch)
      {
        if (ch == c || ch == '\n')
        {
          return;
        }
      }
    }

  private:
    /* buffer busy indicator */
    bool full;

    /* the token is stored after returning with putback() */
    Token buffer;

    /*  */
    istream* stream;
  };

  struct Geometry_forms_window : Graph_lib::My_window {
  public:
    /*
    */
    Geometry_forms_window(Graph_lib::Point xy, int width, int height, const string& title)
      : My_window(xy, width, height, title)
      , token_stream()
    {
    }

    void push_shape(Graph_lib::Shape* shape_ptr, Graph_lib::Color = Graph_lib::Color::black)
    {
      if (shape_ptr)
      {
        forms.push_back(shape_ptr);
        shape_ptr->set_fill_color(Graph_lib::Color::black);
        attach(*shape_ptr);
        redraw();
      }
    }

    virtual void next()
    {
      bool isValid = true;
      Graph_lib::Point xyPoint = Graph_lib::Point();
      for (int pattern_index = 0; pattern_index < parsing_pattern.size(); ++pattern_index)
      {
        Token token = token_stream.get();
        if (token.kind != parsing_pattern[pattern_index])
        {
          isValid = false;
          break;
        }

        if (pattern_index == 1)
        {
          xyPoint.x = token.value;
        }

        if (pattern_index == 3)
        {
          xyPoint.y = token.value;
        }
      }

      if (isValid)
      {
        Graph_lib::Shape* ptr = new Graph_lib::Rectangle(xyPoint, FORM_SIZE, FORM_SIZE);
        push_shape(ptr);
      }

      My_window::next();
    }

  private:
    /**/
    Graph_lib::Vector_ref<Graph_lib::Shape> forms;
    
    /**/
    static const std::array<char, 5> parsing_pattern;

    /**/
    Token_stream token_stream;
  };

  const std::array<char, 5> Geometry_forms_window::parsing_pattern = { '(', NUMBER_KIND, ',', NUMBER_KIND, ')' };
}

int CH16P579EXERC5_FLTKRunExmple::excute()
{
  Geometry_forms_window myWindow({ 100,100 }, 600, 400, "CH16P579EXERC5_FLTKRunExmple");

  return Graph_lib::gui_main();
}