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
void op_char(void *c)
{
	_putchar(*((char *)c));
}

/**
 * op_str - function prints a string specifier
 * @c: string to be printed
 *
 * Return: void
 */

void op_str(void *c)
{
	unsigned int i, len;

	len = strlen(c);
	while (i < len)
	{
		_putchar(*(((char *)c) + i));
		i++;
	}
}
