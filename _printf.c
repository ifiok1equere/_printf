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
=======
#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...){
  int count = 0, i;
  
  va_list data;
  va_start(data, format);

  /* _printf("%s", 'Hello') */
  
  for (i = 0; format[i] != '\0'; ){
    
    /* count the number of characters */
    /* print to the screen each character counted */
    if (format[i] != '%'){
      count += _putchar(format[i]);
      i++;
    }
    else if (format[i] == '%' && format[i+1] !=' '){
      switch (format[i + 1]){
        case 'c':
            /* print the character from the va_arguments */
            count += _putchar(va_arg(data, int));
            break;
        case 's':
            count += print_string(va_arg(data, char *));
            break;
        case '%':
            /* print the character from the va_arguments */
            count += _putchar('%');
            break;
        case 'd':
            count += print_decimal(va_arg(data, int));
            break;
        case 'i':
            count += print_decimal(va_arg(data, int));
            break;
        case 'b':
            count += print_binary(va_arg(data, int));
            break;
        case 'u':
            count += print_unsigned(va_arg(data, unsigned int));
            break;
        default:
            break;
      }
      
      i += 2;
    }
    
    
  }
  

  return (count);
>>>>>>> d41771cdaa1c153cb7e2ce8688062939b9364b0c
}
