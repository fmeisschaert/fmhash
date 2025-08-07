# fmhash
A fast hashing algorithm designed for utf8 strings

## build

You can just compile it using a C17 compatible C compiler:

    cc -std=c17 -O2 -Wall -Werror -c fmhash.c

Or use

    make

You can then link the fmhash.o object in your program. You can also create a
library, e.g. for Linux/macOS:

    cc -std=c17 -O2 -Wall -Werror -fPIC -shared -o libfmhash.so fmhash.c

## usage

Include the fmhash.h header file or use the source directly.

