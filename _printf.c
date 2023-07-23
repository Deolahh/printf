#include <stdarg.h>
#include <stdio.h>
#include "main.h"
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
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				putchar(va_arg(args, int)), count++, i++;
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char*);

				if (str)
				{
					while (*str)
					{
						putchar(*str), count++, str++;
					}
				} i++;
			}
				else
				{
					putchar(format[i]), count++;
				}
			}
			else
			{
				putchar(format[i]), count++;
			} i++;
		}
	va_end(args);
	return (count);
}
