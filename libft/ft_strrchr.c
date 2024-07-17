/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:36:20 by coh               #+#    #+#             */
/*   Updated: 2022/07/07 21:25:34 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	cc;

	cc = (char)c;
	len = (int)ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == cc)
			return ((char *)&s[len]);
		len--;
	}
	return (0);
}
