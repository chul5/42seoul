/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:28:21 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 15:43:11 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	q_sort(int *arr, int start, int end)
{
	int	left;
	int	right;
	int	pivot;

	if (start >= end)
		return ;
	pivot = arr[start];
	left = start + 1;
	right = end;
	while (left <= right)
	{
		while (left <= end && pivot >= arr[left])
			left++;
		while (right > start && pivot <= arr[right])
			right--;
		if (left > right)
			swap(&arr[start], &arr[right]);
		else
			swap(&arr[left], &arr[right]);
	}
	q_sort(arr, start, right - 1);
	q_sort(arr, right + 1, end);
}
