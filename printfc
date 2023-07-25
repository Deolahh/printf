#include "main.h"
int _printf(const char *format, ...) {
    va_list args;
    bool is_long;
    bool is_uppercase;
    int width, precision, pad_char, chars_written;

    va_start(args, format);
    chars_written = 0;

    while (*format) {
        if (*format == '%') {
            format++;
            is_long = false;
            is_uppercase = false;
            width = 0;
            precision = -1;
            pad_char = ' ';
            if (*format == '-') {
                
                pad_char = '-';
                format++;
            }

            if (*format == '0') {
                
                pad_char = '0';
                format++;
            }

            
            while (*format >= '0' && *format <= '9') {
                width = width * 10 + (*format - '0');
                format++;
            }

            if (*format == '.') {
                format++; 
                
                precision = 0;
                while (*format >= '0' && *format <= '9') {
                    precision = precision * 10 + (*format - '0');
                    format++;
                }
            }

            if (*format == 'l') {
                is_long = true;
                format++;
            }

            if (*format == 'X') {
                is_uppercase = true;
                format++;
            }

            switch (*format) {
                case 'c': {
                    char c = va_arg(args, int);
                    _putchar_char(c);
                    chars_written++;
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char *);
                    int str_len = strlen(str);
                    int padding = (width > str_len) ? (width - str_len) : 0;

                    if (padding > 0 && pad_char == ' ') {
			    int i;
                        for (i = 0; i < padding; i++) {
                            _putchar_char(pad_char);
                        }
                    }

                    _putchar_str(str);

                    if (padding > 0 && pad_char == '-') {
			    int i;
                        for (i = 0; i < padding; i++) {
                            _putchar_char(pad_char);
                        }
                    }

                    chars_written += str_len;
                    break;
                }
                case 'd':
                case 'i': {
                    int num = is_long ? va_arg(args, long) : va_arg(args, int);
                    char buffer[20];
		    int num_len, padding, i;
                    snprintf(buffer, sizeof(buffer), "%d", num);
                    num_len = strlen(buffer);

                    padding = (width > num_len) ? (width - num_len) : 0;

                    if (padding > 0 && pad_char == ' ') {
                        for (i = 0; i < padding; i++) {
                            _putchar_char(pad_char);
                        }
                    }

                    _putchar_int(num);

                    if (padding > 0 && pad_char == '-') {
			    int i;
                        for (i = 0; i < padding; i++) {
                            _putchar_char(pad_char);
                        }
                    }

                    chars_written += num_len;
                    break;
                }
                case 'u': {
                    unsigned int num = is_long ? va_arg(args, unsigned long) : va_arg(args, unsigned int);
                    _putchar_uint(num);
                    chars_written += (is_long ? sizeof(unsigned long) : sizeof(unsigned int));
                    break;
                }
                case 'x': {
                    unsigned int num = is_long ? va_arg(args, unsigned long) : va_arg(args, unsigned int);
                    _putchar_hex(num, is_uppercase);
                    chars_written += (is_long ? sizeof(unsigned long) : sizeof(unsigned int));
                    break;
                }
                case 'f': {
                    double num = va_arg(args, double);
                    _putchar_float(num, precision);
                    chars_written += 10; 
                    break;
                }
                case '%': {
                    _putchar_char('%');
                    chars_written++;
                    break;
                }
                case 'n': {
                   
                    int *ptr = va_arg(args, int *);
                    *ptr = chars_written;
                    break;
                }
                default:
                    _putchar_escape(*format);
                    chars_written++;
                    break;
            }
        } else if (*format == '\\') {
            
            format++;
            switch (*format) {
                case 'n': {
                    _putchar_char('\n');
                    chars_written++;
                    break;
                }
                case 't': {
                    _putchar_char('\t');
                    chars_written++;
                    break;
                }
                default:
                    _putchar_char(*format);
                    chars_written++;
                    break;
            }
        } else {
            _putchar_char(*format);
            chars_written++;
        }
        format++;
    }

    va_end(args);
    return chars_written;
}

