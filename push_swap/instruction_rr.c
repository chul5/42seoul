/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intruction_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:21:53 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 15:29:43 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_deque *a)
{
	int	data;

	data = pop(a);
	append_left(a, data);
	print_msg("rra\n");
}

void	rrb(t_deque *b)
{
	int	data;

	data = pop(b);
	append_left(b, data);
	print_msg("rrb\n");
}

void	rrr(t_deque *a, t_deque *b)
{
	int	data;

	data = pop(a);
	append_left(a, data);
	data = pop(b);
	append_left(b, data);
	print_msg("rrr\n");
}
