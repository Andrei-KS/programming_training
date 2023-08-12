#ifndef __TOKENSTREAM_H__
#define __TOKENSTREAM_H__

#include <istream>

namespace GameWithGraphMap
{
  /*
  */
  enum class TokenType
  {
    NONE,
    MOVE,
    INT_VALUE,
    CONNECTOR,
    SHOOT,
    NEW,
    HELP,
    QUIT,
    LINE_END,
    BAD_TOKEN,
  };

  class Token
  {
  public:
    /*
    */
    Token(TokenType type);

    /*
    */
    Token(TokenType type, int value);

    /*
    */
    TokenType GetType() const;

    /*
    */
    int GetValue() const;

  private:
    /**/
    TokenType mType;

    /**/
    int mIntValue;
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
  class TokenStream
  {
  public:
    /*
    * Creates an object of the Token Stream.
    */
    TokenStream();

    /*
    * Creates an object of the Token Stream.
    * @param istream - source of tokens.
    */
    TokenStream(std::istream* istream);

    /*
    * Retrieves a Token object from a stream.
		* @return Token object
    */
    Token Get();

    /*
    * Returns the Token back to the stream.
    * @param token - which will return to the stream.
    */
    void Putback(Token token);

    /*
    * @param c - discard characters up to and including a c
    */
    void Ignore(char c = '\n');

  private:
    /* buffer busy indicator */
    bool mFull;

    /* the token is stored after returning with putback() */
    Token mBuffer;

    /* source of tokens */
    std::istream* mIStream;
  };
}

#endif //!__TOKENSTREAM_H__