#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_con_spec - handles %d and %i conversion
 * @format: pointer to char d and i
 * Return: count
 */

int print_int(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				int num = va_arg(args, int);

				putchar(num + '0');
				count++;
				i++;
			}
			else if (format[i + 1] == 'r')
			{
				putchar('%');
				putchar('r');
				count += 2;
				i++;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
