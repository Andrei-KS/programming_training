#ifndef __CONFIG_H__
#define __CONFIG_H__

#cmakedefine __DECLSPEC__
#cmakedefine __EXPORTING__
#cmakedefine __LIBSTRING__ ${__LIBSTRING__}

// replaces argument s with string "s" 
#define TEXT(s) TEXT_(s)
#define TEXT_(s) #s

#endif // !__CONFIG_H__