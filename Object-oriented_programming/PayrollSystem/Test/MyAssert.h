#ifndef __MYASSERT_H__
#define __MYASSERT_H__

#if defined _VCRT_BUILD && !defined _ASSERT_OK
#error assert.h not for CRT internal use
#endif

#include <corecrt.h>
#include <cassert>

_CRT_BEGIN_C_HEADER
#undef assertEquals

#ifdef NDEBUG

#define assertEquals(TargetNumber, CheckedNumber, Accuracy) ((void)0)

#else

#define assertEquals(TargetNumber, CheckedNumber, Accuracy) assert( (TargetNumber) - (CheckedNumber) < (Accuracy) && (TargetNumber) - (CheckedNumber) > (-(Accuracy)) )

#endif
_CRT_END_C_HEADER

#endif // !__MYASSERT_H__