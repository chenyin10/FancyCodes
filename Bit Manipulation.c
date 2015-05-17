#include <stdio.h>

/**
 * return n bit from x form position p
 * assume that most right pos is  0 
 */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p - n + 1)) & ~(~0 << n);
}

/**
 * set n bits in x from position p 
 * to n bits from y from most right
 */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return  x & ~(~(~0 << n) << (p - n + 1)) |
		(y & ~(~0 << n)) << (p - n + 1);
}

// calculate word length of the machine
int wordlength(void)
{
	int i;
	unsigned v = (unsigned)~0;
	for (i = 1; (v = v >> 1) > 0; i++);
	return i;
}

/**
 * rotate x to the right by n positions
 */
unsigned rightrot(unsigned x, int n)
{
	int rbit;			// right most bit
	int wordLength = wordlength();

	while (n-- > 0) {
		rbit = (x & 1) << (wordLength - 1);
		x = x >> 1;
		x |= rbit;
	}
	return x;
}

/**
 * count all bits which are 1
 * faster than ordinary method
 * the core is (x & x - 1) makes first bit
 * which is 1 becomes 0 
 */
 int bitcount(unsigned x)
 {
 	int b;
 	for (b = 0; x != 0; x &= (x - 1))
 		b++;
 	return b;
 }