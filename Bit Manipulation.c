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

// convert n to characters in s 
#define abs(x) ((x) < 0 ? -(x) : (x))		// pay attention
void reverse(char s[], int n)
{
	int i, j;
	char temp;
	for (i = 0, j = n - 1; i < j; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
void itoa(int n , char s[])
{
	int sign = n;
	int i = 0;
	do {
		s[i++] = abs(n % 10) + '0';			// pay attention
		n /= 10;
	} while (n != 0);
	if (sign < 0)
		s[i++] = '-';
	reverse(s, i);
	s[i] = '\0';
}
// convert n to characters in s - base b
void itob(int n, char s[], int b)
{
	int sign = n;
	int i = 0;
	do {
		int digit = abs(n % b);
		if (digit < 9) 
			s[i++] = digit + '0';
		else 
			s[i++] = digit - 10 + 'a';
		n /= b;
	} while (n != 0);
	if (sign < 0)
		s[i++] = '-';
	reverse(s, i);
	s[i] = '\0';	
}
