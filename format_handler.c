#include "main.h"
#include <unistd.h>
#include <string.h>
/**
 * habdles character prints
 * @c: character to be printed
 * Return: none
 */
void handle_char(char c)
{
	write(1, &c, 1);
}
/**
 * handles string for the _printf function
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
