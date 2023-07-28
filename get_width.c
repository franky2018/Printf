#include "main.h"

/**
 * get_width - Cal the width for printing.
 * @format: Formatted string which prints the args.
 * @i: List of args to be printed.
 * @list: list of args.
 *
 * Return: width.
 */

int get_width(const char *format, int *i, va_list list)
{
	int currs_f;
	int width = 0;

	for (currs_f = *i + 1; format[currs_f] != '\0'; currs_f++)
	{
		if (is_digit(format[currs_f]))
		{
			width *= 10;
			width += format[currs_f] - '0';
		}
		else if (format[currs_f] == '*')
		{
			currs_f++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = currs_f - 1;

	return (width);
}

