#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - converter for printf
 * @ph: type char pointer of the specifier
 * @function: function for the conversion specifier
 *
 */

typedef struct format
{
	char *ph;
	int (*function)();
} convert;

#include "main.h"

int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
        int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_exc_string(va_list val);
int _printf(const char *format, ...);
int print_hex(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[],
        int flags, char flag_ch, int width, int precision, int size);
int print_int(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_revs(va_list args);
int print_rot13(va_list args);
int print_string(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int append_hexa_code(char ascii_code, char buffer[], int i);
int is_printable(char c);
int handle_write_char(char c, char buffer[],
        int flags, int width, int precision, int size);

#endif
