#ifndef __CONFIG_H__
#define __CONFIG_H__

/* #undef __DECLSPEC__ */
/* #undef __EXPORTING__ */
#define __LIBSTRING__ WithoutLIB

// replaces argument s with string "s" 
#define TEXT(s) TEXT_(s)
#define TEXT_(s) #s

#endif // !__CONFIG_H__
