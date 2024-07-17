/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:18:26 by coh               #+#    #+#             */
/*   Updated: 2022/08/07 17:11:15 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putunbr(size_t n, size_t bn, char *base, int *cnt)
{
	if (n >= bn)
	{
		ft_putunbr(n / bn, bn, base, cnt);
		ft_putunbr(n % bn, bn, base, cnt);
	}
	else
	{
		(*cnt)++;
		write(1, &base[n], 1);
	}
	return (*cnt);
}
