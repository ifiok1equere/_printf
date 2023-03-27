#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - function prints
 * @format: pointer to string to be printed.
 *
 * Return: integer
 */
int _printf(const char *format, ...)
{
	unsigned int len, i, u;
	void *c;
	const char *ptr;
	char *str;
	void (*op)(void *);
	va_list arg;
	ops_p ops[] = {{'c', op_char},{'s', op_str},
		{'%', op_percent},{'d', op_int}};

	if (format == NULL)
		exit(-1);

	ptr = format;
	len = strlen(ptr);
	va_start(arg, format);
	for (i = 0; i < len; i++)
	{
		if (ptr[i] == '%')
		{
			if (ptr[i + 1] == ops[0].a)
			{
				c = va_arg(arg, void *);
				op = ops[0].f;
				op(&c);
			}
			else if (ptr[i + 1] == ops[1].a)
			{
				str = va_arg(arg, void *);
				op = ops[1].f;
				op((void *)str);
			}
			else if (ptr[i + 1] == ops[2].a)
			{
				op = ops[2].f;
				op("%");
			}
			else if (ptr[i + 1] == ops[3].a)
			{
				c = va_arg(arg, void *);
				op = ops[0].f;
				op(&c);
			}
			else if (ptr[i + 1] == 'b')
			{
				u = va_arg(arg, unsigned int);
				op_bin(u);
			}
			else if (ptr[i + 1] == 'u')
			{
				u = va_arg(arg, unsigned int);
				op_uint(u);
			}
			else if (ptr[i + 1] == 'o')
			{
				u = va_arg(arg, unsigned int);
				op_oct(u);
			}
			i += 2;
		}
		if (ptr[i] != '%')
		{
			_putchar(ptr[i]);
		}
		else
		{
			i--;
		}
	}
	return (0);
}