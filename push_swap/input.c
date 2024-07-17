/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:12:17 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 13:44:14 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_deque *deque)
{
	t_node	*node;

	node = deque->top;
	while (node)
	{
		if (node->next && (node->data > node->next->data))
			return (0);
		node = node->next;
	}
	node_clear(deque);
	return (1);
}

static int	is_one(int num, t_deque *deque, int *arr)
{
	t_node	*node;

	node = deque->top;
	while (node)
	{
		if (node->data == num)
		{
			node_clear(deque);
			free(arr);
			print_emsg("Error\n");
		}
		node = node->next;
	}
	return (1);
}

static int	is_int(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (!av[i][j])
			return (0);
		if ((av[i][j] == '-' || av[i][j] == '+') && av[i][j + 1])
			j++;
		while (av[i][j])
		{
			if (av[i][j] < '0' || '9' < av[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*parsing(int ac, char **av, t_deque *deque)
{
	int	i;
	int	num;
	int	*arr;

	i = 1;
	if (ac <= 1)
		exit(0);
	if (!is_int(av))
		print_emsg("Error\n");
	arr = (int *)malloc(sizeof(int) * (ac - 1));
	if (!arr)
		print_emsg("Error\n");
	while (i < ac)
	{
		num = ft_atoi(av[i], deque);
		if (is_one(num, deque, arr))
		{
			append(deque, num);
			arr[i - 1] = num;
		}
		i++;
	}
	if (is_sorted(deque))
		exit(0);
	return (arr);
}
