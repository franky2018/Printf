#include "main.h"

/**
 * get_size - Cal the size to cast the arg.
 * @format: Formatted string which to be printed in the arg.
 * @i: List of args to be printed.
 *
 * Return: Precisions.
 */
int get_size(const char *format, int *i)
{
	int currs_f = *i + 1;
	int size = 0;

	if (format[currs_f] == 'l')
		size = S_Long;
	else if (format[currs_f] == 'h')
		size = S_Short;

	if (size == 0)
		*i = currs_f - 1;
	else
		*i = currs_f;

	return (size);
}

