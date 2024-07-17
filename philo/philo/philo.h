/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:24:10 by coh               #+#    #+#             */
/*   Updated: 2023/03/31 12:33:48 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef struct info
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philosopher_must_eat;
	long			start_time;
	int				total_eat;
	int				end;
	int				eat_flag;
	pthread_mutex_t	*fork;
	pthread_mutex_t	msg;
	pthread_mutex_t	flag;
	pthread_mutex_t	mtime;
	pthread_mutex_t	eat;
	pthread_mutex_t	eat_mflag;
}					t_info;

typedef struct philo
{
	pthread_t	tid;
	int			left;
	int			right;
	long		last_eat_time;
	int			eat_cnt;
	int			id;
	t_info		*info;
}				t_philo;

int		info_init(int ac, char *av[], t_info *info);
void	print_philomsg(int id, t_info *info, char *msg, int flag);
long	get_time(void);
int		print_errmsg(t_info *info, t_philo *philo);
void	philo_eat(t_philo *philo, t_info *info);
int		philosopher(t_philo *philo);
int		philo_init(t_philo **philo, t_info *info);
void	free_data(t_philo *philo, t_info *info);
int		ft_atoi(const char *str);
void	waiting_time(long time);
void	check_philosopher_state(t_philo *philo, t_info *info);
void	fork_rule(t_philo *philo, t_info *info);
int		check_flag(t_info *info, int flag);
long	philo_le_read(t_philo *philo, t_info *info);
void	ft_eat_flag_write(t_info *info);
int		ft_eat_flag_read(t_info *info);

#endif