#include "main.h"

/**
 * print_char - Prints a char.
 * @arg: A list of arguments pointing to
 *       the character to be printed.
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
 */
int print_string(va_list arg)
{
	char *str;
	int i = 0;

	str = va_arg(arg, char *);

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
 *       the integer to be printed.
 */
int print_int(va_list arg)
{
	int num;

	num = va_arg(arg, int);
	print_number(num);

	return (get_int_length(num));
}
