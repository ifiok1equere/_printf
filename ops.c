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
        	write(STDOUT_FILENO, "-", 1);
        	num = -num;
    	}
    	while (num > 0)
	{
        	str[i++] = num % 10 + '0';
        	num /= 10;
    	}
    	if (i == 0)
	{
        	write(STDOUT_FILENO, "0", 1);
    	}
	else
	{
        	while (i > 0)
		{
            		write(STDOUT_FILENO, &str[--i], 1);
        	}
    	}
}
