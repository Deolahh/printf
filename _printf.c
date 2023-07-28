#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: character string, composed of zero or;more directives
 * Return: no of char printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					handle_char(va_arg(args, int));
					count++;
					break;
				case 's':
					handle_string(va_arg(args, char*));
					count++;
					break;
				case 'd':
				case 'i':
					handle_int(va_arg(args, int));
					count++;
					break;
				case 'b':
					handle_binary(va_arg(args, unsigned int));
					count++;
					break;
				default:
					write(1, format, 1);
					count++;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
