#include "holberton.h"
#include <stdio.h>
/**
  * print_rot13 - encodes a string into rot13.
  * @R: string to convert
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
// Uppercase letter, use the input array
            i = c - 'A';
            _putchar(output[i]);
            count++;
        }
        else if (c >= 'a' && c <= 'z')
        {
            // Lowercase letter, use the input array with offset
            i = c - 'a' + 26;
            _putchar(output[i]);
            count++;
        }
        else
        {
            // Not a letter, print as is
            _putchar(c);
            count++;
        }
    }
    return count;
}
