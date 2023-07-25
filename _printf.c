#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - produces output according to a format
 * @format: The format string containing the text and format specifiers
 * Return: number of characters printed (excluding null byte)
 * Team project done by Habeeb and Adeola
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list lists;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lists, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, lists);
			precision = get_precision(format, &i, lists);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, lists, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(lists);

	return (printed_chars);
}

/**
 * print_buffer - output the content of the buffer
 * @buffer: Array of chars in the buffer
 * @buff_ind: buffer index
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
