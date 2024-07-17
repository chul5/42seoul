/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:51:09 by coh               #+#    #+#             */
/*   Updated: 2023/01/28 17:02:38 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int ac, char **av)
{
	t_data	game;
	t_image	img;

	if (ac != 2)
		print_msg("wrong argument!");
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		print_msg("fname_error");
	t_data_init(&game);
	check_rectangle(av[1], &game);
	mem_init(&game);
	map_parsing(av[1], &game);
	check_char_error(&game);
	bfs(&game);
	mem_free(&game, game.hei);
	mem_init(&game);
	map_parsing(av[1], &game);
	mapinit(&game, &img);
	mlx_hook(game.win, KEY_PRESS, 0, &keyhook, &game);
	mlx_hook(game.win, KEY_RED, 0, &mouse_exit, &game);
	mlx_loop(game.mlx);
	mem_free(&game, game.hei);
	return (0);
}
