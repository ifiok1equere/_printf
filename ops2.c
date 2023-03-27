#include "main.h"

/**
 * op_bin - convert decimal to binary
 * @c: decimal number to be converted.
 *
 * Return: void
 */
void op_bin(unsigned int n)
{
	char c;

	if (n > 1)
		op_bin(n / 2);

	c = (n % 2) + '0';

	_putchar(c);
}
