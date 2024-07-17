/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:21:47 by coh               #+#    #+#             */
/*   Updated: 2023/03/31 12:33:43 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_num(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (1);
	}
	return (0);
}

static int	check_arg(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 5 || 6 < ac)
		return (1);
	while (av[++i])
	{
		if (is_num(av[i]))
			return (1);
		if (ft_atoi(av[i]) <= 0)
			return (1);
	}
	return (0);
}

int	mutex_init(t_info *info)
{
	int	i;

	i = -1;
	info->fork = malloc(sizeof(pthread_mutex_t) * info->number_of_philosophers);
	if (!info->fork)
		return (1);
	while (++i < info->number_of_philosophers)
	{
		if (pthread_mutex_init(&info->fork[i], 0))
			return (1);
	}
	if (pthread_mutex_init(&info->msg, 0))
		return (1);
	if (pthread_mutex_init(&info->flag, 0))
		return (1);
	if (pthread_mutex_init(&info->mtime, 0))
		return (1);
	if (pthread_mutex_init(&info->eat, 0))
		return (1);
	if (pthread_mutex_init(&info->eat_mflag, 0))
		return (1);
	return (0);
}

int	info_init(int ac, char *av[], t_info *info)
{
	if (check_arg(ac, av))
		return (1);
	info->number_of_philosophers = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->philosopher_must_eat = ft_atoi(av[5]);
	if (mutex_init(info))
		return (1);
	return (0);
}

int	philo_init(t_philo **philo, t_info *info)
{
	int	i;

	i = -1;
	*philo = (t_philo *)malloc(sizeof(t_philo) * info->number_of_philosophers);
	if (!philo)
		return (1);
	while (++i < info->number_of_philosophers)
	{
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % info->number_of_philosophers;
		(*philo)[i].info = info;
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].id = i;
		(*philo)[i].last_eat_time = 0;
	}
	return (0);
}
