#include "main.h"

/**
 *_printf - prints the input string
 * @format: the string argument passed into _printf
 *
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	/*variable initialisation*/
	int num_of_char = 0, i = 0;
	specifier_t specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i',  print_int},
		{'b',  print_binary},
		{'u',  print_unsigned},
		{'o',  print_otal},
		{'x',  print_hex},
		{'X',  print_hex_upper},
		{'p',  print_pointer},
	};
	va_list args;

	if (!format)
		return (0);

	va_start(args, format);

	/*identify the format and */
	/*match to appropriate funtion*/
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			num_of_char++;
		}
		else
		{
			if (!format[i + 1] || format[i + 1] == ' ')
				return (-1);
			num_of_char += process_specifiers(format, args, &i, specifiers);
		}
		i++;
	}
	va_end(args);

	return (num_of_char);
}
/**
 * process_specifiers - processes specifier with argument
 * @format: the string argument passed into _printf
 * @specifiers: an array of the specifier_t type
 * @i: pointer address of counter i from printf
 * @args: the variadic arg
 *
 * Return: number of characters
*/
int process_specifiers(const char *format, va_list args, int *i,
	specifier_t specifiers[])
{
	int num_of_char = 0;
	int j = 0, len;

	while (specifiers[j].ch)
	{
		if (format[*i] == '%' && format[*i + 1] == specifiers[j].ch)
		{
			len = specifiers[j].print_type(args);
			num_of_char += len;
			(*i)++;
			break;
		}
		else if (format[*i] == '%' && format[*i + 1] == '%')
		{
			_putchar('%');
			num_of_char++;
			(*i)++;
			break;
		}
		j++;
	}
	return (num_of_char);
}
