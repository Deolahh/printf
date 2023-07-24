#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Custom putchar function to write a single character to stdout.
 * @c: The character to be written.
 * Return: On success, 1 is returned. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _printf - produce outputs according to format
 * @format: type of the string
 * Return: number of characters printed (excluding the null byte)
 * Write output to standard output
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

	va_start(args, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				_putchar(va_arg(args, int)), count++, i++;
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char*);

				if (str)
				{
					while (*str)
					{
						_putchar(*str), count++, str++;
					}
				} i++;
			}
				else
				{
					_putchar(format[i]), count++;
				}
			}
			else
			{
				_putchar(format[i]), count++;
			} i++;
		}
	va_end(args);
	return (count);
}
