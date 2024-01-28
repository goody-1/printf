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
