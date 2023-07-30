#include "main.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * handle_binary - prints binary
 * @num: number to be printed in binary
 * Return: None
 */
void handle_binary(unsigned int num)
{
	int size, i, *binary;
	binary = custom_binary(num, &size);

	for (i = 0; i < size; i++)
	{
		char digit = binary[i] + '0';

		write(1, &digit, 1);
	}
	free(binary);
}
