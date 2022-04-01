/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraetz <agraetz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:15:48 by agraetz           #+#    #+#             */
/*   Updated: 2022/03/31 12:12:14 by agraetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int	checkchar(const char c, va_list ap, int *i);
int	ifchar(char c);
int	ifhexdec(size_t n, char c);
int	ifint(long long int n);
int	ifstr(va_list ap);
int	ft_printf(const char *format, ...);
int	numlength(size_t n, int base);

#endif
