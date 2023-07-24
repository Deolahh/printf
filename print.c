#include <unistd.h>
#include <string.h>
#include <stdio.h>
/**
 * _putchar_char - outputs char
 * @c: A char
 * perror: returns error
 */
void _putchar_char(char c)
{
	if (write(STDOUT_FILENO, &c, 1) == -1)
	{
		perror("_putchar_char");
	}
}
/**
 *_putchar_str - outputs strings
 *@str: A string
 *perror: returns error
 */
void _putchar_str(const char *str)
{
	size_t len = strlen(str);

	if (write(STDOUT_FILENO, str, len) == -1)
	{
		perror("_putchar_str");
	}
}
/**
 * _putchar_int - outputs integer
 * @num: the integer
 * perror - returns error
 */
void _putchar_int(int num)
{
	char buffer[20];
	int len = snprintf(buffer, sizeof(buffer), "%d", num);

	if (write(STDOUT_FILENO, buffer, len) == -1)
	{
		perror("_putchar_int");
	}
}
