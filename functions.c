#include "main.h"


/**
 * print_char - Print characters.
 * @types: List of args
 * @buffer: Buffer array to handle print.
 * @flags:  Cal working flag.
 * @width: width
 * @precision: Precisions specifier.
 * @size: size specifier
 * Return: Number of characters to be printed
 */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char k = va_arg(types, int);

	return (handle_write_char(k, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints strings.
 * @types: List of args.
 * @buffer: Buffer arrays to handle print
 * @flags:  Cal working flag.
 * @width: width.
 * @precision: Precisions specifier.
 * @size: size specifier.
 * Return: Number of characters to be printed.
 */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int lengths = 0, a;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[lengths] != '\0')
		lengths++;
	if (precision >= 0 && precision < lengths)
		lengths = precision;
	if (width > lengths)
	{
		if (flags & F_Minus)
		{
			write(1, &str[0], lengths);
			for (a = width - lengths; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - lengths; a > 0; a--)
				write(1, " ", 1);
			write(1, &str[0], lengths);
			return (width);
		}
	}
	return (write(1, str, lengths));
}

/**
 * print_int - Print integer value.
 * @types: List of args.
 * @buffer: Buffer arrays to handle print.
 * @flags: Cal working flags.
 * @width: width.
 * @precision: Precisions specifier.
 * @size: size specifier.
 * Return: Number of characters to be printed.
 */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	int is_negative = 0;
	long int i = va_arg(types, long int);
	unsigned long int num;

	i = convert_size_number(i, size);

	if (i == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)i;

	if (i < 0)
	{
		num = (unsigned long int)((-1) * i);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[k--] = (num % 10) + '0';
		num /= 10;
	}

	k++;

	return (write_number(is_negative, k, buffer, flags, width, precision, size));
}


/**
 * print_binary - Print unsigned number.
 * @types: List of args.
 * @buffer: Buffer arrays to handle print.
 * @flags:  Cal working flag.
 * @width: width.
 * @precision: Precisions specifier.
 * @size: size specifier
 * Return: Numbers of character printed.
 */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int k, l, j, sum;
	unsigned int i[32];
	int counts;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	k = va_arg(types, unsigned int);
	l = 2147483648;
	i[0] = k / l;

	for (j = 1; j < 32; j++)
	{
		l /= 2;
		i[j] = (k / l) % 2;
	}

	for (j = 0, sum = 0, counts = 0; j < 32; j++)
	{
		sum += i[j];
		if (sum || j == 31)
		{
			char g = '0' + i[j];

			write(1, &g, 1);
			counts++;
		}
	}
	return (counts);
}

/**
 * print_percent - Print percent sign.
 * @types: List of args.
 * @buffer: Buffer arrays to handle print
 * @flags:  Cal working flags.
 * @width: width.
 * @precision: Precision specifier.
 * @size: size specifier.
 * Return: Number of characters to be printed.
 */

int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
