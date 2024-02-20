#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h> // for fprintf
#include <errno.h> // for errno     
#include <string.h> // for strerror

#ifdef NDEBUG
#define debug(M, ...)  
#else
/* The ##__VA_ARGS__ syntax is a GCC extension that allows 
you to use variable arguments in macros. 
It's used here to pass any additional arguments to the fprintf function.
If no additional arguments are provided, the ## operator 
will remove the preceding comma(debug(M, ...): comm after M), 
preventing a syntax error. */
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n",\
                      __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))
//test
