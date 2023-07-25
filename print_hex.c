#include "main.h"
/**
* print_hex - prints unsigned int in hexadecimal
* @n: unsigned number to be printed
* @c: case of printing (0 = lower, 1 = upper)
* Descriptions: prints unsigned in hexadecimal with _putchar
* Return: size the output
*/
int print_hex(unsigned int n, unsigned int c)
{
	unsigned int lenght, powten;
	unsigned int j, digit, number;
	int count = 0;
	char diff;

	if (n != 0)
	{
		number = n;
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
			digit = n / powten;
			if (digit < 10)
				_putchar(digit + '0');
			else
				_putchar(digit + '0' + diff);
			count++;
			n -= digit * powten;
			powten /= 16;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
/**
* print_x - prints HEX in lowercase hex
* @x: unsigned number to print
* Descriptions: prints in lowercase hex with _putchar
* Return: size of the output
*/
int print_x(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}
/**
* print_X - prints HEX in uppercase
* @X: unsigned number to print
* Descriptions: prints in uppercase hex with _putchar
* Return: size of the output
*/
int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}
