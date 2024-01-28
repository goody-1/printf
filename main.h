#ifndef MAIN_H
#define MAIN_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

/* Project functions' prototypes */
int _putchar(char c);
void print_char(va_list arg);
void print_string(va_list arg);

/* Project's entry*/
int _printf(const char *format, ...);

/* Helper functions */
unsigned int str_len(char *str);

#endif /* MAIN_H */
