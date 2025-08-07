fmhash.o: fmhash.c
	cc -std=c17 -O2 -Wall -Werror -c fmhash.c

libfmhash.so: fmhash.c
	cc -std=c17 -O2 -Wall -Werror -fPIC -shared -o libfmhash.so fmhash.c
