/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:57:34 by coh               #+#    #+#             */
/*   Updated: 2023/03/31 05:52:43 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_rule(t_philo *philo, t_info *info)
{
	if (!(philo->id % 2))
		pthread_mutex_lock(&(info->fork[philo->left]));
	else
		pthread_mutex_lock(&(info->fork[philo->right]));
	print_philomsg(philo->id, info, "has taken a fork", 0);
	if (!(philo->id % 2))
		pthread_mutex_lock(&(info->fork[philo->right]));
	else
		pthread_mutex_lock(&(info->fork[philo->left]));
	print_philomsg(philo->id, info, "has taken a fork", 0);
}

void	philo_eat(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->mtime);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&info->mtime);
	print_philomsg(philo->id, info, "is eating", 0);
	pthread_mutex_lock(&info->eat);
	philo->eat_cnt++;
	pthread_mutex_unlock(&info->eat);
	waiting_time(info->time_to_eat);
	pthread_mutex_unlock(&(info->fork[philo->right]));
	pthread_mutex_unlock(&(info->fork[philo->left]));
}
