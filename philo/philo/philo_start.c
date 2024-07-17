/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:04:17 by coh               #+#    #+#             */
/*   Updated: 2023/03/31 10:39:13 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread(void *data)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)data;
	info = philo->info;
	if (philo->id % 2)
		usleep(1000);
	while (!check_flag(info, 0))
	{
		fork_rule(philo, info);
		philo_eat(philo, info);
		pthread_mutex_lock(&info->eat_mflag);
		if (info->eat_flag)
		{
			pthread_mutex_unlock(&info->eat_mflag);
			break ;
		}
		pthread_mutex_unlock(&info->eat_mflag);
		print_philomsg(philo->id, info, "is sleeping", 0);
		waiting_time(info->time_to_sleep);
		print_philomsg(philo->id, info, "is thinking", 0);
		usleep(100);
	}
	return (0);
}

int	check_flag(t_info *info, int flag)
{
	int	temp;

	pthread_mutex_lock(&info->flag);
	if (flag == 0)
	{
		temp = info->end;
		pthread_mutex_unlock(&info->flag);
		return (temp);
	}
	else
		info->end = 1;
	pthread_mutex_unlock(&info->flag);
	return (0);
}

void	check_philosopher_state(t_philo *philo, t_info *info)
{
	int		i;

	while (!check_flag(info, 0))
	{
		i = -1;
		while (++i < info->number_of_philosophers)
		{
			pthread_mutex_lock(&info->eat);
			if (info->philosopher_must_eat && \
			philo[i].eat_cnt == info->philosopher_must_eat)
			{
				ft_eat_flag_write(info);
				pthread_mutex_unlock(&info->eat);
				break ;
			}
			pthread_mutex_unlock(&info->eat);
			if (get_time() - philo_le_read(&philo[i], info) \
			>= (long)info->time_to_die)
				print_philomsg(philo[i].id, info, "died", 1);
		}
		if (ft_eat_flag_read(info))
			break ;
	}
}

int	philosopher(t_philo *philo)
{
	int	i;

	i = -1;
	philo->info->start_time = get_time();
	while (++i < philo->info->number_of_philosophers)
	{
		philo[i].last_eat_time = get_time();
		if (pthread_create(&philo[i].tid, 0, thread, &philo[i]) == -1)
			return (1);
	}
	check_philosopher_state(philo, philo->info);
	i = -1;
	if (philo->info->number_of_philosophers > 1)
		while (++i < philo->info->number_of_philosophers)
			pthread_join(philo[i].tid, 0);
	else
		pthread_detach(philo[0].tid);
	free_data(philo, philo->info);
	return (0);
}
