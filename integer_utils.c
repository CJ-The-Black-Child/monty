#include "monty.h"
#include <ctype.h>

/**
 * is_integer - Checks if a string represents an integer
 * @str: The string to check.
 *
 * Return: 1 if @str represents an integer, 0 if otherwise.
 */

int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (0);
	}
	if (*str == '-')
	{
		str++;
	}

	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
