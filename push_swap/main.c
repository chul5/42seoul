/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 01:53:48 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 16:00:36 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_deque	a;
	t_deque	b;
	int		*arr;
	int		pivot[2];

	deque_init(&a);
	deque_init(&b);
	arr = parsing(ac, av, &a);
	q_sort(arr, 0, a.cnt - 1);
	start_ps_sw(&a, &b, pivot, arr);
	greedy(&a, &b);
	sort_ascending(&a);
	node_clear(&a);
	free(arr);
	return (0);
}
