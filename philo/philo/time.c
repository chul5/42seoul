/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:14:15 by coh               #+#    #+#             */
/*   Updated: 2023/03/31 10:39:22 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	if (-1 == gettimeofday(&time, 0))
		return (0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	waiting_time(long time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}
