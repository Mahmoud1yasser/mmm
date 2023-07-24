#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_pointer - prints a pointer address in hexadecimal format
 * @arg: the pointer to print
 *
 * Return: the number of characters printed
 */
int print_pointer(va_list arg)
{
	void *ptr = va_arg(arg, void *);

	if (ptr == NULL)
		return (printf("(nil)"));

	return (printf("%p", ptr));
}

/**
 * print_hex_x - prints unsigned int in hexadecimal
 * @ptr: pointer to unsigned number to be printed
 * @c: case of printing (0 = lower, 1 = upper)
 *
 * Description: prints unsigned in hexadecimal with printf
 * Return: size of the output
 */
int print_hex_x(void *ptr, unsigned int c)
{
	unsigned int lenght, powten;
	unsigned int j, digit, number;
	char diff;
	int count = 0;

	if (ptr != NULL)
	{
		number = (unsigned int)ptr;
		lenght = 0;
		if (c)
			diff = 'A' - ':';
		else
			diff = 'a' - ':';
		while (number != 0)
			{
				number /= 16;
				lenght++;
			}
		powten = 1;
		for (j = 1; j <= lenght - 1; j++)
			powten *= 16;
		for (j = 1; j <= lenght; j++)
		{
			digit = (unsigned int)ptr / powten;
			if (digit < 10)
				printf("%c", digit + '0');
			else
				printf("%c", digit + '0' + diff);
			count++;
			ptr -= digit * powten;
			powten /= 16;
		}
	}
	else
	{
		printf("(nil)");
		return (5);
	}
	return (count);
}

/**
 * print_x - prints HEX in lowercase hex
 * @x: pointer to unsigned number to be printed
 *
 * Description: prints in lowercase hex with printf
 * Return: size of the output
 */
int print_x(va_list x)
{
	return (print_hex_x(va_arg(x, void *), 0));
}

/**
 * print_X - prints HEX in uppercase
 * @X: pointer to unsigned number to be printed
 *
 * Description: prints in uppercase hex with printf
 * Return: size of the output
 */
int print_X(va_list X)
{
	return (print_hex_x(va_arg(X, void *), 1));
}
