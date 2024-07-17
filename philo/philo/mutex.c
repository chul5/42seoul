/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 03:57:56 by coh               #+#    #+#             */
/*   Updated: 2023/03/31 05:51:59 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat_flag_write(t_info *info)
{
	pthread_mutex_lock(&(info->eat_mflag));
	info->eat_flag = 1;
	pthread_mutex_unlock(&info->eat_mflag);
}

int	ft_eat_flag_read(t_info *info)
{
	int	value;

	pthread_mutex_lock(&(info->eat_mflag));
	value = info->eat_flag;
	pthread_mutex_unlock(&info->eat_mflag);
	return (value);
}

long	philo_le_read(t_philo *philo, t_info *info)
{
	long	value;

	pthread_mutex_lock(&info->mtime);
	value = philo->last_eat_time;
	pthread_mutex_unlock(&info->mtime);
	return (value);
}
