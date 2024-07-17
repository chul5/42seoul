/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:22:56 by coh               #+#    #+#             */
/*   Updated: 2023/03/31 00:17:42 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_info	info;
	t_philo	*philo;

	memset(&info, 0, sizeof(info));
	if (info_init(ac, av, &info))
		return (1);
	if (philo_init(&philo, &info))
	{
		free(info.fork);
		return (1);
	}
	if (philosopher(philo))
		return (print_errmsg(&info, philo));
	return (0);
}
