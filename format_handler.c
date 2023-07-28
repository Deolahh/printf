#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
/**
 * handle_char - handles character prints
 * @c: character to be printed
 * Return: none
 */
void handle_char(char c)
{
	write(1, &c, 1);
}
/**
 * handle_string - handles string for the _printf function
 * @s: pointer to the string
 * Return: None
 */
void handle_string(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		write(1, &s[i], 1);
	}
}
/**
 * handle_int - handles %d and %i format specifier
 * @num: integer value to be printed
 * return: none
 */
void handle_int(int num)
{
	char buffer[12];
	int length;

	length = snprintf(buffer, sizeof(buffer), "%d", num);
	if (length < 0)
	{
		return;
	}
	write(1, buffer, length);
}
