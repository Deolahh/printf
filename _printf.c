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
			i++;
			switch (format[i])
			{
				case 'c':
					{
						char c = va_arg(args, int);
						write(1, &c, 1), count++, break;
					}
				case 's':
					{
						char *str = va_arg(args, char*);
						int len = 0;
				
						while (str[len])
							len++, write(1, str, len), count += len, break;
					}
				case '%':
					{
						write(1, "%", 1), count++, break;
					}
				default:
					break;
			}
		}
		else
		{
			write(1, &format[i], 1), count++;
		} i++;
	}
	va_end(args);
	return count;
}
