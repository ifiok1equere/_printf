#include "main.h"

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
			if (format[i + 1] == 's')
			{
				reton += op_str(va_arg(arg, char *));
			}
			if (format[i + 1] == '%')
			{
				write(1, "%", 1);
				reton++;
			}
			i += 2;
		}
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			reton++;
		}
		else
			i--;
	}
	return (reton - 1);
}
