#include "main.h"

/**
 *_print - prints the user args
 * @format: the arg passed into _printf
*/
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int argsList = va_arg(args, const char);
}