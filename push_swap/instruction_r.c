/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:15:42 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 16:20:10 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deque *a)
{
	int	data;

	data = pop_left(a);
	append(a, data);
	print_msg("ra\n");
}

void	rb(t_deque *b)
{
	int	data;

	data = pop_left(b);
	append(b, data);
	print_msg("rb\n");
}

void	rr(t_deque *a, t_deque *b)
{
	int	data;

	data = pop_left(a);
	append(a, data);
	data = pop_left(b);
	append(b, data);
	print_msg("rr\n");
}
