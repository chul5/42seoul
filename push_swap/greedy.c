/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:16:52 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 18:56:32 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min(t_deque *a, t_deque *b, int *da, int *db)
{
	int			idx;
	int			data;
	int			a_location;
	int			b_location;
	t_node		*temp;

	idx = 0;
	temp = b->top;
	while (idx < b->cnt)
	{
		data = temp->data;
		a_location = get_loc_a(a, data);
		if (idx > b->cnt / 2)
			b_location = idx - b->cnt;
		else
			b_location = idx;
		if (!idx || cmp_location(*da, *db, a_location, b_location))
		{
			*da = a_location;
			*db = b_location;
		}
		temp = temp->next;
		idx++;
	}
}

static void	use_rrr_rr(t_deque *a, t_deque *b, int *da, int *db)
{
	while (*da && *db && (*da < 0 && *db < 0))
	{
		*da += 1;
		*db += 1;
		rrr(a, b);
	}
	while (*da && *db && (*da > 0 && *db > 0))
	{
		*da -= 1;
		*db -= 1;
		rr(a, b);
	}
}

void	use_rot_a(t_deque *a, int da)
{
	while (da < 0)
	{
		da += 1;
		rra(a);
	}
	while (da > 0)
	{
		da -= 1;
		ra(a);
	}
}

static void	use_rot_b(t_deque *b, int db)
{
	while (db < 0)
	{
		db += 1;
		rrb(b);
	}
	while (db > 0)
	{
		db -= 1;
		rb(b);
	}
}

void	greedy(t_deque *a, t_deque *b)
{
	int	data_a;
	int	data_b;

	while (b->cnt)
	{
		data_a = 0;
		data_b = 0;
		find_min(a, b, &data_a, &data_b);
		use_rrr_rr(a, b, &data_a, &data_b);
		use_rot_a(a, data_a);
		use_rot_b(b, data_b);
		pa(a, b);
	}
}
