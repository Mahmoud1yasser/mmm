#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
* print_bin - convert to binary
*
* @b: decimal number
*
* Return: number of chars printed(sucess)
*/

int print_bin(va_list b)
{
	unsigned int len, pten, j;
	unsigned int digit, n, number;
	int count = 0;

	n = va_arg(b, unsigned int);
	if (n != 0)
	{
		number = n;
		len = 0;
		while (number != 0)
		{
			number /= 2;
			len++;
		}
		pten = 1;
		for (j = 1; j <= len - 1; j++)
			pten *= 2;
		for (j = 1; j <= len; j++)
		{
			digit = n / pten;
			_putchar(digit + '0');
			count++;
			n -= digit * pten;
			pten /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
