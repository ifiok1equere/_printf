#include "main.h"

/**
 * op_percent - function handles % specifier
 * @c: string to be printed
 *
 * Return: void
 */
void op_percent(void *c)
{
	_putchar(*((char *)c));
}

/**
 * op_int - function prints an integer
 * @c: integer to be printed
 *
 * Return: void
 */
void op_int(void *c)
{
	char str[20];
	int i = 0, num = *((int *)c);

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	while (num > 0)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	if (i == 0)
	{
		_putchar('0');
	}
	else
	{
		while (i > 0)
		{
			_putchar(str[--i]);
		}
	}
}
