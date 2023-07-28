#include "main.h"

/**
 * print_pointer - Print the value of a pointer var.
 * @types: List of args.
 * @buffer: Buffer arrays to handle print.
 * @flags: Cal working flag.
 * @width: width.
 * @precision: Precisions specifier.
 * @size: size specifier.
 * Return: Number of characters to be printed.
 */

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_e = 0, padd = ' ';
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_address;
	char masp_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[index--] = masp_to[num_address % 16];
		num_address /= 16;
		length++;
	}

	if ((flags & F_Zero) && !(flags & F_Minus))
		padd = '0';
	if (flags & F_Plus)
		extra_e = '+', length++;
	else if (flags & F_Space)
		extra_e = ' ', length++;

	index++;

	return (write_pointer(buffer, index, length,
		width, flags, padd, extra_e, padd_start));
}

/**
 * print_non_printable - Print ascii codes in hexadecimal
 *  of non printable characters.
 * @types: List of args.
 * @buffer: Buffer arrays to handle print.
 * @flags: Cal working flag.
 * @width: width.
 * @precision: Precisions specifier.
 * @size: size specifier.
 * Return: Number of characters printed
 */

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = 0, offsets = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[a] != '\0')
	{
		if (is_printable(str[a]))
			buffer[a + offsets] = str[a];
		else
			offsets += append_hexa_code(str[a], buffer, a + offsets);

		a++;
	}

	buffer[a + offsets] = '\0';

	return (write(1, buffer, a + offsets));
}

/**
 * print_reverse - Print reverse string.
 * @types: List of args.
 * @buffer: Buffer arrays to handle print.
 * @flags: Cal working flag.
 * @width: width.
 * @precision: Precisions specifier.
 * @size: size specifier.
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int a, counts = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (a = 0; str[a]; a++)
		;

	for (a = a - 1; a >= 0; a--)
	{
		char g = str[a];

		write(1, &g, 1);
		counts++;
	}
	return (counts);
}

/**
 * print_rot13string - Print string in rot13.
 * @types: List of args.
 * @buffer: Buffer arrays to handle print.
 * @flags: Cal working flag.
 * @width: width.
 * @precision: Precisions specifier.
 * @size: size specifier.
 * Return: Numbers of characters printed
 */

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char d;
	char *str;
	unsigned int m, k;
	int counts = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (m = 0; str[m]; m++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == str[m])
			{
				d = out[k];
				write(1, &d, 1);
				counts++;
				break;
			}
		}
		if (!in[k])
		{
			d = str[m];
			write(1, &d, 1);
			counts++;
		}
	}
	return (counts);
}
