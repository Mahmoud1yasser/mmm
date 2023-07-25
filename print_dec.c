#include "main.h"
/**
* print_dec - prints decimaml numbers
* @d: number to be printed
* Descriptions: prints digit with _putchar
* Return: size the output text
*/
int print_dec(va_list d)
{
	int lenght, powten, j, digit, n, count = 0, number;

	n = va_arg(d, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
		}
		number = n;
		lenght = 0;
		while (number != 0)
		{
			number /= 10;
			lenght++;
		}
		powten = 1;
		for (j = 1; j <= lenght - 1; j++)
			powten *= 10;
		for (j = 1; j <= lenght; j++)
		{
			digit = n / powten;
			if (n < 0)
				_putchar((digit * -1) + 48);
			else
				_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
