/*
** mrbconf.h - mruby core configuration
**
** See Copyright Notice in mruby.h
*/

#ifndef MRUBYCONF_H
#define MRUBYCONF_H

#include <stdint.h>

/* configuration options: */
/* add -DMRB_USE_FLOAT to use float instead of double for floating point numbers */
//#define MRB_USE_FLOAT

/* initial size of khash table bucket; should be power of 2 (n >= 8) */
//#define MRB_INITIAL_HASH_SIZE 32

/* argv max size in mrb_funcall */
//#define MRB_FUNCALL_ARGC_MAX 16 

/* number of object per heap page */
//#define MRB_HEAP_PAGE_SIZE 1024

/* -DDISABLE_XXXX to drop the feature */
#define DISABLE_REGEXP	        /* regular expression classes */
//#define DISABLE_SPRINTF	/* Kernel.sprintf method */
//#define DISABLE_MATH		/* Math functions */
//#define DISABLE_TIME		/* Time class */
//#define DISABLE_STRUCT	/* Struct class */
//#define DISABLE_STDIO		/* use of stdio */

#undef  HAVE_UNISTD_H /* WINDOWS */
#define HAVE_UNISTD_H /* LINUX */

/* end of configuration */

#ifdef MRB_USE_FLOAT
typedef float mrb_float;
#else
typedef double mrb_float;
#endif
#define readfloat(p) (mrb_float)strtod((p),NULL)

typedef int mrb_int;
typedef intptr_t mrb_sym;

/* define ENABLE_XXXX from DISABLE_XXX */
#ifndef DISABLE_REGEXP
#define ENABLE_REGEXP
#endif
#ifndef DISABLE_SPRINTF
#define ENABLE_SPRINTF
#endif
#ifndef DISABLE_MATH
#define ENABLE_MATH
#endif
#ifndef DISABLE_TIME
#define ENABLE_TIME
#endif
#ifndef DISABLE_STRUCT
#define ENABLE_STRUCT
#endif
#ifndef DISABLE_STDIO
#define ENABLE_STDIO
#endif

#ifndef FALSE
# define FALSE 0
#endif

#ifndef TRUE
# define TRUE 1
#endif

#ifdef _MSC_VER
# define inline __inline
# define snprintf _snprintf
# define isnan _isnan
# define isinf(n) (!_finite(n) && !_isnan(n))
#endif

#endif  /* MRUBYCONF_H */
