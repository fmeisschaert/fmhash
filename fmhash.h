#ifndef FMHASH_H
#define FMHASH_H

#include <stddef.h>
#include <stdint.h>

uint32_t fmhash(char *s, size_t len);

uint32_t fmhash_lc(char *s, size_t len);

#endif // FMHASH_H
