/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_press.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:41:16 by coh               #+#    #+#             */
/*   Updated: 2023/01/26 19:06:30 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	press_w(t_data *game)
{
	if (game->array[game->row - 1][game->col] == 'C')
		game->collection++;
	if (game->array[game->row - 1][game->col] == 'E' && \
	game->collection == (game->char_num).c)
	{	
		game->cnt++;
		ft_putnbr_fd(game->cnt, 1);
		write(1, "\n", 1);
		destroy_game(game, "Success!\n");
	}
	else if (game->array[game->row - 1][game->col] == '0' || \
	game->array[game->row - 1][game->col] == 'C')
	{
		game->array[game->row][game->col] = '0';
		game->array[game->row - 1][game->col] = 'P';
		position_init(game, game->row - 1, game->col);
		game->cnt++;
		ft_putnbr_fd(game->cnt, 1);
		write(1, "\n", 1);
		mlx_put(game, (t_image *)game->img);
	}
}

void	press_s(t_data *game)
{
	if (game->array[game->row + 1][game->col] == 'C')
		game->collection++;
	if (game->array[game->row + 1][game->col] == 'E' && \
	game->collection == (game->char_num).c)
	{	
		game->cnt++;
		ft_putnbr_fd(game->cnt, 1);
		write(1, "\n", 1);
		destroy_game(game, "Success!\n");
	}
	else if (game->array[game->row + 1][game->col] == '0' || \
	game->array[game->row + 1][game->col] == 'C')
	{
		game->array[game->row][game->col] = '0';
		game->array[game->row + 1][game->col] = 'P';
		position_init(game, game->row + 1, game->col);
		game->cnt++;
		ft_putnbr_fd(game->cnt, 1);
		write(1, "\n", 1);
		mlx_put(game, (t_image *)game->img);
	}
}

void	press_a(t_data *game)
{
	if (game->array[game->row][game->col - 1] == 'C')
		game->collection++;
	if (game->array[game->row][game->col - 1] == 'E' && \
	game->collection == (game->char_num).c)
	{	
		game->cnt++;
		ft_putnbr_fd(game->cnt, 1);
		write(1, "\n", 1);
		destroy_game(game, "Success!\n");
	}
	else if (game->array[game->row][game->col - 1] == '0' || \
	game->array[game->row][game->col - 1] == 'C')
	{
		game->array[game->row][game->col] = '0';
		game->array[game->row][game->col - 1] = 'P';
		position_init(game, game->row, game->col - 1);
		game->cnt++;
		ft_putnbr_fd(game->cnt, 1);
		write(1, "\n", 1);
		mlx_put(game, (t_image *)game->img);
	}
}

void	press_d(t_data *game)
{
	if (game->array[game->row][game->col + 1] == 'C')
		game->collection++;
	if (game->array[game->row][game->col + 1] == 'E' && \
	game->collection == (game->char_num).c)
	{	
		game->cnt++;
		ft_putnbr_fd(game->cnt, 1);
		write(1, "\n", 1);
		destroy_game(game, "Success!\n");
	}
	else if (game->array[game->row][game->col + 1] == '0' || \
	game->array[game->row][game->col + 1] == 'C')
	{
		game->array[game->row][game->col] = '0';
		game->array[game->row][game->col + 1] = 'P';
		position_init(game, game->row, game->col + 1);
		game->cnt++;
		ft_putnbr_fd(game->cnt, 1);
		write(1, "\n", 1);
		mlx_put(game, (t_image *)game->img);
	}
}
