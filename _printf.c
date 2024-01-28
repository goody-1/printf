#include "main.h"

/**
 *_printf - prints the user args
 * @format: the arg passed into _printf
 * Return: prints the inputed argument
*/
int _printf(const char *format, ...)
{
	/*variable initialisation*/
	int letter = 0;
	va_list args;

	va_start(args, format);

	/*identify the format and */
	/*match to appropriate funtion*/
	while (format[letter] != '\0')
	{
		if (format[letter] == "%")
		{
			letter++;

			/*this switchcase is meant to call functions*/
			/*that match to the format specifier*/
			switch (format[letter])
			{
			case 'c':
				/* code */
				break;
			case 'd':
				/* code*/
				break;

			default:
				break;
			}
		}
	}

va_end(args);
}
