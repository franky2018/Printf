#include "main.h"

/**
 * print_unsigned - Print unsigned numbers.
 * @types: List of args.
 * @buffer: Buffer arrays to be handle print.
 * @flags:  Cal working flag.
 * @width: width.
 * @precision: Precisions specifier.
 * @size: size specifier.
 * Return: Number of characters to be printed.
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_unsignd(0, a, buffer, flags, width, precision, size));
}

/**
 * print_octal - Print unsigned number in octal notation.
 * @types: List of args.
 * @buffer: Buffer arrays to handle print.
 * @flags: Cal working flag.
 * @width: width.
 * @precision: Precisions specifier.
 * @size: size specifier.
 * Return: Number of characters to be printed
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_Hash && init_num != 0)
		buffer[a--] = '0';

	a++;

	return (write_unsignd(0, a, buffer, flags, width, precision, size));
}

/**
 * print_hexa_upper - Print unsigned number in upper hexadecimal notation.
 * @types: List of args.
 * @buffer: Buffer arrays to handle print.
 * @flags: Cal working flag.
 * @width: width.
 * @precision: Precisions specifier.
 * @size: size specifier.
 * Return: Number of characters to be printed.
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Print hexadecimal number in lower or upper case.
 * @types: List of args.
 * @map_to: Array of values that maps to the number.
 * @buffer: Buffer arrays to handle print.
 * @flags:  Cal working flag.
 * @flag_ch: Cal working flag.
 * @width: width.
 * @precision: Precisions specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_Hash && init_num != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}

	a++;

	return (write_unsignd(0, a, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Print unsigned number in hexadecimal notation.
 * @types: List of args.
 * @buffer: Buffer arrays to handle print.
 * @flags: Cal working flag.
 * @width: width.
 * @precision: Precisions specifier.
 * @size: size specifier.
 * Return: Number of characters to be printed
 */

int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
