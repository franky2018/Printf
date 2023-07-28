#include "main.h"

/**
 * handle_print - Print an arg based on it's type.
 * @fmt: Formatted string which print the args.
 * @list: List of arguments to be printed.
 * @ind: Index.
 * @buffer: Buffer array to handle print.
 * @flags: Cal working flags.
 * @width: get width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: 1 if chars is printed or 2 if not.
 */

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int j, unknow_lens = 0, prints_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (j = 0; fmt_types[j].fmt != '\0'; j++)
		if (fmt[*ind] == fmt_types[j].fmt)
			return (fmt_types[j].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[j].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_lens += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_lens += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_lens += write(1, &fmt[*ind], 1);
		return (unknow_lens);
	}
	return (prints_chars);
}
