/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:13:55 by marvin            #+#    #+#             */
/*   Updated: 2022/07/08 16:13:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *src)
{
	char	*nomi;
	int		i;

	i = 0;
	while (src[i])
		i++;
	nomi = (char *)malloc((i + 1) * sizeof(char));
	if (nomi == 0)
		return (0);
	i = 0;
	while (src[i])
	{
		nomi[i] = src[i];
		i++;
	}
	nomi[i] = '\0';
	return (nomi);
}
