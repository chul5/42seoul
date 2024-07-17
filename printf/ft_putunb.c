/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:29:44 by coh               #+#    #+#             */
/*   Updated: 2022/08/07 20:57:57 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putunb(va_list ap)
{
	int	i;

	i = 0;
	return (ft_putunbr(va_arg(ap, unsigned int), 10, "0123456789", &i));
}
