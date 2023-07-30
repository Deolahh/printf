#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
/**
 * custom_binary - converts int to binary
 * @num: number to be converted
 * @size: size of the array
 * Return: binary of the number
 */
int *custom_binary(unsigned int num, int *size)
{
	int i, j, temp, bits;
	int *bin;

	bits = sizeof(int) * CHAR_BIT;
	bin = (int *)malloc(bits * sizeof(int));


	if (bin == NULL)
	{
		*size = 0;
		return (NULL);
	}
	i = 0;
	if (num == 0)
	{
		bin[i++] = 0;
	}
	else
	{

		while (num > 0)
		{
			bin[i++] = num % 2;
			num /= 2;
		}
	}
	*size = i;
	for (j = 0; j < *size / 2; j++)
	{
		temp = bin[j];

		bin[j] = bin[*size - j - 1];
		bin[*size - j - 1] = temp;
	}
	return (bin);
}
