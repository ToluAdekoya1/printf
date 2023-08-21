#include <stdio.h>
#include "main.h"

/**
 * print_char - character printing
 * @c: param1
 * @count: param2
*/

void print_char(int c, int *count)
{
	putchar(c);
	(*count)++;
}

/**
 * print_string - string printing
 * @s: param1
 * @count: param2
*/

void print_string(const char *s, int *count)
{
	while (*s != '\0')
	{
		putchar(*s);
		s++;
		(*count)++;
	}
}

/**
 * print_integer - prints integer
 * @j: param1
 * @count: param2
*/

void print_integer(int j, int *count)
{
	printf("%d", j);
	(*count)++;
}
/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	int i, c, j;
	char *s;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				print_char(c, &count);
			}
			else if (format[i] == 's')
			{
				s = va_arg(args, char *);
				print_string(s, &count);
			}
			else if (format[i] == 'i' || format[i] == 'd')
			{
				j = va_arg(args, int);
				print_integer(j, &count);
			}
			else if (format[i] == '%')
				print_char('%', &count);
		}
		else
		{
			print_char(format[i], &count);
		}
	}
	va_end(args);
	return (count);
}
