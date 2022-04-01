/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraetz <agraetz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:12:34 by agraetz           #+#    #+#             */
/*   Updated: 2022/03/31 10:43:24 by agraetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkchar(const char c, va_list ap, int *i)
{
	if (c == 'c')
		return (ifchar(va_arg(ap, int)));
	if (c == 's')
		return (ifstr(ap));
	if (c == 'd' || c == 'i')
		return (ifint(va_arg(ap, int)));
	if (c == 'u')
		return (ifint(va_arg(ap, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ifhexdec(va_arg(ap, unsigned int), c));
	if (c == 'p')
		return (ifhexdec(va_arg(ap, unsigned long), c));
	if (c == '%')
		return (ifchar(c));
	if (!c)
		return (0);
	else
		*i -= 1;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		print;
	va_list	ap;

	i = 0;
	print = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[++i])
		{
			print += checkchar(format[i], ap, &i);
			i++;
		}
		if (format[i] && format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			i++;
			print++;
		}
	}
	va_end(ap);
	return (print);
}
