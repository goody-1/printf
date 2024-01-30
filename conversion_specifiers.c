#include "main.h"

/**
 * print_otal - converts an int to octal and prints it.
 * @arg: the int argument
 *
 * Return: length of string printed
 */
int print_otal(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	int length = 0, temp, index = 0;
	char *buffer;

	/* Count the number of characters printed */
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	temp = num;
	while (temp != 0)
	{
		temp /= 8;
		length++;
	}
	buffer = malloc(sizeof(int) * length);

	temp = num;
	while (temp != 0)
	{
		buffer[index++] = temp % 8 + '0';
		temp /= 8;
	}
	while (index > 0)
		_putchar(buffer[--index]);

	free(buffer);
	return (length);
}

/**
 * print_hex - converts an int to hex and prints it.
 * @arg: the int argument
 *
 * Return: length of string printed
 */
int print_hex(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	int length = 0, temp, hex_digit, index = 0;
	char *buffer;

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
	buffer = malloc(sizeof(int) * length);
	temp = num;
	while (temp != 0)
	{
		hex_digit = temp % 16;

		if (hex_digit < 10)
			buffer[index++] = hex_digit + '0';
		else
			buffer[index++] = hex_digit - 10 + 'a';
		temp /= 16;
	}

	while (index > 0)
		_putchar(buffer[--index]);
	free(buffer);

	return (length);
}
/**
 * print_hex_upper - converts an int to hex in uppercase and prints it.
 * @arg: the int argument
 *
 * Return: length of string printed
 */
int print_hex_upper(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	int length = 0, temp, hex_digit, index = 0;
	char *buffer;

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
	buffer = malloc(sizeof(int) * length);
	temp = num;
	while (temp != 0)
	{
		hex_digit = temp % 16;

		if (hex_digit < 10)
			buffer[index++] = hex_digit + '0';
		else
			buffer[index++] = hex_digit - 10 + 'A';
		temp /= 16;
	}

	while (index > 0)
		_putchar(buffer[--index]);
	free(buffer);

	return (length);
}
/**
 * print_pointer - prints pointer .
 * @arg: the int argument
 *
 * Return: length of string printed
 */
int print_pointer(va_list arg)
{
	void *ptr = va_arg(arg, void *);
	unsigned long address = (unsigned long)ptr;
	int length, i, digit, msb_index;
	char *hex_digits;

	/* Print the pointer address in hexadecimal */
	_putchar('0');
	_putchar('x');

	/* Determine the most significant non-zero digit */
	msb_index = sizeof(void *) * 2 - 1;
	while (((address >> (msb_index * 4)) & 0xF) == 0 && msb_index > 0)
        msb_index--;

	/* Print each hexadecimal digit individually */
	length = 2;  /* Length of "0x" */
	hex_digits = "0123456789abcdef";
	for (i = msb_index; i >= 0; i--)
	{
		digit = (address >> (i * 4)) & 0xF;
		_putchar(hex_digits[digit]);
		length++;
	}

	return (length);
}
