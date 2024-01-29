#include "main.h"

/**
 * str_len - get length of string argument
 *
 * @str: string whose length is needed
 * Return: 0
*/
unsigned int str_len(char *str)
{
	unsigned int i = 0;

	if (!str)
		return (0);


	while (str[i] != '\0')
		i++;

	return (i);
}
/**
* print_number - prints an integer
* @n: integer to be printed
* Return: no return (return is void)
*/
void print_number(int n)
{
	unsigned int c;

	c = n;

	if (n < 0)
	{
		_putchar('-');
		c = -n;
	}

	if (c / 10)
		print_number(c / 10);

	_putchar((c % 10) + '0');
}

/**
* get_int_length - get length of an integer
* @nun: integer in question
* Return: length of integer
*/
int get_int_length(int num)
{
	int length = 0;

	if (num == 0) {
		return 1;
	}

	if (num < 0) {
		num = -num;
	}

	while (num != 0) {
		num /= 10;
		length++;
	}

	return length;
}
