/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:16:28 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 13:41:31 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_clear(t_deque *deque)
{
	t_node	*node;
	t_node	*temp;

	node = deque->top;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
}
