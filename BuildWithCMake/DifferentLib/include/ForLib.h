#ifndef __FORLIB_H__
#define __FORLIB_H__

#ifndef __DECLSPEC__
# if defined(_WIN32) || defined(_WIN64)
#  ifdef __EXPORTING__
#   define __DECLSPEC__ __declspec(dllexport)
#  else
#   define __DECLSPEC__ __declspec(dllimport)
#  endif // __EXPORTING__
# endif // defined(_WIN32) || defined(_WIN64)
#endif // DECLSPEC

#endif // !__FORLIB_H__