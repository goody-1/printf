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
	int num_of_char = 0, i = 0, j;
	specifier_t specifiers[] = {
		{'c', print_char},
		{'s', print_string},
	};
	va_list args;

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
		j = 0;
		while (specifiers[j].ch)
		{
			if (format[i] == '%' && format[i + 1] == specifiers[j].ch)
			{
				specifiers[j].print_type(args);
				num_of_char++;
				i++;
			}
			else if (format[i] == '%' && format[i + 1] == '%')
			{
				_putchar('%');
				num_of_char++;
				i++;
			}
			j++;
		}
		i++;
	}
	va_end(args);

	return (num_of_char);
}
