#include "main.h"
#include <unistd.h>
#include <string.h>
/**
 * itoa - function converts a number to a string
 * @num: number to be converted
 * @str: resulting string
 *
 * Return: void
 */
int op_int(int c)
{
	unsigned int i, j;
	char str[100];
	char *ptr;

	j = 0;
	ptr = itoa(c, str, 10);
	while (i < strlen(str))
	{
		write(1, &ptr[i], 1);
		i++;
		j++;
	}
	return (j);
}
