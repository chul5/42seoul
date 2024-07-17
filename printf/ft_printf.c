/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:24:50 by coh               #+#    #+#             */
/*   Updated: 2022/08/07 21:55:52 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	funtional_func(char c, va_list ap)
{
	int	temp;

	temp = 0;
	if (c == 'c')
		return (ft_putchar((char)va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int), &temp));
	if (c == 'u')
		return (ft_putunb(ap));
	if (c == 'X' || c == 'x' || c == 'p')
		return (ft_puthex(ap, c));
	if (c == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		cnt;

	va_start(ap, s);
	i = -1;
	cnt = 0;
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1] != 0)
		{
			i++;
			cnt += funtional_func(s[i], ap);
		}
		else
			cnt += ft_putchar(s[i]);
	}
	va_end(ap);
	return (cnt);
}
