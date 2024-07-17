/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:06:40 by coh               #+#    #+#             */
/*   Updated: 2023/01/26 18:42:06 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

void	map_parsing(char *file_name, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	line = "map open start";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			ft_strlcpy(data->array[i], line, data->wid + 1);
			free(line);
		}
		i++;
	}
	close(fd);
}

void	img_put(int i, int j, t_data *g, t_image *ig)
{
	mlx_put_image_to_window(g->mlx, g->win, ig->snow, 64 * j, 64 * i);
	if (g->array[i][j] == '1')
		mlx_put_image_to_window(g->mlx, g->win, ig->tree, 64 * j, 64 * i);
	if (g->array[i][j] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, ig->collection, 64 * j, 64 * i);
	if (g->array[i][j] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, ig->character, 64 * j, 64 * i);
	if (g->array[i][j] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, ig->alinia, 64 * j, 64 * i);
}

void	mlx_put(t_data *g, t_image *ig)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->hei)
	{
		j = 0;
		while (j < g->wid)
		{
			img_put(i, j, g, ig);
			j++;
		}
		i++;
	}
}

void	mem_free(t_data *data, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(data->array[i]);
		i++;
	}
	free(data->array);
}
