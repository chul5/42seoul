/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:41:42 by coh               #+#    #+#             */
/*   Updated: 2023/01/27 18:35:38 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapinit(t_data *g, t_image *img)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, 64 * (g->wid), \
	64 * g->hei, "so_long");
	img->alinia = mlx_xpm_file_to_image(g->mlx, "./images/alinia.xpm", \
	&img->img_hei, &img->img_wid);
	img->collection = mlx_xpm_file_to_image(g->mlx, "./images/collection.xpm", \
	&img->img_hei, &img->img_wid);
	img->character = mlx_xpm_file_to_image(g->mlx, "./images/character.xpm", \
	&img->img_hei, &img->img_wid);
	img->snow = mlx_xpm_file_to_image(g->mlx, "./images/snow.xpm", \
	&img->img_hei, &img->img_wid);
	img->tree = mlx_xpm_file_to_image(g->mlx, "./images/tree.xpm", \
	&img->img_hei, &img->img_wid);
	g->img = img;
	mlx_put(g, (t_image *)g->img);
}

void	position_init(t_data *move, int i, int j)
{
	move->row = i;
	move->col = j;
}

void	t_data_init(t_data *temp)
{
	(temp->char_num).c = 0;
	(temp->char_num).p = 0;
	(temp->char_num).e = 0;
	temp->cnt = 0;
	temp->wid = 0;
	temp->hei = 0;
	temp->collection = 0;
}

void	mem_init(t_data *temp)
{
	int	i;

	i = 0;
	temp->array = (char **)malloc(sizeof(char *) * (temp->hei + 1));
	if (!(temp->array))
		print_msg("meminit error");
	temp->array[temp->hei] = 0;
	while (i < temp->hei)
	{
		temp->array[i] = (char *)malloc(sizeof(char) * (temp->wid + 1));
		if (!(temp->array[i]))
			mem_free(temp, i);
		i++;
	}
}

void	init_queue(t_Queue *queue)
{
	queue->front = 0;
	queue->rear = 0;
	queue->count = 0;
	queue->i = 0;
	queue->dx = 0;
	queue->dy = 0;
	(queue->data).c = 0;
	(queue->data).e = 0;
}
