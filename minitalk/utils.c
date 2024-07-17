/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:43:39 by coh               #+#    #+#             */
/*   Updated: 2023/02/21 11:38:47 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int					minus;
	int					i;
	unsigned long long	data;

	i = 0;
	minus = 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	data = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{	
		data *= 10;
		data += str[i] - '0';
		i++;
	}
	return ((int)(data * minus));
}

void	print_msg(char *msg)
{
	write(1, msg, ft_strlen(msg));
}

void	print_int_num(long num)
{
	char	c;

	if (num < 0)
	{
		write(1, "-", 1);
		c = '0' + num % 10;
		print_int_num(-(num / 10));
	}
	else
	{
		c = '0' + num % 10;
		if (num / 10 != 0)
			print_int_num(num / 10);
	}
	write(1, &c, 1);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
