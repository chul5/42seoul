/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:53:59 by coh               #+#    #+#             */
/*   Updated: 2023/02/14 17:32:06 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig)
{
	if (sig == SIGUSR1)
		print_msg("signal received well\n");
	exit(0);
}

static void	bin_to_send(int pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else if (bit == 1)
		kill(pid, SIGUSR2);
	usleep(100);
}

static void	ten_to_bin(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		bin_to_send(pid, c >> (7 - bit) & 1);
		bit++;
	}
}

static void	str_to_ten(int pid, char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		ten_to_bin(pid, string[i]);
		i++;
	}
	ten_to_bin(pid, 10);
	ten_to_bin(pid, 0);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	pid = ft_atoi(av[1]);
	if (ac != 3)
	{
		print_msg("usage : ./client [server's pid] \"[string]\"\n");
		exit(1);
	}
	else
	{
		if (pid <= 100 || pid > 99999)
		{
			print_msg("pid error is occured\n");
			exit(1);
		}
		signal(SIGUSR1, handler);
		str_to_ten(pid, av[2]);
	}
	while (1)
		pause();
}
