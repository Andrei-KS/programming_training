/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate                                   : 04/24/2023 08:11:55
	author                                          : Andrei-KS
*/

#include "CH18P664EXERC2RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH18P664EXERC2RunExmple();

namespace {
  constexpr long long BIG_PRIME_NUMBER = 100000007;
  constexpr long long ALPHABET_MULTIPLIER = 263;

  size_t getLength(const char* str)
  {
    size_t ret = 0;
    while (str[ret] != '\0')
    {
      ++ret;
    }
    return ret;
  }

  char* searchRabinKarp(const char* pattern, const char* text)
  {
    // We use Polynomial hash
    // H(s) = s_0*x^0 + s_1*x^1 +...+ s_n*x^n
    // and its properties
    // H(s + 'a') = H(s)*x + H('a')
    // H('a' + s) = H('a')*x^(n+1) + H(s)
    // Idei is next:
    // we have
    // ............... - text
    // *** - pattern
    // and every step we push pattern window across text:
    // ***............
    // .***...........
    //      {...}
    // ............***
    // and check the hash of the string

    const size_t patternSize = getLength(pattern);
    const size_t textSize = getLength(text);

    if (patternSize > textSize)
    {
      return nullptr;
    }

    long long hashPattern = 0;
    for (size_t index = 0; index < patternSize; ++index)
    {
      hashPattern *= ALPHABET_MULTIPLIER;
      hashPattern %= BIG_PRIME_NUMBER;
      hashPattern += pattern[index];
      hashPattern %= BIG_PRIME_NUMBER;
    }

    long long hashText = 0;
    for (size_t index = 0; index < patternSize; ++index)
    {
      hashText *= ALPHABET_MULTIPLIER;
      hashText %= BIG_PRIME_NUMBER;
      hashText += text[index];
      hashText %= BIG_PRIME_NUMBER;
    }

    long long maxOrderMultiplier = 1;
    for (size_t index = 0; index < patternSize - 1; ++index)
    {
      maxOrderMultiplier *= ALPHABET_MULTIPLIER;
      maxOrderMultiplier %= BIG_PRIME_NUMBER;
    }

    for (size_t index = patternSize; index < textSize; ++index)
    {
      if (hashPattern == hashText)
      {
        bool isFind = true;
        const int shift = index - patternSize;
        for (size_t patternIndex = 0; patternIndex < patternSize; ++patternIndex)
        {
          if (text[shift + patternIndex] != pattern[patternIndex])
          {
            isFind = false;
            break;
          }
        }
        if (isFind)
        {
          return const_cast<char*>(text+shift);
        }
      }
      hashText -= (text[index - patternSize] * maxOrderMultiplier) % BIG_PRIME_NUMBER;
      if (hashText < 0) hashText += BIG_PRIME_NUMBER;
      hashText *= ALPHABET_MULTIPLIER;
      hashText %= BIG_PRIME_NUMBER;
      hashText += text[index];
      hashText %= BIG_PRIME_NUMBER;
    }

    return nullptr;
  }

  char* Myfindx(const char* s, const char* x)
  {
    return searchRabinKarp(x, s);
  }
}

int CH18P664EXERC2RunExmple::excute()
{
  cout << searchRabinKarp("test", "testaaa") << "\n";
  cout << searchRabinKarp("test", "btesktaatetestestgha") << "\n";
	return 0;
}