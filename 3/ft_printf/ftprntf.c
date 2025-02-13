/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprntf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:26:05 by asafrono          #+#    #+#             */
/*   Updated: 2025/02/13 15:02:14 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

int ft_printf_write(int c, int i)
{
	i++;
	write(1, &c, 1);
	return(i);
}

int ft_s(char *s, int i)
{
	if (!s)
		i = ft_s("(null)", i);
	else
		while (*s)
			i = ft_printf_write(*s++, i);
	return(i);
}

int ft_d(long d, int i)
{
	if (d < 0)
	{
		i = ft_printf_write('-', i);
		i = ft_d(-d, i);
	}
	else if (d < 10)
		i = ft_printf_write(d + '0', i);
	else
	{
		i = ft_d(d / 10, i);
		i = ft_printf_write(d % 10 + '0', i);
	}
	return(i);
}
int ft_x(unsigned int x, int i)
{
	if (x == 0)
		i = ft_printf_write('0', i);
	else if (x > 16)
	{
		i = ft_x(x / 16, i);
		i = ft_x(x % 16, i);
	}
	else
	{
		if (x <= 9)
			i = ft_printf_write(x + '0', i);
		else
			i = ft_printf_write(x + 'a' - 10, i);
	}
	return(i);
}

int ft_printf(const char *format, ... )
{
	va_list args;
	int i;
	int j;

	i = 0;
	j = -1;
	va_start(args, format);
	while (format[++j])
	{
		if (format[j] == '%')
		{
			j++;
			if (format[j] == 's')
				i = ft_s(va_arg(args, char*), i);
			if (format[j] == 'd')
				i = ft_d(va_arg(args, int), i);
			if (format[j] == 'x')
				i = ft_x(va_arg(args, unsigned int), i);
		}
		else
			i = ft_printf_write(format[j], i);
	}
	va_end(args);
	return(0);
}
// int	main(void)
// {
// 	int i;

// 	i = ft_printf("hello 42!\ns: %s, d: %d, x: %x\n", NULL, -2147483648, 42);
// 	printf("i: %i\n\n", i);
// }