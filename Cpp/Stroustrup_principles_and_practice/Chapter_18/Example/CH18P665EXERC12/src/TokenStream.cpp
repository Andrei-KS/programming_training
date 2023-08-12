#include "TokenStream.h"
#include <iostream>
#include <exception>
#include <iomanip>
#include <string>

namespace GameWithGraphMap
{
  Token::Token(TokenType type)
    : mType{ type }
    , mIntValue{ 0 }
  {
  }

  Token::Token(TokenType type, int value)
    : mType{ type }
    , mIntValue{ value }
  {
  }

  TokenType Token::GetType() const
  {
    return mType;
  }

  int Token::GetValue() const
  {
    return mIntValue;
  }

  TokenStream::TokenStream()
    : mFull{ false }
    , mBuffer{ Token(TokenType::NONE) }
    , mIStream{&std::cin}
  {
  }

  TokenStream::TokenStream(std::istream* istream)
    : mFull{ false }
    , mBuffer{ Token(TokenType::NONE) }
    , mIStream{ istream }
  {
  }

  Token TokenStream::Get()
  {
    if (mFull)
    {
      mFull = false;
      return mBuffer;
    }

    Token token{TokenType::NONE};
    char symbol = mIStream->get();
    while (true)
    {
      if (isdigit(symbol))
      {
        mIStream->putback(symbol);
        int value;
        (*mIStream) >> value;
        return Token(TokenType::INT_VALUE, value);
      }

      if (symbol == 'm')
      {
        char nextSymbol = mIStream->get();
        mIStream->putback(nextSymbol);
        if (isdigit(nextSymbol))
        {
          return Token(TokenType::MOVE);
        }
      }

      if (symbol == 's')
      {
        char nextSymbol = mIStream->get();
        mIStream->putback(nextSymbol);
        if (isdigit(nextSymbol))
        {
          return Token(TokenType::SHOOT);
        }
      }

      if (symbol == '-')
      {
        char nextSymbol = mIStream->get();
        mIStream->putback(nextSymbol);
        if (isdigit(nextSymbol))
        {
          return Token(TokenType::CONNECTOR);
        }
      }

      if (symbol == '\n')
      {
        return Token(TokenType::LINE_END);
      }
        
      if (isalpha(symbol))
      {
        mIStream->putback(symbol);
        std::string value;
        *mIStream >> value;
        if (value == "quit")
        {
          return Token(TokenType::QUIT);
        }
        else if (value == "new")
        {
          return Token(TokenType::NEW);
        }
        else if (value == "help")
        {
          return Token(TokenType::HELP);
        }
      }

      return Token(TokenType::BAD_TOKEN);
    }
  }

  void TokenStream::Ignore(char c)
  {
    if (mFull)
    {
      mFull = false;
      if (c == '\n' && mBuffer.GetType() == TokenType::LINE_END)
      {
        mBuffer = Token(TokenType::NONE);
        return;
      }
    }

    char ch = 0;
    while (mIStream->get(ch))
    {
      if (ch == c)
      {
        return;
      }
    }
  }
}