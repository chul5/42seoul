/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:48:30 by coh               #+#    #+#             */
/*   Updated: 2023/02/27 20:48:30 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ascending(t_deque *a)
{
	int	stack_data;
	int	cnt;

	cnt = 0;
	stack_data = stack_max(a->top);
	cnt = get_location(a, stack_data, 1);
	use_rot_a(a, cnt);
}
