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
/* errno global variable, which is set by many functions in the C 
and C++ standard libraries when they encounter errors. */
#define clean_errno() (errno == 0 ? "None" : strerror(errno))

/* log_err, log_warn, log_info, and check macros are used to log messages
to the user. They're similar to debug, but are always compiled in. */
#define log_err(M, ...) fprintf(stderr,\
    "[ERROR] (%s:%d: errno: %s)" M "\n", __FILE__, __LINE__,\
    clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr,\
    "[WARN] (%s:%d: errno: %s)" M "\n", __FILE__, __LINE__,\
    clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr,\
    "[INFO] (%s:%d)" M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

/* check macro is used to make sure a condition is true, and if not,
it logs the error and jumps to the error: label. */
#define check(A, M, ...) if (!(A)) {\
    log_err(M, ##__VA_ARGS__); errno=0; goto error;}

/* sentinel macro is used to make sure a function always
returns an error, and if not, it logs it and jumps to the error: label. */
#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__);\
    errno=0; goto error;}

/* check_mem macro is used to make sure a pointer is valid, and if not,
it logs the error and jumps to the error: label. */
#define check_mem(A) check((A), "Out of memory.")

/* check_debug macro is used to make sure a condition is true, and if not,
it logs the error and jumps to the error: label. */
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__);\
    errno=0; goto error;}

#endif

