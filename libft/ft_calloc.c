/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:31:28 by marvin            #+#    #+#             */
/*   Updated: 2022/07/08 14:31:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	arr = (unsigned char *)malloc(nmemb * size);
	if (!arr)
		return (0);
	i = 0;
	while (i < size * nmemb)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
