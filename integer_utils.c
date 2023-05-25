#include "monty.h"
#include <ctype.h>

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
