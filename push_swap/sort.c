/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:44:38 by coh               #+#    #+#             */
/*   Updated: 2023/03/06 16:05:13 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_deque *a, t_deque *b, int *pivot)
{
	split_to_b(a, b, pivot);
	if (a->cnt == 2)
		sort_two(a);
	else if (a->cnt == 3)
		sort_three(a);
}

void	sort_five(t_deque *a, t_deque *b, int *arr)
{
	int	min;
	int	idx;

	min = arr[0];
	idx = get_location(a, min, 0);
	use_rot_a(a, idx);
	pb(a, b);
	min = arr[1];
	idx = get_location(a, min, 0);
	use_rot_a(a, idx);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	sort_four(t_deque *a, t_deque *b, int *arr)
{
	int	min;
	int	idx;

	min = arr[0];
	idx = get_location(a, min, 0);
	use_rot_a(a, idx);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_three(t_deque *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->data;
	second = a->top->next->data;
	third = a->bottom->data;
	if (first > second && second < third && third > first)
		sa(a);
	if (first > second && second > third && third < first)
	{
		sa(a);
		rra(a);
	}
	if (first > second && second < third && third < first)
		ra(a);
	if (first < second && second > third && third > first)
	{
		sa(a);
		ra(a);
	}
	if (first < second && second > third && third < first)
		rra(a);
}

void	sort_two(t_deque *a)
{
	if (a->top->data > a->top->next->data)
		sa(a);
}
