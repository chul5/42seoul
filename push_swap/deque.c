/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:29:23 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 15:09:39 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deque_init(t_deque *deque)
{
	deque->cnt = 0;
	deque->top = 0;
	deque->bottom = 0;
}

void	append(t_deque *deque, int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->next = 0;
	node->prev = 0;
	node->data = data;
	if (is_empty(deque))
		deque->top = node;
	else
	{
		node->prev = deque->bottom;
		deque->bottom->next = node;
	}
	deque->bottom = node;
	deque->cnt++;
}

int	pop_left(t_deque *deque)
{
	t_node	*ptr;
	int		data;

	if (is_empty(deque))
		print_emsg("Error\n");
	ptr = deque->top;
	data = ptr->data;
	if (deque->cnt == 1)
	{
		deque->top = 0;
		deque->bottom = 0;
	}
	else
	{
		deque->top = ptr->next;
		deque->top->prev = 0;
	}
	deque->cnt--;
	free(ptr);
	return (data);
}

void	append_left(t_deque *deque, int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->next = 0;
	node->prev = 0;
	node->data = data;
	if (is_empty(deque))
		deque->bottom = node;
	else
	{
		node->next = deque->top;
		deque->top->prev = node;
	}
	deque->top = node;
	deque->cnt++;
}

int	pop(t_deque *deque)
{
	t_node	*ptr;
	int		data;

	if (is_empty(deque))
		print_emsg("Error\n");
	ptr = deque->bottom;
	data = ptr->data;
	if (deque->cnt == 1)
	{
		deque->top = 0;
		deque->bottom = 0;
	}
	else
	{
		deque->bottom = ptr->prev;
		deque->bottom->next = 0;
	}
	deque->cnt--;
	free(ptr);
	return (data);
}
