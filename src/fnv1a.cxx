#include "fnv1a.hxx"

#define FNV_INIT ((uint64_t)0xcbf29ce484222325ULL)
#define FNV_PRIME ((uint64_t)0x100000001b3ULL)

inline uint64_t fnv_pass(uint64_t hval, char octet)
{
    /* xor the bottom with the current octet */
    hval ^= (uint64_t)octet;
    /* multiply by FNV_PRIME */
    hval *= FNV_PRIME;

    return hval;
}

/*
 * perform a 64 bit Fowler/Noll/Vo FNV-1a
 */
uint64_t fnv1a(const char *str)
{
    uint64_t hval = FNV_INIT;

    /*
	 * FNV-1a hash each octet of the string
	 */
    while (*str)
    {
        hval = fnv_pass(hval, *str++);
    }

    return hval;
}

/*
 * perform a 64 bit Fowler/Noll/Vo FNV-1a 
 */
uint64_t fnv1a(const char *str, char base)
{
    uint64_t hval = FNV_INIT;

    hval = fnv_pass(hval, base);
    /*
	 * FNV-1a hash each octet of the string
	 */
    while (*str)
    {
        hval = fnv_pass(hval, *str++);
    }

    return hval;
}