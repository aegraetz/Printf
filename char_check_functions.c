/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_check_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraetz <agraetz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:17:09 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/03/31 12:09:27 by agraetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ifchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ifstr(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ifhexdec(size_t n, char c)
{
	int	count;

	count = numlength(n, 16);
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		count += 2;
		c = 'x';
	}
	if (n >= 16)
	{
		ifhexdec(n / 16, c);
		ifhexdec(n % 16, c);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + 48, 1);
		else if (c == 'x')
			ft_putchar_fd(n + 87, 1);
		else
			ft_putchar_fd(n + 55, 1);
	}
	return (count);
}
