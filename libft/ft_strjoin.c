/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:44:36 by coh               #+#    #+#             */
/*   Updated: 2022/07/11 17:44:36 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	lens1;
	size_t	lens2;
	char	*arr;

	i = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	arr = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!arr)
		return (0);
	ft_strlcpy(arr, s1, lens1 + 1);
	ft_strlcpy(arr + lens1, s2, lens2 + 1);
	return (arr);
}
