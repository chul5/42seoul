/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:02:52 by coh               #+#    #+#             */
/*   Updated: 2023/03/31 12:34:11 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philomsg(int id, t_info *info, char *msg, int flag)
{
	pthread_mutex_lock(&(info->msg));
	if (!check_flag(info, 0))
		printf("%lu %d %s\n", get_time() - info->start_time, id + 1, msg);
	if (flag)
		check_flag(info, 1);
	pthread_mutex_unlock(&(info->msg));
}

int	print_errmsg(t_info *info, t_philo *philo)
{
	free_data(philo, info);
	printf("Error\n");
	return (1);
}

void	free_data(t_philo *philo, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->number_of_philosophers)
		pthread_mutex_destroy(&info->fork[i]);
	pthread_mutex_destroy(&info->flag);
	pthread_mutex_destroy(&info->mtime);
	pthread_mutex_destroy(&info->msg);
	pthread_mutex_destroy(&info->eat_mflag);
	pthread_mutex_destroy(&info->eat);
	free(philo);
	free(info->fork);
}

int	ft_atoi(const char *str)
{
	int					minus;
	int					i;
	unsigned long long	data;

	i = 0;
	minus = 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	data = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		data *= 10;
		data += str[i] - '0';
		i++;
	}
	return (data * minus);
}
