/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:36:57 by coh               #+#    #+#             */
/*   Updated: 2023/01/26 18:42:03 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	keyhook(int keypress, t_data *game)
{
	if (keypress == KW)
		press_w(game);
	if (keypress == KS)
		press_s(game);
	if (keypress == KA)
		press_a(game);
	if (keypress == KD)
		press_d(game);
	if (keypress == ESC)
		destroy_game(game, "ESC is pressed!\n");
	return (0);
}

int	mouse_exit(t_data *g)
{
	mlx_destroy_window(g->mlx, g->win);
	write(1, "mouse exit!\n", 12);
	mem_free(g, g->hei);
	exit(0);
}
