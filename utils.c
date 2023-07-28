#include "main.h"

/**
 * is_printable - Evaluates a character if printable.
 * @c: Character to evaluated.
 *
 * Return: if c is printable return 1, otherwise 0.
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts  number to specified size.
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of number.
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_Long)
		return (num);
	else if (size == S_Short)
		return ((short)num);

	return ((int)num);
}

/**
 * append_hexa_code - Include ascii in hexadecimal code to buffer.
 * @buffer: array of characters.
 * @i: Index which including begins.
 * @ascii_code: Ascii Code.
 * Return: Always 3 (Succuss).
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char maps_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = maps_to[ascii_code / 16];
	buffer[i] = maps_to[ascii_code % 16];

	return (3);
}

/**
 * convert_size_unsgnd - Casts number to the specified size.
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of number.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_Long)
		return (num);
	else if (size == S_Short)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/**
 * is_digit - Verify if a character is a digit.
 * @c: Character to be evaluated
 *
 * Return: if c is a digitreturn 1, otherwise 0.
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
