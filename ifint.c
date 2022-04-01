/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numlength.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraetz <agraetz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:05:36 by agraetz           #+#    #+#             */
/*   Updated: 2022/03/31 12:14:40 by agraetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	makechar(size_t n)
{
	if (n > 9)
	{
		makechar(n / 10);
		makechar(n % 10);
	}
	if (n < 10)
	{
		ft_putchar_fd(n + 48, 1);
	}
}

int	numlength(size_t n, int base)
{
	int	len;

	len = 0;
	if (!n)
	{
		return (1);
	}
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	ifint(long long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		count++;
	}
	makechar(n);
	count += numlength(n, 10);
	return (count);
}
