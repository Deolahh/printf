#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...) {
	va_list args;

	va_start(args, format);
	int chars_written = 0;
	
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			char specifier = *format;
			switch (specifier)
			{
				case 'c':
					chars_written += _putchar('
					break;
				case 's':
					chars_written += printf("%s", va_arg(args, char *));
					break;
				case 'd':
				case 'i':
                    chars_written += printf("%d", va_arg(args, int));
                    break;
                case 'u':
                    chars_written += printf("%u", va_arg(args, unsigned int));
                    break;
                case 'x':
                    chars_written += printf("%x", va_arg(args, unsigned int));
                    break;
                case '%':
                    chars_written += putchar('%');
                    break;
                default:
                    chars_written += putchar('%');
                    chars_written += putchar(specifier);
            }
        } else {
            chars_written += putchar(*format);
        }
        format++;
    }

    va_end(args);
    return chars_written;
}
