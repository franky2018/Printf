#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

	/* Size*/
#define S_Short 1
#define S_Long 2

/**
 * typedef struct fmt fmt_t - Structure operator
 *
 * @fmt: The Format
 * @fm_t: Function associated
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size);


	/* Flags */
#define F_Plus 2
#define F_Space 16
#define F_Minus 1
#define F_Hash 8
#define F_Zero 4

/**
 * struct fmt - Structure operator
 *
 * @fmt: Format
 * @fn: Function associated
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

	/*				Functions				*/
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size);
int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_flags(const char *format, int *i);
int write_num(int ind, char bff[], int flags,
		int width, int precision, int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);
int write_unsignd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);
int handle_write_char(char c, char buffer[], int flags,
		int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_rot13string(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_unsignd(unsigned long int num, int size);
int is_printable(char);
long int convert_size_number(long int num, int size);

#endif
