#include "main.h"
#include <unistd.h>
#include <string.h>
#include <unistd.h>
/**
 * op_char - function prints a character specifier
 * @c: string to be printed
 *
 * Return: void
 */
int op_char(int c)
{
	unsigned char a = c;

	return (write(1, &a, 1));
}

/**
 * op_str - function prints a string specifier
 * @c: string to be printed
 *
 * Return: void
 */
int op_str(char *c)
{
	unsigned int i = 0;

	while (*c != '\0')
	{
		write(1, c, 1);
		c++;
		i++;
	}
	return (i);
}
