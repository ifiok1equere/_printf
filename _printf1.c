#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
/**
 * _print1f - function prints
 * @format: pointer to string to be printed.
 *
 * Return: integer
 */
int _printf1(const char *format, ...)
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
			if (*format == 'd' || *format == 'i')
			{
				reton += op_int(va_arg(arg, int));
				format++;
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				reton += 2;
				format++;
			}
		}
		else
		{
			write(1, format, 1);
			format++;
			reton++;
		}
	}
	va_end(arg);
	return (reton);
}
