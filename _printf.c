#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * _printf - function prints
 * @format: pointer to string to be printed.
 * Return: integer
 */
int _printf(const char *format, ...)
{
	unsigned int reton = 0;
	va_list arg;

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				reton += op_char(va_arg(arg, int));
			}
			else if (*format == 's')
			{
				reton += op_str(va_arg(arg, char *));
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				reton++;
			}
			if (*format == 'c' || *format == 's' || *format == '%')
				format++;
			else
				format--;
		}
		write(1, format, 1);
		reton++;
		format++;
	}
	va_end(arg);
	return (reton);
}
