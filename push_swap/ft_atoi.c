/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:32:19 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 15:43:17 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_overflow(unsigned long long num, int minus, t_deque *deque)
{
	if (num >= 2147483648 && minus == 1)
	{
		node_clear(deque);
		print_emsg("Error\n");
	}
	if (num > 2147483648 && minus == -1)
	{
		node_clear(deque);
		print_emsg("Error\n");
	}
	return (num * minus);
}

int	ft_atoi(const char *str, t_deque *deque)
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
	return ((int)check_overflow(data, minus, deque));
}
