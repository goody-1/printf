#include "main.h"

/**
 * print_char - Prints a char.
 * @arg: A list of arguments pointing to
 *       the character to be printed.
 *
 * Return: 1 for length of char
 */
int print_char(va_list arg)
{
	char letter;

	letter = va_arg(arg, int);
	_putchar(letter);

	return (1);
}

/**
 * print_string - Prints a string.
 * @arg: A list of arguments pointing to
 *       the string to be printed.
 *
 * Return: length of argument
 */
int print_string(va_list arg)
{
	char *str, *null = "(null)";
	int i = 0, j = 0;

	str = va_arg(arg, char *);

	if (!str)
	{
		while (null[j] != '\0')
		{
			_putchar(null[j]);
			j++;
		}
		return (j);
	}

	if (str)
	{
		while (str[i] != '\0')
		{
			_putchar(str[i]);
			i++;
		}
	}
	/* What happens otherwise? */

	return (i);
}

/**
 * print_int - Prints an int.
 * @arg: A list of arguments pointing to
 *       the integer to be printed
 *
 * Return: length of argument
 */
int print_int(va_list arg)
{
	int num;

	num = va_arg(arg, int);
	print_number(num);

	return (get_int_length(num));
}
/**
 * print_binary - converts an int to binary and prints it.
 * @arg: A list of arguments
 *
 *
 * Return: length of string to be printed
 */
int print_binary(va_list arg)
{
	int num = va_arg(arg, int);
	int length = 0;
	unsigned int mask = 1 << (sizeof(int) * 8 - 1);

	/* Skip leading zeros */
	while ((mask & num) == 0 && mask != 0)
		mask >>= 1;

	/* Print the remaining binary digits */
	while (mask != 0)
	{
		_putchar((num & mask) ? '1' : '0');
		length++;
		mask >>= 1;
	}
	/* If the number was zero, print a single '0' */
	if (length == 0)
	{
		putchar('0');
		length = 1;
	}
	return (length);
}
/**
 * print_unsigned - prints unsigned integer.
 * @arg: the integer argument
 *
 * Return: length of string printed
 */

int print_unsigned(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int length = 0, index = 0, temp;
	char *buffer;

	/* Special case: print '0' for zero */
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	temp = num;
	/* Count the number of characters printed */
	while (temp != 0)
	{
		temp /= 16;
		length++;
	}

	buffer = malloc(sizeof(unsigned int) * length);
	temp = num;
	while (temp != 0)
	{
		buffer[index++] = temp % 10 + '0';
		temp /= 10;
	}

	while (index > 0)
		putchar(buffer[--index]);

	free(buffer);
	return (length);
}
