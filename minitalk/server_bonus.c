/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:56:04 by coh               #+#    #+#             */
/*   Updated: 2023/02/14 17:32:59 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	bin_to_char(int sig, siginfo_t *info, void *context)
{
	static char	temp;
	static int	bit;

	(void)context;
	if (sig == SIGUSR1 && bit < 8)
		temp <<= 1;
	else if (sig == SIGUSR2 && bit < 8)
	{
		temp <<= 1;
		temp |= 1;
	}
	bit++;
	if (bit == 8)
	{
		if (temp != 0)
			write(1, &temp, 1);
		else
			kill(info->si_pid, SIGUSR1);
		bit = 0;
		temp = 0;
	}
}

static void	print_pid(void)
{
	print_msg("server's pid : ");
	print_int_num(getpid());
	print_msg("\n");
}

int	main(int ac, char *av[])
{
	struct sigaction	test;

	(void)av;
	if (ac != 1)
	{
		print_msg("format error is occured\n");
		exit(1);
	}
	print_pid();
	test.sa_flags = SA_SIGINFO;
	test.sa_sigaction = bin_to_char;
	sigemptyset(&test.sa_mask);
	if (sigaction(SIGUSR1, &test, 0) == -1)
	{
		print_msg("error is occured in receiving SIGUSR1\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &test, 0) == -1)
	{
		print_msg("error is occured in receiving SIGUSR2\n");
		exit(1);
	}
	while (1)
		pause();
}
