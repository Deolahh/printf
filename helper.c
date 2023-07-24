#include "main.h"
/*&
 * print_string - ...
 * @str: ...
 * @width: ...
 * @pad_char: ...
 */
static void print_string(const char *str, int width, char pad_char)
{
	int str_len = strlen(str);
	int padding = (width > str_len) ? (width - str_len) : 0;
	
	if (padding > 0)
	{
		for (int i = 0; i < padding; i++)
		{
			_putchar_char(pad_char);
		}
	}
	_putchar_str(str);
}
/**
 * print_int_with_padding - ...
 * @num: ...
 * @width: ...
 * @pad_char: ...
 */
static void print_int_with_padding(int num, int width, char pad_char)
{
	char buffer[20];

	snprintf(buffer, sizeof(buffer), "%d", num);
	
	int num_len = strlen(buffer);
	int padding = (width > num_len) ? (width - num_len) : 0;

	if (padding > 0)
	{
		for (int i = 0; i < padding; i++)
		{
			_putchar_char(pad_char);
		}
	}
	_putchar_int(num);
}
