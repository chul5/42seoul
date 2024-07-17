/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:11:14 by coh               #+#    #+#             */
/*   Updated: 2022/07/11 17:11:14 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	getlen(int num)
{
	int	length;

	length = 0;
	if (num <= 0)
		length++;
	while (num)
	{
		num /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int			len;
	long long	temp_n;
	char		*arr;

	len = getlen(n);
	temp_n = (long long)n;
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (!arr)
		return (0);
	arr[len--] = '\0';
	arr[0] = '0';
	if (temp_n < 0)
	{
		arr[0] = '-';
		temp_n *= -1;
	}
	while (temp_n)
	{
		arr[len--] = temp_n % 10 + '0';
		temp_n /= 10;
	}
	return (arr);
}
