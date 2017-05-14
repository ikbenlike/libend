# libend

libend provides macros that let you write C with a different syntax (not recommend for use in production)


# How to use it:

To use libend you either put it in your system's C library path, or you put it in your project folder. Then you just
`#include <end.h>` or `#include "end.h"`


# Macros

All "functionality" provided by libend is provided in the form of macros

* START `START` opens a new scope, it's the same as `{`
* THEN `THEN` also opens a new scope, but it should be used after control flow mechanisms such as if-statements, it's the same as `{`
* END `END` closes a scope, the same as `}`
