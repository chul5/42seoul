/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_location.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 01:44:04 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 13:48:53 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	cmp_location(int da, int db, int a_location, int b_location)
{
	int	temp_a;
	int	temp_b;

	temp_a = ft_abs(da) + ft_abs(db);
	temp_b = ft_abs(a_location) + ft_abs(b_location);
	if (temp_a < temp_b)
		return (0);
	return (1);
}
