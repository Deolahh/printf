#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format, ...);
void handle_char(char c);
void handle_string(const char *s);
void handle_int(int num);
int *custom_binary(unsigned int num, int *size);
static void handle_binary(unsigned int num);
#endif
