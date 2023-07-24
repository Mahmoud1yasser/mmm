#include "holberton.h"
#include <stdio.h>

/**
  * print_rot13 - encodes a string into rot13.
  *
  * @R: string to convert
  *
  * Return: size the output text
*/

int print_rot13(va_list R)
{
	int j, i, count = 0;
	char *r;

	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	r = va_arg(R, char *);
	if (r == NULL)
		r = "(NULL)";
	for (j = 0; r[j] != '\0'; j++)
	{
		char c = r[j];

		if (c >= 'A' && c <= 'Z')
		{
			i = c - 'A';
			_putchar(output[i]);
			count++;
		}
		else if (c >= 'a' && c <= 'z')
		{
			i = c - 'a' + 26;
			_putchar(output[i]);
			count++;
		}
		else if (c == ' ')
		{
			_putchar(' ');
			count++;
		}
		else
		{
			_putchar(c);
			count++;
		}
	}
	return (count);
}
