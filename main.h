#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void _putchar_char(char c);
void _putchar_str(const char *str);
void _putchar_int(int num);
void _putchar_uint(unsigned int num);
void _putchar_hex(unsigned int num, bool uppercase);
void _putchar_float(double num, int precision);
void _putchar_escape(char c);
int _printf(const char *format, ...);
#endif
