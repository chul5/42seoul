/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:13:20 by coh               #+#    #+#             */
/*   Updated: 2023/01/09 16:13:20 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	isempty(t_Queue *queue)
{
	if (queue->count == 0)
		return (1);
	return (0);
}

void	enqueue(t_Queue *queue, int x, int y)
{
	t_Node	*newnode;

	newnode = (t_Node *)malloc(sizeof(t_Node));
	newnode->x = x;
	newnode->y = y;
	newnode->next = 0;
	if (isempty(queue))
	{
		queue->front = newnode;
	}
	else
	{
		queue->rear->next = newnode;
	}
	queue->rear = newnode;
	queue->count++;
}

int	dequeue(t_Queue *queue, int *x, int *y)
{
	t_Node	*ptr;

	if (isempty(queue))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ptr = queue->front;
	*x = ptr->x;
	*y = ptr->y;
	queue->front = ptr->next;
	free(ptr);
	queue->count--;
	return (1);
}

void	bfs(t_data *temp)
{
	t_Queue		queue;
	const int	arr[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	init_queue(&queue);
	enqueue(&queue, temp->row, temp->col);
	temp->array[temp->row][temp->col] = 'x';
	while (!(isempty(&queue)))
	{
		queue.i = 0;
		dequeue(&queue, &queue.dx, &queue.dy);
		while (queue.i < 4)
		{
			queue.x = queue.dx + arr[queue.i][0];
			queue.y = queue.dy + arr[queue.i][1];
			if (is_valid(temp, queue.x, queue.y, &(queue.data)))
			{
				enqueue(&queue, queue.x, queue.y);
				temp->array[queue.x][queue.y] = 'x';
			}
			queue.i++;
		}
	}
	if (queue.data.c != (temp->char_num).c || queue.data.e < 1)
		print_msg("invalid map");
}

int	is_valid(t_data *temp, int dx, int dy, t_char *cnt)
{
	if (dx < 0 || temp->hei <= dx)
		return (0);
	if (dy < 0 || temp->wid <= dy)
		return (0);
	if (temp->array[dx][dy] == '1')
		return (0);
	if (temp->array[dx][dy] == 'x')
		return (0);
	if (temp->array[dx][dy] == 'E')
	{
		cnt->e++;
		temp->array[dx][dy] = 'x';
		return (0);
	}
	if (temp->array[dx][dy] == 'C')
		cnt->c++;
	return (1);
}
