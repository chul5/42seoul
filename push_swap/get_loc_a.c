/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_loc_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 00:27:58 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 19:09:58 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_min(t_node *node)
{
	int	target;

	target = node->data;
	while (node)
	{
		if (target > node->data)
			target = node->data;
		node = node->next;
	}
	return (target);
}

int	stack_max(t_node *node)
{
	int	target;

	target = node->data;
	while (node)
	{
		if (target < node->data)
			target = node->data;
		node = node->next;
	}
	return (target);
}

int	get_location(t_deque *a, int location, int flag)
{
	t_node	*node;
	int		idx;

	node = a->top;
	idx = 0;
	if (flag)
		idx = 1;
	while (node)
	{
		if (location == node->data)
			break ;
		idx++;
		node = node->next;
	}
	if (idx > a->cnt / 2)
		idx -= a->cnt;
	return (idx);
}

static int	get_location_between(t_deque *a, int data)
{
	t_node	*node;
	int		idx;

	idx = 1;
	node = a->top;
	while (node)
	{
		if (!node->prev)
		{
			if (a->bottom->data < data && data < node->data)
			{
				idx = 0;
				break ;
			}
		}
		if (node->data < data && data < node->next->data)
			break ;
		idx++;
		node = node->next;
	}
	if (idx > a->cnt / 2)
		idx -= a->cnt;
	return (idx);
}

int	get_loc_a(t_deque *a, int data)
{
	int	stack_data;

	stack_data = stack_min(a->top);
	if (data < stack_data)
		return (get_location(a, stack_data, 0));
	stack_data = stack_max(a->top);
	if (data > stack_data)
		return (get_location(a, stack_data, 1));
	return (get_location_between(a, data));
}
