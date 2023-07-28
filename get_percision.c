#include "main.h"

/**
 * get_precision - Cal precision to be printed.
 * @format: Formatted string which print the args.
 * @i: List of args to print.
 * @list: list of args.
 *
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int currs_f = *i + 1;
	int precisions = -1;

	if (format[currs_f] != '.')
		return (precisions);

	precisions = 0;

	for (currs_f += 1; format[currs_f] != '\0'; currs_f++)
	{
		if (is_digit(format[currs_f]))
		{
			precisions *= 10;
			precisions += format[currs_f] - '0';
		}
		else if (format[currs_f] == '*')
		{
			currs_f++;
			precisions = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = currs_f - 1;

	return (precisions);
}

