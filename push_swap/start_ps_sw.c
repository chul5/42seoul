/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ps_sw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:07:10 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 15:23:10 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_to_b(t_deque *a, t_deque *b, int *pivot)
{
	int	a_cnt;

	a_cnt = a->cnt;
	while (a_cnt--)
	{
		if (pivot[1] < a->top->data)
			ra(a);
		else
		{
			pb(a, b);
			if (b->top->data < pivot[0])
				rb(b);
		}
	}
	while (a->cnt > 3)
		pb(a, b);
}

void	start_ps_sw(t_deque *a, t_deque *b, int *pivot, int *arr)
{
	pivot[0] = arr[a->cnt / 3];
	pivot[1] = arr[a->cnt / 3 * 2];
	if (a->cnt == 2)
		sort_two(a);
	else if (a->cnt == 3)
		sort_three(a);
	else if (a->cnt == 4)
		sort_four(a, b, arr);
	else if (a->cnt == 5)
		sort_five(a, b, arr);
	else
		sort_big(a, b, pivot);
}
