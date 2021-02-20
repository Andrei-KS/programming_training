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

    /*_ACRTIMP void __cdecl _wassert5(
        _In_z_ wchar_t const* _Message1,
        _In_z_ wchar_t const* _Message2,
        _In_z_ wchar_t const* _Message3,
        _In_z_ wchar_t const* _File,
        _In_   unsigned       _Line
        );*/

#define assertEquals(TargetNumber, CheckedNumber, Accuracy) (void)(                                                       \
            (!!((TargetNumber)-(CheckedNumber)<(Accuracy) && (TargetNumber)-(CheckedNumber)>(-(Accuracy)))) ||                                                              \
            (_wassert(_CRT_WIDE(#TargetNumber), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0) \
        )

#endif
_CRT_END_C_HEADER

#endif // !__MYASSERT_H__