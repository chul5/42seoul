/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:50:55 by coh               #+#    #+#             */
/*   Updated: 2022/07/07 21:25:22 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_overflow(unsigned long long num, int minus)
{
	unsigned long long	a;

	a = 9223372036854775807;
	if (num > a - 1 && minus == -1)
		return (0);
	if (num > a && minus == 1)
		return (-1);
	return (num * minus);
}

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
	return ((int)check_overflow(data, minus));
}
