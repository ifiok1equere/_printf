#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
/**
 * _printf - function prints
 * @format: pointer to string to be printed.
 * Return: integer
 */
int _printf(const char *format, ...)
{
	unsigned int i, reton = 0;
	va_list arg;

	if (format == NULL)
		return (0);
	va_start(arg, format);
	for (i = 0; i < strlen(format); i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				reton += op_char(va_arg(arg, int));
			}
			else if (format[i + 1] == 's')
			{
				reton += op_str(va_arg(arg, char *));
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				reton++;
			}
			i += 2;
		}
		if (format[i] != '%')
		{
			_putchar(format[i]);
			reton++;
		}
		else
			i--;
	}
	return (reton);
}
