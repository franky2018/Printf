#include "main.h"

/**
 * get_flags - Cal working flags.
 * @format: Formatted string which prints the args.
 * @i: parameter.
 * Return: flag.
 */

int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int b, currs_f;
	int flag = 0;
	const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARRS[] = {F_Minus, F_Plus, F_Zero, F_Hash, F_Space, 0};

	for (currs_f = *i + 1; format[currs_f] != '\0'; currs_f++)
	{
		for (b = 0; FLAG_CH[b] != '\0'; b++)
			if (format[currs_f] == FLAG_CH[b])
			{
				flag |= FLAG_ARRS[b];
				break;
			}

		if (FLAG_CH[b] == 0)
			break;
	}

	*i = currs_f - 1;

	return (flag);
}
