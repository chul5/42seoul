/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 02:06:43 by coh               #+#    #+#             */
/*   Updated: 2023/02/26 13:55:18 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct node
{
	struct node	*next;
	struct node	*prev;
	int			data;
}				t_node;

typedef struct deque
{
	t_node	*top;
	t_node	*bottom;
	int		cnt;
}			t_deque;

void	print_emsg(char *msg);
void	print_msg(char *msg);
size_t	ft_strlen(const char *str);
int		is_empty(t_deque *deque);
void	rrr(t_deque *a, t_deque *b);
void	rrb(t_deque *b);
void	rra(t_deque *a);
void	sa(t_deque *a);
void	sb(t_deque *a);
void	ss(t_deque *a, t_deque *b);
void	ra(t_deque *a);
void	rb(t_deque *b);
void	rr(t_deque *a, t_deque *b);
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);
int		pop(t_deque *deque);
void	append_left(t_deque *deque, int data);
int		pop_left(t_deque *deque);
void	append(t_deque *deque, int data);
void	deque_init(t_deque *deque);
void	q_sort(int *arr, int start, int end);
void	swap(int *a, int *b);
int		ft_atoi(const char *str, t_deque *deque);
void	node_clear(t_deque *deque);
int		*parsing(int ac, char **av, t_deque *deque);
void	start_ps_sw(t_deque *a, t_deque *b, int *pivot, int *arr);
void	greedy(t_deque *a, t_deque *b);
int		get_loc_a(t_deque *a, int data);
int		cmp_location(int da, int db, int a_location, int b_location);
int		get_location(t_deque *a, int location, int flag);
int		stack_max(t_node *node);
void	use_rot_a(t_deque *a, int da);
void	sort_ascending(t_deque *a);
void	sort_big(t_deque *a, t_deque *b, int *pivot);
void	sort_three(t_deque *a);
void	sort_five(t_deque *a, t_deque *b, int *arr);
void	sort_four(t_deque *a, t_deque *b, int *arr);
void	sort_two(t_deque *a);
void	split_to_b(t_deque *a, t_deque *b, int *pivot);

#endif