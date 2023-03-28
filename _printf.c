#include <stdarg.h>
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
				format++;
			}
			else if (*format == 's')
			{
				reton += op_str(va_arg(arg, char *));
				format++;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				write(1, "%", 1);
				reton++;
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

