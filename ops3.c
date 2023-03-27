#include "main.h"

/**
 * op_uint - convert to unsigned integer
 * @n: decimal number to be converted
 *
 * Return: unsigned integer
 */
void op_uint(unsigned int n)
{
	char c;

	if ((n / 10) != 0)
		op_uint(n / 10);

	c = n % 10 + '0';
	_putchar(c);
}


/**
 * op_oct - convert to octal number
 * @n: decimal number to be converted
 *
 * Return: octal number
 */
void op_oct(unsigned int n)
{
	char c;

	if (n == 0)
	{
		_putchar(0 + '0');
		return;
	}
	if (n / 8 != 0)
	{
		op_oct(n / 8);
	}
	c = (n % 8) + '0';
	_putchar(c);
}

/**
 * op_hex - convert to heximal number
 * @n: decimal number to be converted
 *
 * Return: hexadecimal number
 */
void op_hex(unsigned int n)
{
	char arr[100];
	int i = 0, j = 0, rem = 0;

	while (n != 0)
	{
		rem = n % 16;
		if (rem < 10)
		{
			arr[i] = rem + 48;
			i++;
		}
		else
		{
			arr[i] = rem + 55;
			i++;
		}
		n /= 16;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(arr[j]);
	}
}
