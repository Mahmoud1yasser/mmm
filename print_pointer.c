#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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
 * print_hexi - prints unsigned int in hexadecimal
 * @ptr: pointer to unsigned number to be printed
 * @c: case of printing (0 = lower, 1 = upper)
 *
 * Description: prints unsigned in hexadecimal with printf
 * Return: size of the output
 */
int print_hexi(void *ptr, unsigned int c)
{
	uintptr_t number = (uintptr_t)ptr;
	unsigned int length = 0, powten;
	unsigned int j, digit;
	char diff;

	int count = 0;

	if (ptr != NULL)
	{
		if (c)
			diff = 'A' - ':';
		else
			diff = 'a' - ':';
		while (number != 0)
		{
			number /= 16;
			length++;
		}
		powten = 1;
		for (j = 1; j <= length - 1; j++)
			powten *= 16;
		for (j = 1; j <= length; j++)
		{
			digit = (unsigned int)(number / powten);
			if (digit < 10)
				printf("%c", digit + '0');
			else
				printf("%c", digit + '0' + diff);
			count++;
			number -= digit * powten;
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
	return (print_hexi(va_arg(x, void *), 0));
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
	return (print_hexi(va_arg(X, void *), 1));
}
