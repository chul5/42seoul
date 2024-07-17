/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:22:16 by coh               #+#    #+#             */
/*   Updated: 2023/01/26 18:42:05 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_game(t_data *temp, const char *msg)
{
	mlx_destroy_window(temp->mlx, temp->win);
	write(1, msg, ft_strlen(msg));
	mem_free(temp, temp->hei);
	exit(0);
}

void	rect_err(char *line)
{
	const char	*msg = "Rectangle error!\n";

	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	free(line);
	exit(1);
}

void	char_err(t_data *temp)
{
	const char	*msg = "Char error is occured!\n";

	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	mem_free(temp, temp->hei);
	exit(1);
}

void	print_msg(char *msg)
{
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	exit(1);
}
