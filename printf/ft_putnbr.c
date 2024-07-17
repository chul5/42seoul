/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:34:12 by coh               #+#    #+#             */
/*   Updated: 2022/08/07 21:52:08 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void	putnum(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

int	ft_putnbr(int n, int *cnt)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		(*cnt)++;
		ft_putnbr(n, cnt);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, cnt);
		ft_putnbr(n % 10, cnt);
	}
	else
	{
		putnum(n);
		(*cnt)++;
	}
	return (*cnt);
}

int ft_putnum(int a, int base)
{
	int cnt = 0;
	char c;
	if (a < 0)
	{
		c = '0' + a % base; 
		write(1, '-', 1);
		cnt += ft_putnum(-(a/base), base);
	}
	else if (a > base)
	{
		c = '0' + a % base;
		if (a / base != 0)
			cnt += ft_putnum(a / base, base);
	}
	write(1, &c ,1);
	return cnt;
	
}