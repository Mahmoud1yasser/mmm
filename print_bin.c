#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
* print_bin - convert to binary
* @b: decimal number
* Return: number of chars printed(sucess)
*/
int print_bin(va_list b)
{
	unsigned int lenght, powten, j;
	unsigned int digit, n, number;
	int count = 0;

	n = va_arg(b, unsigned int);
	if (n != 0)
	{
		number = n;
		lenght = 0;
		while (number != 0)
		{
			number /= 2;
			lenght++;
		}
		powten = 1;
		for (j = 1; j <= lenght - 1; j++)
			powten *= 2;
		for (j = 1; j <= lenght; j++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
