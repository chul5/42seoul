/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:12:51 by coh               #+#    #+#             */
/*   Updated: 2023/01/27 18:41:02 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include "./gnl/get_next_line.h"

# define KEY_PRESS		2
# define KEY_RED		17
# define ESC			53
# define KW				13
# define KA				0
# define KS				1
# define KD				2

typedef struct s_char
{
	int	c;
	int	p;
	int	e;
}	t_char;

typedef struct s_data
{
	void	*win;
	void	*mlx;
	int		hei;
	int		wid;
	int		row;
	int		col;
	int		collection;
	int		cnt;
	char	**array;
	void	*img;
	t_char	char_num;
}			t_data;

typedef struct s_image
{
	void	*snow;
	void	*alinia;
	void	*character;
	void	*tree;
	void	*collection;
	int		img_wid;
	int		img_hei;
}			t_image;

typedef struct Node
{
	int			x;
	int			y;
	struct Node	*next;
}				t_Node;

typedef struct s_Queue
{
	t_Node	*front;
	t_Node	*rear;
	int		count;
	t_char	data;
	int		i;
	int		dx;
	int		dy;
	int		x;
	int		y;
}			t_Queue;

int		is_valid(t_data *temp, int dx, int dy, t_char *cnt);
void	bfs(t_data *temp);
int		dequeue(t_Queue *queue, int *x, int *y);
void	enqueue(t_Queue *queue, int x, int y);
int		isempty(t_Queue *queue);
int		check_char(char c, t_data *data);
void	check_char_error(t_data *data);
int		check_len(char *line);
void	check_rectangle(char *filename, t_data *temp);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		keyhook(int keypress, t_data *game);
int		mouse_exit(t_data *g);
void	init_queue(t_Queue *queue);
void	mem_init(t_data *temp);
void	mapinit(t_data	*game, t_image *img);
void	t_data_init(t_data *temp);
void	position_init(t_data *data, int i, int j);
void	char_err(t_data *temp);
void	rect_err(char *line);
void	print_msg(char *msg);
void	destroy_game(t_data *temp, const char *msg);
void	press_w(t_data *game);
void	press_a(t_data *game);
void	press_s(t_data *game);
void	press_d(t_data *game);
void	mem_free(t_data *data, int idx);
void	map_parsing(char *file_name, t_data *data);
void	mlx_put(t_data *game, t_image *img);
void	ft_putnbr_fd(int n, int fd);
void	img_put(int i, int j, t_data *g, t_image *ig);

#endif