#include <stddef.h>
#include <stdint.h>

#ifndef __STDC_VERSION__
#error "at least c17 required"
#elif __STDC_VERSION__ < 201710L
#error "at least c17 required"
#endif

static inline
uint32_t rotr32(uint32_t x,uint32_t r) {
    return (x >> r) | (x << (32 - r));
}

// random numbers with no more than 3 consecutive equal bits, even if rotated
//                           3 2         1         0
//                           10987654321098765432109876543210
static const uint32_t n1 = 0b00101101100010010001001101011101;
static const uint32_t n2 = 0b01000100100101110101100100010011;
static const uint32_t n3 = 0b10111011010111011101011001001010;

// designed for utf8 strings with mostly basic latin (ascii) characters

uint32_t fmhash(char *s, size_t len) {
    uint32_t hash = 0;

    for (size_t i = 0; i < len; i++) {
        uint32_t c = (uint32_t) s[i];
        uint32_t p7 = (uint32_t) i * 7;

        // distribute the character bits "randomly" over the 32 bits
        // add them to the hash
        hash += c * n1 + n2;

        // rotate the hash by a stateful, the position of the character, multiple
        // of 7 bits, inspired by the 7 bits of basic latin (ascii)
        hash = rotr32(hash,p7 & 0x1f);

        // invert the hash bits by a "randomly", the character, rotated constant 
        hash ^= rotr32(n3,c & 0x1f);
    }

    return hash;
}

uint32_t fmhash_lc(char *s, size_t len) {
    uint32_t hash = 0;

    for (size_t i = 0; i < len; i++) {
        uint32_t c = (uint32_t) s[i];
        if (c >= 0x41 && c <= 0x5a) c |= 0x20;  // convert ASCII A-Z to a-z
        uint32_t p7 = (uint32_t) i * 7;

        // distribute the character bits "randomly" over the 32 bits
        // add them to the hash
        hash += c * n1 + n2;

        // rotate the hash by a stateful, the position of the character, multiple
        // of 7 bits, inspired by the 7 bits of basic latin (ascii)
        hash = rotr32(hash,p7 & 0x1f);

        // invert the hash bits by a "randomly", the character, rotated constant 
        hash ^= rotr32(n3,c & 0x1f);
    }

    return hash;
}

