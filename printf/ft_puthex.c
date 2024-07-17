/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:53:16 by coh               #+#    #+#             */
/*   Updated: 2022/08/07 21:51:24 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_puthex(va_list ap, char c)
{
	size_t			len;
	char			*base;
	unsigned int	i;

	base = "0123456789abcdef";
	len = 0;
	i = 0;
	if (c == 'p')
	{
		len = (size_t)va_arg(ap, void *);
		ft_putstr("0x");
		if (!len)
		{
			write(1, "0", 1);
			return (3);
		}
		return (ft_putunbr(len, 16, base, (int *)&i) + 2);
	}
	i = va_arg(ap, int);
	if (c == 'x')
		return (ft_putunbr(i, 16, base, (int *)&len));
	else
		return (ft_putunbr(i, 16, "0123456789ABCDEF", (int *)&len));
}
