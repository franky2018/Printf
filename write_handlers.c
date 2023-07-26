#include "main.h"

/**
 * write_pointer - Write address of mem.
 * @buffer: array of characters.
 * @ind: Index which the number begins from in buffer.
 * @length: len of number.
 * @width: width specifier.
 * @flags: flags specifier.
 * @padd: character that represent the padding.
 * @extra_c: character that represent extra character.
 * @padd_start: Index which padding should begin from.
 *
 * Return: written numbers of characters.
 */

int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int a;

	if (width > length)
	{
		for (a = 3; a < width - length + 3; a++)
			buffer[a] = padd;
		buffer[a] = '\0';
		if (flags & F_Minus && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], a - 3));
		}
		else if (!(flags & F_Minus) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], a - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_Minus) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], a - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

/**
 * write_number - Print string.
 * @is_negative: List of args.
 * @ind: Indexing character types.
 * @buffer: Buffer arrays to be printed.
 * @flags:  Cal working flag.
 * @width: get width.
 * @precision: precisions specifier.
 * @size: size specifier.
 *
 * Return: numbers of characters printed.
 */

int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char pad = ' ', extra_char = 0;

	UNUSED(size);

	if ((flags & F_Zero) && !(flags & F_Minus))
		pad = '0';
	if (is_negative)
		extra_chars = '-';
	else if (flags & F_Plus)
		extra_char = '+';
	else if (flags & F_Space)
		extra_char = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		len, pad, extra_char));
}

/**
 * write_unsignd - Write unsigned numbers.
 * @is_negative: Numbers that indicate if the num is negative.
 * @ind: Index which the number begins in buffer.
 * @buffer: arrays of characters.
 * @flags: flags specifier.
 * @width: width specifier.
 * @precision: Precisions specifier.
 * @size: size specifier.
 *
 * Return: written numbers of characters.
 */

int write_unsignd(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1, a = 0;
	char pad = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < len)
		pad = ' ';

	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flags & F_Zero) && !(flags & F_Minus))
		pad = '0';

	if (width > len)
	{
		for (a = 0; a < width - len; a++)
			buffer[a] = pad;

		buffer[a] = '\0';

		if (flags & F_Minus)
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], a));
		}
		else
		{
			return (write(1, &buffer[0], a) + write(1, &buffer[ind], len));
		}
	}

	return (write(1, &buffer[ind], len));
}
/**
 * handle_write_char - Print string.
 * @c: Character types.
 * @buffer: Buffer Arrays to be print.
 * @flags:  Cal working flag.
 * @width: get width.
 * @precision: Precisions specifier.
 * @size: size specifier.
 *
 * Return: Numbers of characters to be  printed.
 */

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_Zero)
		pad = '0';

	buffer[a++] = c;
	buffer[a] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (a = 0; a < width - 1; a++)
			buffer[BUFF_SIZE - a - 2] = pad;

		if (flags & F_Minus)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - a - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - a - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_num - Writes numbers using  bufffer.
 * @ind: Index which number begins on buffer.
 * @buffer: Buffer.
 * @flags: flag.
 * @width: width.
 * @prec: Precisions specifier.
 * @length: length of numbers.
 * @padd: Padding characters.
 * @extra_c: Extra characters.
 *
 * Return: Number of characters to be printed.
 */

int write_num(int ind, char buffer[],
	int flags, int width, int prec, int length, char padd, char extra_c)
{
	int a, pad_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (a = 1; a < width - length + 1; a++)
			buffer[a] = padd;
		buffer[a] = '\0';
		if (flags & F_Minus && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], a - 1));
		}
		else if (!(flags & F_Minus) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], a - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_Minus) && padd == '0')
		{
			if (extra_c)
				buffer[--pad_start] = extra_c;
			return (write(1, &buffer[pad_start], i - pad_start) +
				write(1, &buffer[ind], length - (1 - pad_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}
