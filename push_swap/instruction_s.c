/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:19:22 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 15:44:52 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *a)
{
	t_node	*ptr;

	if (a->cnt <= 1)
		return ;
	ptr = a->top->next;
	swap(&a->top->data, &ptr->data);
	print_msg("sa\n");
}

void	sb(t_deque *b)
{
	t_node	*ptr;

	if (b->cnt <= 1)
		return ;
	ptr = b->top->next;
	swap(&b->top->data, &ptr->data);
	print_msg("sb\n");
}

void	ss(t_deque *a, t_deque *b)
{
	t_node	*ptr;

	if (a->cnt > 1)
	{
		ptr = a->top->next;
		swap(&a->top->data, &ptr->data);
	}
	if (b->cnt > 1)
	{
		ptr = b->top->next;
		swap(&b->top->data, &ptr->data);
	}
	print_msg("ss\n");
}
