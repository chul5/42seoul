/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:19:48 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 15:24:00 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_deque *a, t_deque *b)
{
	int	data;

	if (is_empty(b))
		return ;
	data = pop_left(b);
	append_left(a, data);
	print_msg("pa\n");
}

void	pb(t_deque *a, t_deque *b)
{
	int	data;

	if (is_empty(a))
		return ;
	data = pop_left(a);
	append_left(b, data);
	print_msg("pb\n");
}
