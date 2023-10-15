#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int chars_printed = 0;
for (int i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
if (format[i] == '\0')
{
break;
}
if (format[i] == 'c')
{
char c = va_arg(args, int);
putchar(c);
chars_printed++;
}
else if (format[i] == 's')
{
char *str = va_arg(args, char *);
while (*str != '\0')
{
putchar(*str);
str++;
chars_printed++;
}
}
else if (format[i] == '%')
{
putchar('%');
chars_printed++;
}
}
else
{
putchar(format[i]);
chars_printed++;
}
}
va_end(args);
return (chars_printed);
}
int main(void)
{
int n = 42;
char c = 'A';
char *str = "Hello, World!";
int chars_printed = _printf("Number: %d, Character: %c, String: %s, Percent: %%\n", n, c, str);
printf("Chars printed: %d\n", chars_printed);
return (0);
}
