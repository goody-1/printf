#ifndef MAIN_H
#define MAIN_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>


/**
 * struct specifier - for correct mapping of specifiers to arguments
 *
 * @ch: format specifier
 * @print_type: The function for specifier, i.e int, char etc
 */
typedef struct specifier
{
	char ch;
	int (*print_type)(va_list arg);
} specifier_t;

/* Project functions' prototypes */
int _putchar(char c);
int print_char(va_list arg);
int print_string(va_list arg);
int print_int(va_list arg);
int print_binary(va_list args);
int print_otal(va_list arg);
int print_hex(va_list arg);
int print_hex_upper(va_list arg);
int print_unsigned(va_list arg);
int print_pointer(va_list arg);

/* Project's entry*/
int _printf(const char *format, ...);

/* Helper functions */
unsigned int str_len(char *str);
void print_number(int n);
int get_int_length(int num);
int process_specifiers(const char *format, va_list args, int *i,
	specifier_t specifiers[]);
int check_valid_identifier(const char *format, int *counter, int *num_of_char,
	specifier_t *specifiers, int specifier_size);
char *_strcpy(char *dest, char *src);

#endif /* MAIN_H */
