/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:51:36 by coh               #+#    #+#             */
/*   Updated: 2022/07/11 14:51:36 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	idx_size;
	size_t	length;

	length = ft_strlen(s);
	if ((size_t)start >= length)
		return (ft_strdup(""));
	if (length - start > len)
		idx_size = len;
	else
		idx_size = length - start;
	arr = (char *)malloc((idx_size + 1) * sizeof(char));
	if (arr == 0)
		return (0);
	ft_strlcpy(arr, s + start, idx_size + 1);
	return (arr);
}
