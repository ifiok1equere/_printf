#include "main.h"
#include <unistd.h>
#include <string.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * op_char - function prints a character specifier
 * @c: string to be printed
 *
 * Return: void
 */
int op_char(int c)
{
	_putchar(c);
	return (1);
}

/**
 * op_str - function prints a string specifier
 * @c: string to be printed
 *
 * Return: void
 */

int op_str(char *c)
{
	unsigned int i = 0, len;

	len = strlen(c);
	while (i < len)
	{
		_putchar(c[i]);
		i++;
	}
	return (i + 1);
}
