/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:58:08 by coh               #+#    #+#             */
/*   Updated: 2022/07/11 17:58:08 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	head;
	size_t	tail;
	char	*str;

	str = 0;
	head = 0;
	tail = ft_strlen(s1);
	while (s1[head] && ft_strchr(set, s1[head]))
		head++;
	while (ft_strchr(set, s1[tail - 1]) && tail > head)
		tail--;
	str = (char *)malloc(sizeof(char) * (tail - head + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, &s1[head], tail - head + 1);
	return (str);
}
